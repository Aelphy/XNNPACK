// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <algorithm>
#include <cfloat>
#include <chrono>
#include <cmath>
#include <functional>
#include <limits>
#include <mutex>
#include <random>
#include <vector>

#include <cpuinfo.h>

#include <benchmark/benchmark.h>
#include "bench/gemm.h"
#include "bench/utils.h"
#include <xnnpack/AlignedAllocator.h>
#include <xnnpack/common.h>
#include <xnnpack/gemm.h>
#include <xnnpack/pack.h>
#include <xnnpack/params-init.h>
#include <xnnpack/params.h>


static void GEMMBenchmark(benchmark::State& state,
  xnn_qs8_gemm_ukernel_function gemm,
  size_t mr, size_t nr, size_t kr, size_t sr,
  benchmark::utils::IsaCheckFunction isa_check = nullptr)
{
  if (!cpuinfo_initialize()) {
    state.SkipWithError("cpuinfo initialization failed");
    return;
  }
  if (isa_check && !isa_check(state)) {
    return;
  }

  const size_t mc = state.range(0);
  const size_t nc = state.range(1);
  const size_t kc = state.range(2);

  const size_t nc_stride = benchmark::utils::RoundUp(nc, nr);
  const size_t kc_stride = benchmark::utils::RoundUp(kc, kr);

  std::random_device random_device;
  auto rng = std::mt19937(random_device());
  auto i32rng = std::bind(std::uniform_int_distribution<int32_t>(-10000, 10000), std::ref(rng));
  auto i8rng = std::bind(
    std::uniform_int_distribution<uint32_t>(std::numeric_limits<int8_t>::min(), std::numeric_limits<int8_t>::max()), std::ref(rng));

  std::vector<int8_t> a(mc * kc);
  std::generate(a.begin(), a.end(), std::ref(i8rng));
  std::vector<int8_t> k(nc * kc);
  std::generate(k.begin(), k.end(), std::ref(i8rng));
  std::vector<int32_t> b(nc);
  std::generate(b.begin(), b.end(), std::ref(i32rng));

  const size_t w_size = kc_stride * nc_stride * sizeof(int8_t) + nc_stride * sizeof(int32_t);
  const size_t c_elements = mc * nc;
  const size_t num_buffers = 1 +
    benchmark::utils::DivideRoundUp<size_t>(benchmark::utils::GetMaxCacheSize(), w_size + c_elements * sizeof(int8_t));

  std::vector<char, AlignedAllocator<char, 32>> w(w_size * num_buffers);
  std::fill(w.begin(), w.end(), 0);
  const xnn_qs8_packing_params packing_params = { 127 };
  xnn_pack_qs8_gemm_goi_w(1 /* groups */, nc, kc, nr, kr, sr, k.data(), b.data(), w.data(), &packing_params);
  std::vector<int8_t> c(c_elements * num_buffers);
  std::fill(c.begin(), c.end(), 0xA5);

  union xnn_qs8_gemm_params quantization_params = xnn_init_qs8_gemm_params(0.75f, 127, -127, 126);

  size_t buffer_index = 0;
  for (auto _ : state) {
    // Use circular buffers (exceeding cache size) and prefetch to control cache state:
    // - A is always in L1 cache (if fits, otherwise L2, L3, etc)
    // - W is not in cache (for any cache level)
    // - C is not in cache (for any cache level)
    state.PauseTiming();
    benchmark::utils::PrefetchToL1(a.data(), a.size() * sizeof(int8_t));
    buffer_index = (buffer_index + 1) % num_buffers;
    state.ResumeTiming();

    for (uint32_t m = 0; m < mc; m += mr) {
      const uint32_t mb = min(mc - m, mr);
      for (uint32_t n = 0; n < nc; n += nr) {
        const uint32_t nb = min(nc - n, nr);
        gemm(
          mb, nb, kc * sizeof(int8_t),
          a.data() + m * kc, kc * sizeof(int8_t),
          w.data() + w_size * buffer_index + n * (kc_stride * sizeof(int8_t) + sizeof(int32_t)),
          c.data() + (mc * buffer_index + m) * nc + n, nc * sizeof(int8_t), nr * sizeof(int8_t),
          &quantization_params);
      }
    }
  }

  state.counters["Freq"] = benchmark::utils::GetCurrentCpuFrequency();
  state.counters["OPS"] = benchmark::Counter(
    uint64_t(state.iterations()) * 2 * mc * nc * kc, benchmark::Counter::kIsRate);
}

static void GEMMBenchmark(benchmark::State& state,
  xnn_qs8_gemm_xw_ukernel_function gemm,
  size_t mr, size_t nr, size_t kr, size_t sr,
  benchmark::utils::IsaCheckFunction isa_check = nullptr)
{
  if (!cpuinfo_initialize()) {
    state.SkipWithError("cpuinfo initialization failed");
    return;
  }
  if (isa_check && !isa_check(state)) {
    return;
  }

  const size_t mc = state.range(0);
  const size_t nc = state.range(1);
  const size_t kc = state.range(2);

  const size_t nc_stride = benchmark::utils::RoundUp(nc, nr);
  const size_t kc_stride = benchmark::utils::RoundUp(kc, kr);

  std::random_device random_device;
  auto rng = std::mt19937(random_device());
  auto i32rng = std::bind(std::uniform_int_distribution<int32_t>(-10000, 10000), rng);
  auto i8rng = std::bind(
    std::uniform_int_distribution<uint32_t>(std::numeric_limits<int8_t>::min(), std::numeric_limits<int8_t>::max()), rng);

  std::vector<int8_t> a(mc * kc);
  std::generate(a.begin(), a.end(), std::ref(i8rng));
  std::vector<int8_t> k(nc * kc);
  std::generate(k.begin(), k.end(), std::ref(i8rng));
  std::vector<int32_t> b(nc);
  std::generate(b.begin(), b.end(), std::ref(i32rng));

  const size_t w_size = kc_stride * nc_stride * sizeof(int16_t) + nc_stride * sizeof(int32_t);
  const size_t c_elements = mc * nc;
  const size_t num_buffers = 1 +
    benchmark::utils::DivideRoundUp<size_t>(benchmark::utils::GetMaxCacheSize(), w_size + c_elements * sizeof(int8_t));

  std::vector<char, AlignedAllocator<char, 32>> w(w_size * num_buffers);
  std::fill(w.begin(), w.end(), 0);
  const xnn_qs8_packing_params packing_params = { 127 };
  xnn_pack_qs8_gemm_xw_goi_w(1 /* groups */, nc, kc, nr, kr, sr, k.data(), b.data(), w.data(), &packing_params);
  std::vector<int8_t> c(c_elements * num_buffers);
  std::fill(c.begin(), c.end(), 0xA5);

  union xnn_qs8_gemm_xw_params quantization_params = xnn_init_qs8_gemm_xw_params(0.75f, 127, -127, 126);

  size_t buffer_index = 0;
  for (auto _ : state) {
    // Use circular buffers (exceeding cache size) and prefetch to control cache state:
    // - A is always in L1 cache (if fits, otherwise L2, L3, etc)
    // - W is not in cache (for any cache level)
    // - C is not in cache (for any cache level)
    state.PauseTiming();
    benchmark::utils::PrefetchToL1(a.data(), a.size() * sizeof(int8_t));
    buffer_index = (buffer_index + 1) % num_buffers;
    state.ResumeTiming();

    for (uint32_t m = 0; m < mc; m += mr) {
      const uint32_t mb = min(mc - m, mr);
      for (uint32_t n = 0; n < nc; n += nr) {
        const uint32_t nb = min(nc - n, nr);
        gemm(
          mb, nb, kc * sizeof(int8_t),
          a.data() + m * kc, kc * sizeof(int8_t),
          w.data() + w_size * buffer_index + n * (kc_stride * sizeof(int16_t) + sizeof(int32_t)),
          c.data() + (mc * buffer_index + m) * nc + n, nc * sizeof(int8_t), nr * sizeof(int8_t),
          &quantization_params);
      }
    }
  }

  state.counters["Freq"] = benchmark::utils::GetCurrentCpuFrequency();
  state.counters["OPS"] = benchmark::Counter(
    uint64_t(state.iterations()) * 2 * mc * nc * kc, benchmark::Counter::kIsRate);
}


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  static void qs8_gemm_4x8__neon_mlal_lane(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_4x8__neon_mlal_lane, 4, 8, 1, 1, benchmark::utils::CheckNEON);
  }
  static void qs8_gemm_2x16__neon_mlal_lane(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_2x16__neon_mlal_lane, 2, 16, 1, 1, benchmark::utils::CheckNEON);
  }

  BENCHMARK_GEMM(qs8_gemm_4x8__neon_mlal_lane)
  BENCHMARK_GEMM(qs8_gemm_2x16__neon_mlal_lane)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  static void qs8_gemm_4x4c2__sse2_ld64(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_4x4c2__sse2_ld64, 4, 4, 2, 1);
  }
  static void qs8_gemm_4x4c2__ssse3_ld64(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_4x4c2__ssse3_ld64, 4, 4, 2, 1, benchmark::utils::CheckSSSE3);
  }
  static void qs8_gemm_4x4c2__sse41_ld64(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_4x4c2__sse41_ld64, 4, 4, 2, 1, benchmark::utils::CheckSSE41);
  }
  static void qs8_gemm_4x4c2__xop_ld64(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_4x4c2__xop_ld64, 4, 4, 2, 1, benchmark::utils::CheckXOP);
  }

  static void qs8_gemm_4x4c2__sse2_ld128(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_4x4c2__sse2_ld128, 4, 4, 2, 1);
  }
  static void qs8_gemm_4x4c2__ssse3_ld128(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_4x4c2__ssse3_ld128, 4, 4, 2, 1, benchmark::utils::CheckSSSE3);
  }
  static void qs8_gemm_4x4c2__sse41_ld128(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_4x4c2__sse41_ld128, 4, 4, 2, 1, benchmark::utils::CheckSSE41);
  }
  static void qs8_gemm_4x4c2__xop_ld128(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_4x4c2__xop_ld128, 4, 4, 2, 1, benchmark::utils::CheckXOP);
  }

  static void qs8_gemm_xw_4x4c2__sse2(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_4x4c2__sse2, 4, 4, 2, 1);
  }
  static void qs8_gemm_xw_4x4c2__ssse3(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_4x4c2__ssse3, 4, 4, 2, 1, benchmark::utils::CheckSSSE3);
  }
  static void qs8_gemm_xw_4x4c2__sse41(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_4x4c2__sse41, 4, 4, 2, 1, benchmark::utils::CheckSSE41);
  }
  static void qs8_gemm_xw_4x4c2__xop(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_4x4c2__xop, 4, 4, 2, 1, benchmark::utils::CheckXOP);
  }

  static void qs8_gemm_2x4c8__sse2_ld64(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_2x4c8__sse2_ld64, 2, 4, 8, 1);
  }
  static void qs8_gemm_2x4c8__ssse3_ld64(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_2x4c8__ssse3_ld64, 2, 4, 8, 1, benchmark::utils::CheckSSSE3);
  }
  static void qs8_gemm_2x4c8__sse41_ld64(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_2x4c8__sse41_ld64, 2, 4, 8, 1, benchmark::utils::CheckSSE41);
  }
  static void qs8_gemm_2x4c8__xop_ld64(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_2x4c8__xop_ld64, 2, 4, 8, 1, benchmark::utils::CheckXOP);
  }

  static void qs8_gemm_2x4c8__sse2_ld128(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_2x4c8__sse2_ld128, 2, 4, 8, 1);
  }
  static void qs8_gemm_2x4c8__ssse3_ld128(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_2x4c8__ssse3_ld128, 2, 4, 8, 1, benchmark::utils::CheckSSSE3);
  }
  static void qs8_gemm_2x4c8__sse41_ld128(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_2x4c8__sse41_ld128, 2, 4, 8, 1, benchmark::utils::CheckSSE41);
  }
  static void qs8_gemm_2x4c8__xop_ld128(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_2x4c8__xop_ld128, 2, 4, 8, 1, benchmark::utils::CheckXOP);
  }

  static void qs8_gemm_xw_2x4c8__sse2(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_2x4c8__sse2, 2, 4, 8, 1);
  }
  static void qs8_gemm_xw_2x4c8__ssse3(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_2x4c8__ssse3, 2, 4, 8, 1, benchmark::utils::CheckSSSE3);
  }
  static void qs8_gemm_xw_2x4c8__sse41(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_2x4c8__sse41, 2, 4, 8, 1, benchmark::utils::CheckSSE41);
  }
  static void qs8_gemm_xw_2x4c8__xop(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_2x4c8__xop, 2, 4, 8, 1, benchmark::utils::CheckXOP);
  }

  static void qs8_gemm_3x4c8__sse2_ld64(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_3x4c8__sse2_ld64, 3, 4, 8, 1);
  }
  static void qs8_gemm_3x4c8__ssse3_ld64(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_3x4c8__ssse3_ld64, 3, 4, 8, 1, benchmark::utils::CheckSSSE3);
  }
  static void qs8_gemm_3x4c8__sse41_ld64(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_3x4c8__sse41_ld64, 3, 4, 8, 1, benchmark::utils::CheckSSE41);
  }
  static void qs8_gemm_3x4c8__xop_ld64(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_3x4c8__xop_ld64, 3, 4, 8, 1, benchmark::utils::CheckXOP);
  }

  static void qs8_gemm_3x4c8__sse2_ld128(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_3x4c8__sse2_ld128, 3, 4, 8, 1);
  }
  static void qs8_gemm_3x4c8__ssse3_ld128(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_3x4c8__ssse3_ld128, 3, 4, 8, 1, benchmark::utils::CheckSSSE3);
  }
  static void qs8_gemm_3x4c8__sse41_ld128(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_3x4c8__sse41_ld128, 3, 4, 8, 1, benchmark::utils::CheckSSE41);
  }
  static void qs8_gemm_3x4c8__xop_ld128(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_3x4c8__xop_ld128, 3, 4, 8, 1, benchmark::utils::CheckXOP);
  }

  static void qs8_gemm_xw_3x4c8__sse2(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_3x4c8__sse2, 3, 4, 8, 1);
  }
  static void qs8_gemm_xw_3x4c8__ssse3(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_3x4c8__ssse3, 3, 4, 8, 1, benchmark::utils::CheckSSSE3);
  }
  static void qs8_gemm_xw_3x4c8__sse41(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_3x4c8__sse41, 3, 4, 8, 1, benchmark::utils::CheckSSE41);
  }
  static void qs8_gemm_xw_3x4c8__xop(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_3x4c8__xop, 3, 4, 8, 1, benchmark::utils::CheckXOP);
  }

  static void qs8_gemm_2x8c8__avx2(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_2x8c8__avx2, 2, 8, 8, 1, benchmark::utils::CheckAVX2);
  }
  static void qs8_gemm_3x8c8__avx2(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_3x8c8__avx2, 3, 8, 8, 1, benchmark::utils::CheckAVX2);
  }

  static void qs8_gemm_2x16c8__avx512skx(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_2x16c8__avx512skx, 2, 16, 8, 1, benchmark::utils::CheckAVX512SKX);
  }
  static void qs8_gemm_3x16c8__avx512skx(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_3x16c8__avx512skx, 3, 16, 8, 1, benchmark::utils::CheckAVX512SKX);
  }
  static void qs8_gemm_4x16c8__avx512skx(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_4x16c8__avx512skx, 4, 16, 8, 1, benchmark::utils::CheckAVX512SKX);
  }

  static void qs8_gemm_xw_2x8c8__avx2(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_2x8c8__avx2, 2, 8, 8, 1, benchmark::utils::CheckAVX2);
  }
  static void qs8_gemm_xw_3x8c8__avx2(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_3x8c8__avx2, 3, 8, 8, 1, benchmark::utils::CheckAVX2);
  }

  BENCHMARK_GEMM(qs8_gemm_2x16c8__avx512skx)
  BENCHMARK_GEMM(qs8_gemm_3x16c8__avx512skx)
  BENCHMARK_GEMM(qs8_gemm_4x16c8__avx512skx)

  BENCHMARK_GEMM(qs8_gemm_2x8c8__avx2)
  BENCHMARK_GEMM(qs8_gemm_3x8c8__avx2)
  BENCHMARK_GEMM(qs8_gemm_xw_2x8c8__avx2)
  BENCHMARK_GEMM(qs8_gemm_xw_3x8c8__avx2)

  BENCHMARK_GEMM(qs8_gemm_4x4c2__xop_ld64)
  BENCHMARK_GEMM(qs8_gemm_4x4c2__xop_ld128)
  BENCHMARK_GEMM(qs8_gemm_xw_4x4c2__xop)
  BENCHMARK_GEMM(qs8_gemm_2x4c8__xop_ld64)
  BENCHMARK_GEMM(qs8_gemm_3x4c8__xop_ld64)
  BENCHMARK_GEMM(qs8_gemm_2x4c8__xop_ld128)
  BENCHMARK_GEMM(qs8_gemm_3x4c8__xop_ld128)
  BENCHMARK_GEMM(qs8_gemm_xw_2x4c8__xop)
  BENCHMARK_GEMM(qs8_gemm_xw_3x4c8__xop)

  BENCHMARK_GEMM(qs8_gemm_4x4c2__sse41_ld64)
  BENCHMARK_GEMM(qs8_gemm_4x4c2__sse41_ld128)
  BENCHMARK_GEMM(qs8_gemm_xw_4x4c2__sse41)
  BENCHMARK_GEMM(qs8_gemm_2x4c8__sse41_ld64)
  BENCHMARK_GEMM(qs8_gemm_3x4c8__sse41_ld64)
  BENCHMARK_GEMM(qs8_gemm_2x4c8__sse41_ld128)
  BENCHMARK_GEMM(qs8_gemm_3x4c8__sse41_ld128)
  BENCHMARK_GEMM(qs8_gemm_xw_2x4c8__sse41)
  BENCHMARK_GEMM(qs8_gemm_xw_3x4c8__sse41)

  BENCHMARK_GEMM(qs8_gemm_4x4c2__ssse3_ld64)
  BENCHMARK_GEMM(qs8_gemm_4x4c2__ssse3_ld128)
  BENCHMARK_GEMM(qs8_gemm_xw_4x4c2__ssse3)
  BENCHMARK_GEMM(qs8_gemm_2x4c8__ssse3_ld64)
  BENCHMARK_GEMM(qs8_gemm_3x4c8__ssse3_ld64)
  BENCHMARK_GEMM(qs8_gemm_2x4c8__ssse3_ld128)
  BENCHMARK_GEMM(qs8_gemm_3x4c8__ssse3_ld128)
  BENCHMARK_GEMM(qs8_gemm_xw_2x4c8__ssse3)
  BENCHMARK_GEMM(qs8_gemm_xw_3x4c8__ssse3)

  BENCHMARK_GEMM(qs8_gemm_4x4c2__sse2_ld64)
  BENCHMARK_GEMM(qs8_gemm_4x4c2__sse2_ld128)
  BENCHMARK_GEMM(qs8_gemm_xw_4x4c2__sse2)
  BENCHMARK_GEMM(qs8_gemm_2x4c8__sse2_ld64)
  BENCHMARK_GEMM(qs8_gemm_3x4c8__sse2_ld64)
  BENCHMARK_GEMM(qs8_gemm_2x4c8__sse2_ld128)
  BENCHMARK_GEMM(qs8_gemm_3x4c8__sse2_ld128)
  BENCHMARK_GEMM(qs8_gemm_xw_2x4c8__sse2)
  BENCHMARK_GEMM(qs8_gemm_xw_3x4c8__sse2)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD
  static void qs8_gemm_2x4c8__wasmsimd_ld64(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_2x4c8__wasmsimd_ld64, 2, 4, 8, 1);
  }
  static void qs8_gemm_3x4c8__wasmsimd_ld64(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_3x4c8__wasmsimd_ld64, 3, 4, 8, 1);
  }

  static void qs8_gemm_2x4c8__wasmsimd_ld128(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_2x4c8__wasmsimd_ld128, 2, 4, 8, 1);
  }
  static void qs8_gemm_3x4c8__wasmsimd_ld128(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_minmax_ukernel_3x4c8__wasmsimd_ld128, 3, 4, 8, 1);
  }

  static void qs8_gemm_xw_2x4c8__wasmsimd(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_2x4c8__wasmsimd, 2, 4, 8, 1);
  }
  static void qs8_gemm_xw_3x4c8__wasmsimd(benchmark::State& state, const char* net) {
    GEMMBenchmark(state, xnn_qs8_gemm_xw_minmax_ukernel_3x4c8__wasmsimd, 3, 4, 8, 1);
  }

  BENCHMARK_GEMM(qs8_gemm_2x4c8__wasmsimd_ld64)
  BENCHMARK_GEMM(qs8_gemm_3x4c8__wasmsimd_ld64)
  BENCHMARK_GEMM(qs8_gemm_2x4c8__wasmsimd_ld128)
  BENCHMARK_GEMM(qs8_gemm_3x4c8__wasmsimd_ld128)
  BENCHMARK_GEMM(qs8_gemm_xw_2x4c8__wasmsimd)
  BENCHMARK_GEMM(qs8_gemm_xw_3x4c8__wasmsimd)
#endif  // XNN_ARCH_WASMSIMD

#ifndef XNNPACK_BENCHMARK_NO_MAIN
BENCHMARK_MAIN();
#endif
