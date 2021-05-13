// Auto-generated file. Do not edit!
//   Template: src/qs8-dwconv/unipass-sse-mul32.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#if defined(__GNUC__) || defined(__clang__)
  #include <x86intrin.h>
#else
  #include <immintrin.h>
  #include <ammintrin.h>
#endif

#include <xnnpack/dwconv.h>
#include <xnnpack/intrinsics-polyfill.h>


void xnn_qs8_dwconv_minmax_ukernel_up24x25__xop_mul32(
    size_t channels,
    size_t output_width,
    const int8_t** input,
    const void* weights,
    int8_t* output,
    size_t input_stride,
    size_t output_increment,
    size_t input_offset,
    const int8_t* zero,
    const union xnn_qs8_gemm_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN
{
  assert(channels != 0);
  assert(output_width != 0);

  do {
    const int8_t* i0 = input[0];
    assert(i0 != NULL);
    if XNN_UNPREDICTABLE(i0 != zero) {
      i0 = (const int8_t*) ((uintptr_t) i0 + input_offset);
    }
    const int8_t* i1 = input[1];
    assert(i1 != NULL);
    if XNN_UNPREDICTABLE(i1 != zero) {
      i1 = (const int8_t*) ((uintptr_t) i1 + input_offset);
    }
    const int8_t* i2 = input[2];
    assert(i2 != NULL);
    if XNN_UNPREDICTABLE(i2 != zero) {
      i2 = (const int8_t*) ((uintptr_t) i2 + input_offset);
    }
    const int8_t* i3 = input[3];
    assert(i3 != NULL);
    if XNN_UNPREDICTABLE(i3 != zero) {
      i3 = (const int8_t*) ((uintptr_t) i3 + input_offset);
    }
    const int8_t* i4 = input[4];
    assert(i4 != NULL);
    if XNN_UNPREDICTABLE(i4 != zero) {
      i4 = (const int8_t*) ((uintptr_t) i4 + input_offset);
    }
    const int8_t* i5 = input[5];
    assert(i5 != NULL);
    if XNN_UNPREDICTABLE(i5 != zero) {
      i5 = (const int8_t*) ((uintptr_t) i5 + input_offset);
    }
    const int8_t* i6 = input[6];
    assert(i6 != NULL);
    if XNN_UNPREDICTABLE(i6 != zero) {
      i6 = (const int8_t*) ((uintptr_t) i6 + input_offset);
    }
    const int8_t* i7 = input[7];
    assert(i7 != NULL);
    if XNN_UNPREDICTABLE(i7 != zero) {
      i7 = (const int8_t*) ((uintptr_t) i7 + input_offset);
    }
    const int8_t* i8 = input[8];
    assert(i8 != NULL);
    if XNN_UNPREDICTABLE(i8 != zero) {
      i8 = (const int8_t*) ((uintptr_t) i8 + input_offset);
    }
    const int8_t* i9 = input[9];
    assert(i9 != NULL);
    if XNN_UNPREDICTABLE(i9 != zero) {
      i9 = (const int8_t*) ((uintptr_t) i9 + input_offset);
    }
    const int8_t* i10 = input[10];
    assert(i10 != NULL);
    if XNN_UNPREDICTABLE(i10 != zero) {
      i10 = (const int8_t*) ((uintptr_t) i10 + input_offset);
    }
    const int8_t* i11 = input[11];
    assert(i11 != NULL);
    if XNN_UNPREDICTABLE(i11 != zero) {
      i11 = (const int8_t*) ((uintptr_t) i11 + input_offset);
    }
    const int8_t* i12 = input[12];
    assert(i12 != NULL);
    if XNN_UNPREDICTABLE(i12 != zero) {
      i12 = (const int8_t*) ((uintptr_t) i12 + input_offset);
    }
    const int8_t* i13 = input[13];
    assert(i13 != NULL);
    if XNN_UNPREDICTABLE(i13 != zero) {
      i13 = (const int8_t*) ((uintptr_t) i13 + input_offset);
    }
    const int8_t* i14 = input[14];
    assert(i14 != NULL);
    if XNN_UNPREDICTABLE(i14 != zero) {
      i14 = (const int8_t*) ((uintptr_t) i14 + input_offset);
    }
    const int8_t* i15 = input[15];
    assert(i15 != NULL);
    if XNN_UNPREDICTABLE(i15 != zero) {
      i15 = (const int8_t*) ((uintptr_t) i15 + input_offset);
    }
    const int8_t* i16 = input[16];
    assert(i16 != NULL);
    if XNN_UNPREDICTABLE(i16 != zero) {
      i16 = (const int8_t*) ((uintptr_t) i16 + input_offset);
    }
    const int8_t* i17 = input[17];
    assert(i17 != NULL);
    if XNN_UNPREDICTABLE(i17 != zero) {
      i17 = (const int8_t*) ((uintptr_t) i17 + input_offset);
    }
    const int8_t* i18 = input[18];
    assert(i18 != NULL);
    if XNN_UNPREDICTABLE(i18 != zero) {
      i18 = (const int8_t*) ((uintptr_t) i18 + input_offset);
    }
    const int8_t* i19 = input[19];
    assert(i19 != NULL);
    if XNN_UNPREDICTABLE(i19 != zero) {
      i19 = (const int8_t*) ((uintptr_t) i19 + input_offset);
    }
    const int8_t* i20 = input[20];
    assert(i20 != NULL);
    if XNN_UNPREDICTABLE(i20 != zero) {
      i20 = (const int8_t*) ((uintptr_t) i20 + input_offset);
    }
    const int8_t* i21 = input[21];
    assert(i21 != NULL);
    if XNN_UNPREDICTABLE(i21 != zero) {
      i21 = (const int8_t*) ((uintptr_t) i21 + input_offset);
    }
    const int8_t* i22 = input[22];
    assert(i22 != NULL);
    if XNN_UNPREDICTABLE(i22 != zero) {
      i22 = (const int8_t*) ((uintptr_t) i22 + input_offset);
    }
    const int8_t* i23 = input[23];
    assert(i23 != NULL);
    if XNN_UNPREDICTABLE(i23 != zero) {
      i23 = (const int8_t*) ((uintptr_t) i23 + input_offset);
    }
    const int8_t* i24 = input[24];
    assert(i24 != NULL);
    if XNN_UNPREDICTABLE(i24 != zero) {
      i24 = (const int8_t*) ((uintptr_t) i24 + input_offset);
    }
    input = (const int8_t**) ((uintptr_t) input + input_stride);

    size_t c = channels;
    const void* w = weights;
    for (; c >= 24; c -= 24) {
      __m128i vacc0123 = _mm_loadu_si128((const __m128i*) w);
      __m128i vacc4567 = _mm_loadu_si128((const __m128i*) ((uintptr_t) w + 4 * sizeof(int32_t)));
      __m128i vacc89AB = _mm_loadu_si128((const __m128i*) ((uintptr_t) w + 8 * sizeof(int32_t)));
      __m128i vaccCDEF = _mm_loadu_si128((const __m128i*) ((uintptr_t) w + 12 * sizeof(int32_t)));
      __m128i vaccGHIJ = _mm_loadu_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t)));
      __m128i vaccKLMN = _mm_loadu_si128((const __m128i*) ((uintptr_t) w + 20 * sizeof(int32_t)));


      const __m128i vi0x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i0));
      const __m128i vk0x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 0 * sizeof(int8_t))));
      const __m128i vi0x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i0 + 4)));
      const __m128i vk0x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 4 * sizeof(int8_t))));
      const __m128i vi0x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i0 + 8)));
      const __m128i vk0x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 8 * sizeof(int8_t))));
      const __m128i vi0xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i0 + 12)));
      const __m128i vk0xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 12 * sizeof(int8_t))));
      const __m128i vi0xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i0 + 16)));
      const __m128i vk0xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 16 * sizeof(int8_t))));
      const __m128i vi0xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i0 + 20)));
      const __m128i vk0xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 20 * sizeof(int8_t))));
      i0 += 24;

      vacc0123 = _mm_macc_epi32(vi0x0123, vk0x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi0x4567, vk0x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi0x89AB, vk0x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi0xCDEF, vk0xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi0xGHIJ, vk0xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi0xKLMN, vk0xKLMN, vaccKLMN);

      const __m128i vi1x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i1));
      const __m128i vk1x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 24 * sizeof(int8_t))));
      const __m128i vi1x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i1 + 4)));
      const __m128i vk1x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 28 * sizeof(int8_t))));
      const __m128i vi1x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i1 + 8)));
      const __m128i vk1x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 32 * sizeof(int8_t))));
      const __m128i vi1xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i1 + 12)));
      const __m128i vk1xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 36 * sizeof(int8_t))));
      const __m128i vi1xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i1 + 16)));
      const __m128i vk1xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 40 * sizeof(int8_t))));
      const __m128i vi1xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i1 + 20)));
      const __m128i vk1xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 44 * sizeof(int8_t))));
      i1 += 24;

      vacc0123 = _mm_macc_epi32(vi1x0123, vk1x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi1x4567, vk1x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi1x89AB, vk1x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi1xCDEF, vk1xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi1xGHIJ, vk1xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi1xKLMN, vk1xKLMN, vaccKLMN);

      const __m128i vi2x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i2));
      const __m128i vk2x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 48 * sizeof(int8_t))));
      const __m128i vi2x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i2 + 4)));
      const __m128i vk2x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 52 * sizeof(int8_t))));
      const __m128i vi2x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i2 + 8)));
      const __m128i vk2x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 56 * sizeof(int8_t))));
      const __m128i vi2xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i2 + 12)));
      const __m128i vk2xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 60 * sizeof(int8_t))));
      const __m128i vi2xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i2 + 16)));
      const __m128i vk2xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 64 * sizeof(int8_t))));
      const __m128i vi2xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i2 + 20)));
      const __m128i vk2xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 68 * sizeof(int8_t))));
      i2 += 24;

      vacc0123 = _mm_macc_epi32(vi2x0123, vk2x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi2x4567, vk2x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi2x89AB, vk2x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi2xCDEF, vk2xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi2xGHIJ, vk2xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi2xKLMN, vk2xKLMN, vaccKLMN);

      const __m128i vi3x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i3));
      const __m128i vk3x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 72 * sizeof(int8_t))));
      const __m128i vi3x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i3 + 4)));
      const __m128i vk3x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 76 * sizeof(int8_t))));
      const __m128i vi3x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i3 + 8)));
      const __m128i vk3x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 80 * sizeof(int8_t))));
      const __m128i vi3xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i3 + 12)));
      const __m128i vk3xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 84 * sizeof(int8_t))));
      const __m128i vi3xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i3 + 16)));
      const __m128i vk3xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 88 * sizeof(int8_t))));
      const __m128i vi3xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i3 + 20)));
      const __m128i vk3xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 92 * sizeof(int8_t))));
      i3 += 24;

      vacc0123 = _mm_macc_epi32(vi3x0123, vk3x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi3x4567, vk3x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi3x89AB, vk3x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi3xCDEF, vk3xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi3xGHIJ, vk3xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi3xKLMN, vk3xKLMN, vaccKLMN);

      const __m128i vi4x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i4));
      const __m128i vk4x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 96 * sizeof(int8_t))));
      const __m128i vi4x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i4 + 4)));
      const __m128i vk4x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 100 * sizeof(int8_t))));
      const __m128i vi4x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i4 + 8)));
      const __m128i vk4x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 104 * sizeof(int8_t))));
      const __m128i vi4xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i4 + 12)));
      const __m128i vk4xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 108 * sizeof(int8_t))));
      const __m128i vi4xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i4 + 16)));
      const __m128i vk4xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 112 * sizeof(int8_t))));
      const __m128i vi4xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i4 + 20)));
      const __m128i vk4xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 116 * sizeof(int8_t))));
      i4 += 24;

      vacc0123 = _mm_macc_epi32(vi4x0123, vk4x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi4x4567, vk4x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi4x89AB, vk4x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi4xCDEF, vk4xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi4xGHIJ, vk4xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi4xKLMN, vk4xKLMN, vaccKLMN);

      const __m128i vi5x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i5));
      const __m128i vk5x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 120 * sizeof(int8_t))));
      const __m128i vi5x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i5 + 4)));
      const __m128i vk5x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 124 * sizeof(int8_t))));
      const __m128i vi5x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i5 + 8)));
      const __m128i vk5x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 128 * sizeof(int8_t))));
      const __m128i vi5xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i5 + 12)));
      const __m128i vk5xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 132 * sizeof(int8_t))));
      const __m128i vi5xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i5 + 16)));
      const __m128i vk5xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 136 * sizeof(int8_t))));
      const __m128i vi5xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i5 + 20)));
      const __m128i vk5xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 140 * sizeof(int8_t))));
      i5 += 24;

      vacc0123 = _mm_macc_epi32(vi5x0123, vk5x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi5x4567, vk5x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi5x89AB, vk5x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi5xCDEF, vk5xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi5xGHIJ, vk5xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi5xKLMN, vk5xKLMN, vaccKLMN);

      const __m128i vi6x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i6));
      const __m128i vk6x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 144 * sizeof(int8_t))));
      const __m128i vi6x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i6 + 4)));
      const __m128i vk6x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 148 * sizeof(int8_t))));
      const __m128i vi6x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i6 + 8)));
      const __m128i vk6x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 152 * sizeof(int8_t))));
      const __m128i vi6xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i6 + 12)));
      const __m128i vk6xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 156 * sizeof(int8_t))));
      const __m128i vi6xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i6 + 16)));
      const __m128i vk6xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 160 * sizeof(int8_t))));
      const __m128i vi6xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i6 + 20)));
      const __m128i vk6xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 164 * sizeof(int8_t))));
      i6 += 24;

      vacc0123 = _mm_macc_epi32(vi6x0123, vk6x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi6x4567, vk6x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi6x89AB, vk6x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi6xCDEF, vk6xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi6xGHIJ, vk6xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi6xKLMN, vk6xKLMN, vaccKLMN);

      const __m128i vi7x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i7));
      const __m128i vk7x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 168 * sizeof(int8_t))));
      const __m128i vi7x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i7 + 4)));
      const __m128i vk7x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 172 * sizeof(int8_t))));
      const __m128i vi7x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i7 + 8)));
      const __m128i vk7x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 176 * sizeof(int8_t))));
      const __m128i vi7xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i7 + 12)));
      const __m128i vk7xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 180 * sizeof(int8_t))));
      const __m128i vi7xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i7 + 16)));
      const __m128i vk7xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 184 * sizeof(int8_t))));
      const __m128i vi7xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i7 + 20)));
      const __m128i vk7xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 188 * sizeof(int8_t))));
      i7 += 24;

      vacc0123 = _mm_macc_epi32(vi7x0123, vk7x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi7x4567, vk7x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi7x89AB, vk7x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi7xCDEF, vk7xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi7xGHIJ, vk7xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi7xKLMN, vk7xKLMN, vaccKLMN);

      const __m128i vi8x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i8));
      const __m128i vk8x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 192 * sizeof(int8_t))));
      const __m128i vi8x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i8 + 4)));
      const __m128i vk8x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 196 * sizeof(int8_t))));
      const __m128i vi8x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i8 + 8)));
      const __m128i vk8x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 200 * sizeof(int8_t))));
      const __m128i vi8xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i8 + 12)));
      const __m128i vk8xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 204 * sizeof(int8_t))));
      const __m128i vi8xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i8 + 16)));
      const __m128i vk8xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 208 * sizeof(int8_t))));
      const __m128i vi8xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i8 + 20)));
      const __m128i vk8xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 212 * sizeof(int8_t))));
      i8 += 24;

      vacc0123 = _mm_macc_epi32(vi8x0123, vk8x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi8x4567, vk8x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi8x89AB, vk8x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi8xCDEF, vk8xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi8xGHIJ, vk8xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi8xKLMN, vk8xKLMN, vaccKLMN);

      const __m128i vi9x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i9));
      const __m128i vk9x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 216 * sizeof(int8_t))));
      const __m128i vi9x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i9 + 4)));
      const __m128i vk9x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 220 * sizeof(int8_t))));
      const __m128i vi9x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i9 + 8)));
      const __m128i vk9x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 224 * sizeof(int8_t))));
      const __m128i vi9xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i9 + 12)));
      const __m128i vk9xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 228 * sizeof(int8_t))));
      const __m128i vi9xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i9 + 16)));
      const __m128i vk9xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 232 * sizeof(int8_t))));
      const __m128i vi9xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i9 + 20)));
      const __m128i vk9xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 236 * sizeof(int8_t))));
      i9 += 24;

      vacc0123 = _mm_macc_epi32(vi9x0123, vk9x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi9x4567, vk9x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi9x89AB, vk9x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi9xCDEF, vk9xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi9xGHIJ, vk9xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi9xKLMN, vk9xKLMN, vaccKLMN);

      const __m128i vi10x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i10));
      const __m128i vk10x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 240 * sizeof(int8_t))));
      const __m128i vi10x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i10 + 4)));
      const __m128i vk10x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 244 * sizeof(int8_t))));
      const __m128i vi10x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i10 + 8)));
      const __m128i vk10x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 248 * sizeof(int8_t))));
      const __m128i vi10xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i10 + 12)));
      const __m128i vk10xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 252 * sizeof(int8_t))));
      const __m128i vi10xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i10 + 16)));
      const __m128i vk10xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 256 * sizeof(int8_t))));
      const __m128i vi10xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i10 + 20)));
      const __m128i vk10xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 260 * sizeof(int8_t))));
      i10 += 24;

      vacc0123 = _mm_macc_epi32(vi10x0123, vk10x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi10x4567, vk10x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi10x89AB, vk10x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi10xCDEF, vk10xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi10xGHIJ, vk10xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi10xKLMN, vk10xKLMN, vaccKLMN);

      const __m128i vi11x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i11));
      const __m128i vk11x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 264 * sizeof(int8_t))));
      const __m128i vi11x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i11 + 4)));
      const __m128i vk11x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 268 * sizeof(int8_t))));
      const __m128i vi11x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i11 + 8)));
      const __m128i vk11x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 272 * sizeof(int8_t))));
      const __m128i vi11xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i11 + 12)));
      const __m128i vk11xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 276 * sizeof(int8_t))));
      const __m128i vi11xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i11 + 16)));
      const __m128i vk11xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 280 * sizeof(int8_t))));
      const __m128i vi11xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i11 + 20)));
      const __m128i vk11xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 284 * sizeof(int8_t))));
      i11 += 24;

      vacc0123 = _mm_macc_epi32(vi11x0123, vk11x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi11x4567, vk11x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi11x89AB, vk11x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi11xCDEF, vk11xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi11xGHIJ, vk11xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi11xKLMN, vk11xKLMN, vaccKLMN);

      const __m128i vi12x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i12));
      const __m128i vk12x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 288 * sizeof(int8_t))));
      const __m128i vi12x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i12 + 4)));
      const __m128i vk12x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 292 * sizeof(int8_t))));
      const __m128i vi12x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i12 + 8)));
      const __m128i vk12x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 296 * sizeof(int8_t))));
      const __m128i vi12xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i12 + 12)));
      const __m128i vk12xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 300 * sizeof(int8_t))));
      const __m128i vi12xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i12 + 16)));
      const __m128i vk12xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 304 * sizeof(int8_t))));
      const __m128i vi12xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i12 + 20)));
      const __m128i vk12xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 308 * sizeof(int8_t))));
      i12 += 24;

      vacc0123 = _mm_macc_epi32(vi12x0123, vk12x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi12x4567, vk12x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi12x89AB, vk12x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi12xCDEF, vk12xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi12xGHIJ, vk12xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi12xKLMN, vk12xKLMN, vaccKLMN);

      const __m128i vi13x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i13));
      const __m128i vk13x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 312 * sizeof(int8_t))));
      const __m128i vi13x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i13 + 4)));
      const __m128i vk13x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 316 * sizeof(int8_t))));
      const __m128i vi13x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i13 + 8)));
      const __m128i vk13x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 320 * sizeof(int8_t))));
      const __m128i vi13xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i13 + 12)));
      const __m128i vk13xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 324 * sizeof(int8_t))));
      const __m128i vi13xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i13 + 16)));
      const __m128i vk13xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 328 * sizeof(int8_t))));
      const __m128i vi13xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i13 + 20)));
      const __m128i vk13xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 332 * sizeof(int8_t))));
      i13 += 24;

      vacc0123 = _mm_macc_epi32(vi13x0123, vk13x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi13x4567, vk13x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi13x89AB, vk13x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi13xCDEF, vk13xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi13xGHIJ, vk13xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi13xKLMN, vk13xKLMN, vaccKLMN);

      const __m128i vi14x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i14));
      const __m128i vk14x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 336 * sizeof(int8_t))));
      const __m128i vi14x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i14 + 4)));
      const __m128i vk14x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 340 * sizeof(int8_t))));
      const __m128i vi14x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i14 + 8)));
      const __m128i vk14x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 344 * sizeof(int8_t))));
      const __m128i vi14xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i14 + 12)));
      const __m128i vk14xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 348 * sizeof(int8_t))));
      const __m128i vi14xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i14 + 16)));
      const __m128i vk14xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 352 * sizeof(int8_t))));
      const __m128i vi14xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i14 + 20)));
      const __m128i vk14xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 356 * sizeof(int8_t))));
      i14 += 24;

      vacc0123 = _mm_macc_epi32(vi14x0123, vk14x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi14x4567, vk14x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi14x89AB, vk14x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi14xCDEF, vk14xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi14xGHIJ, vk14xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi14xKLMN, vk14xKLMN, vaccKLMN);

      const __m128i vi15x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i15));
      const __m128i vk15x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 360 * sizeof(int8_t))));
      const __m128i vi15x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i15 + 4)));
      const __m128i vk15x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 364 * sizeof(int8_t))));
      const __m128i vi15x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i15 + 8)));
      const __m128i vk15x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 368 * sizeof(int8_t))));
      const __m128i vi15xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i15 + 12)));
      const __m128i vk15xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 372 * sizeof(int8_t))));
      const __m128i vi15xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i15 + 16)));
      const __m128i vk15xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 376 * sizeof(int8_t))));
      const __m128i vi15xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i15 + 20)));
      const __m128i vk15xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 380 * sizeof(int8_t))));
      i15 += 24;

      vacc0123 = _mm_macc_epi32(vi15x0123, vk15x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi15x4567, vk15x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi15x89AB, vk15x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi15xCDEF, vk15xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi15xGHIJ, vk15xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi15xKLMN, vk15xKLMN, vaccKLMN);

      const __m128i vi16x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i16));
      const __m128i vk16x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 384 * sizeof(int8_t))));
      const __m128i vi16x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i16 + 4)));
      const __m128i vk16x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 388 * sizeof(int8_t))));
      const __m128i vi16x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i16 + 8)));
      const __m128i vk16x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 392 * sizeof(int8_t))));
      const __m128i vi16xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i16 + 12)));
      const __m128i vk16xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 396 * sizeof(int8_t))));
      const __m128i vi16xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i16 + 16)));
      const __m128i vk16xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 400 * sizeof(int8_t))));
      const __m128i vi16xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i16 + 20)));
      const __m128i vk16xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 404 * sizeof(int8_t))));
      i16 += 24;

      vacc0123 = _mm_macc_epi32(vi16x0123, vk16x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi16x4567, vk16x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi16x89AB, vk16x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi16xCDEF, vk16xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi16xGHIJ, vk16xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi16xKLMN, vk16xKLMN, vaccKLMN);

      const __m128i vi17x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i17));
      const __m128i vk17x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 408 * sizeof(int8_t))));
      const __m128i vi17x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i17 + 4)));
      const __m128i vk17x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 412 * sizeof(int8_t))));
      const __m128i vi17x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i17 + 8)));
      const __m128i vk17x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 416 * sizeof(int8_t))));
      const __m128i vi17xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i17 + 12)));
      const __m128i vk17xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 420 * sizeof(int8_t))));
      const __m128i vi17xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i17 + 16)));
      const __m128i vk17xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 424 * sizeof(int8_t))));
      const __m128i vi17xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i17 + 20)));
      const __m128i vk17xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 428 * sizeof(int8_t))));
      i17 += 24;

      vacc0123 = _mm_macc_epi32(vi17x0123, vk17x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi17x4567, vk17x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi17x89AB, vk17x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi17xCDEF, vk17xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi17xGHIJ, vk17xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi17xKLMN, vk17xKLMN, vaccKLMN);

      const __m128i vi18x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i18));
      const __m128i vk18x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 432 * sizeof(int8_t))));
      const __m128i vi18x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i18 + 4)));
      const __m128i vk18x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 436 * sizeof(int8_t))));
      const __m128i vi18x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i18 + 8)));
      const __m128i vk18x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 440 * sizeof(int8_t))));
      const __m128i vi18xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i18 + 12)));
      const __m128i vk18xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 444 * sizeof(int8_t))));
      const __m128i vi18xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i18 + 16)));
      const __m128i vk18xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 448 * sizeof(int8_t))));
      const __m128i vi18xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i18 + 20)));
      const __m128i vk18xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 452 * sizeof(int8_t))));
      i18 += 24;

      vacc0123 = _mm_macc_epi32(vi18x0123, vk18x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi18x4567, vk18x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi18x89AB, vk18x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi18xCDEF, vk18xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi18xGHIJ, vk18xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi18xKLMN, vk18xKLMN, vaccKLMN);

      const __m128i vi19x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i19));
      const __m128i vk19x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 456 * sizeof(int8_t))));
      const __m128i vi19x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i19 + 4)));
      const __m128i vk19x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 460 * sizeof(int8_t))));
      const __m128i vi19x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i19 + 8)));
      const __m128i vk19x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 464 * sizeof(int8_t))));
      const __m128i vi19xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i19 + 12)));
      const __m128i vk19xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 468 * sizeof(int8_t))));
      const __m128i vi19xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i19 + 16)));
      const __m128i vk19xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 472 * sizeof(int8_t))));
      const __m128i vi19xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i19 + 20)));
      const __m128i vk19xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 476 * sizeof(int8_t))));
      i19 += 24;

      vacc0123 = _mm_macc_epi32(vi19x0123, vk19x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi19x4567, vk19x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi19x89AB, vk19x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi19xCDEF, vk19xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi19xGHIJ, vk19xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi19xKLMN, vk19xKLMN, vaccKLMN);

      const __m128i vi20x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i20));
      const __m128i vk20x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 480 * sizeof(int8_t))));
      const __m128i vi20x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i20 + 4)));
      const __m128i vk20x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 484 * sizeof(int8_t))));
      const __m128i vi20x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i20 + 8)));
      const __m128i vk20x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 488 * sizeof(int8_t))));
      const __m128i vi20xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i20 + 12)));
      const __m128i vk20xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 492 * sizeof(int8_t))));
      const __m128i vi20xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i20 + 16)));
      const __m128i vk20xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 496 * sizeof(int8_t))));
      const __m128i vi20xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i20 + 20)));
      const __m128i vk20xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 500 * sizeof(int8_t))));
      i20 += 24;

      vacc0123 = _mm_macc_epi32(vi20x0123, vk20x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi20x4567, vk20x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi20x89AB, vk20x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi20xCDEF, vk20xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi20xGHIJ, vk20xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi20xKLMN, vk20xKLMN, vaccKLMN);

      const __m128i vi21x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i21));
      const __m128i vk21x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 504 * sizeof(int8_t))));
      const __m128i vi21x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i21 + 4)));
      const __m128i vk21x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 508 * sizeof(int8_t))));
      const __m128i vi21x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i21 + 8)));
      const __m128i vk21x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 512 * sizeof(int8_t))));
      const __m128i vi21xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i21 + 12)));
      const __m128i vk21xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 516 * sizeof(int8_t))));
      const __m128i vi21xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i21 + 16)));
      const __m128i vk21xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 520 * sizeof(int8_t))));
      const __m128i vi21xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i21 + 20)));
      const __m128i vk21xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 524 * sizeof(int8_t))));
      i21 += 24;

      vacc0123 = _mm_macc_epi32(vi21x0123, vk21x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi21x4567, vk21x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi21x89AB, vk21x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi21xCDEF, vk21xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi21xGHIJ, vk21xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi21xKLMN, vk21xKLMN, vaccKLMN);

      const __m128i vi22x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i22));
      const __m128i vk22x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 528 * sizeof(int8_t))));
      const __m128i vi22x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i22 + 4)));
      const __m128i vk22x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 532 * sizeof(int8_t))));
      const __m128i vi22x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i22 + 8)));
      const __m128i vk22x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 536 * sizeof(int8_t))));
      const __m128i vi22xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i22 + 12)));
      const __m128i vk22xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 540 * sizeof(int8_t))));
      const __m128i vi22xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i22 + 16)));
      const __m128i vk22xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 544 * sizeof(int8_t))));
      const __m128i vi22xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i22 + 20)));
      const __m128i vk22xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 548 * sizeof(int8_t))));
      i22 += 24;

      vacc0123 = _mm_macc_epi32(vi22x0123, vk22x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi22x4567, vk22x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi22x89AB, vk22x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi22xCDEF, vk22xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi22xGHIJ, vk22xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi22xKLMN, vk22xKLMN, vaccKLMN);

      const __m128i vi23x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i23));
      const __m128i vk23x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 552 * sizeof(int8_t))));
      const __m128i vi23x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i23 + 4)));
      const __m128i vk23x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 556 * sizeof(int8_t))));
      const __m128i vi23x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i23 + 8)));
      const __m128i vk23x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 560 * sizeof(int8_t))));
      const __m128i vi23xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i23 + 12)));
      const __m128i vk23xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 564 * sizeof(int8_t))));
      const __m128i vi23xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i23 + 16)));
      const __m128i vk23xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 568 * sizeof(int8_t))));
      const __m128i vi23xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i23 + 20)));
      const __m128i vk23xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 572 * sizeof(int8_t))));
      i23 += 24;

      vacc0123 = _mm_macc_epi32(vi23x0123, vk23x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi23x4567, vk23x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi23x89AB, vk23x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi23xCDEF, vk23xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi23xGHIJ, vk23xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi23xKLMN, vk23xKLMN, vaccKLMN);

      const __m128i vi24x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i24));
      const __m128i vk24x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 576 * sizeof(int8_t))));
      const __m128i vi24x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i24 + 4)));
      const __m128i vk24x4567 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 580 * sizeof(int8_t))));
      const __m128i vi24x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i24 + 8)));
      const __m128i vk24x89AB = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 584 * sizeof(int8_t))));
      const __m128i vi24xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i24 + 12)));
      const __m128i vk24xCDEF = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 588 * sizeof(int8_t))));
      const __m128i vi24xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i24 + 16)));
      const __m128i vk24xGHIJ = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 592 * sizeof(int8_t))));
      const __m128i vi24xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (i24 + 20)));
      const __m128i vk24xKLMN = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 596 * sizeof(int8_t))));
      i24 += 24;

      vacc0123 = _mm_macc_epi32(vi24x0123, vk24x0123, vacc0123);
      vacc4567 = _mm_macc_epi32(vi24x4567, vk24x4567, vacc4567);
      vacc89AB = _mm_macc_epi32(vi24x89AB, vk24x89AB, vacc89AB);
      vaccCDEF = _mm_macc_epi32(vi24xCDEF, vk24xCDEF, vaccCDEF);
      vaccGHIJ = _mm_macc_epi32(vi24xGHIJ, vk24xGHIJ, vaccGHIJ);
      vaccKLMN = _mm_macc_epi32(vi24xKLMN, vk24xKLMN, vaccKLMN);

      w = (const void*) ((uintptr_t) w + 24 * sizeof(int32_t) + 600 * sizeof(int8_t));

      const __m128i vmultiplier = _mm_load_si128((const __m128i*) params->sse2.multiplier);
      const __m128i vrounding = _mm_load_si128((const __m128i*) params->sse2.rounding);

      const __m128i vacc13 = _mm_shuffle_epi32(vacc0123, _MM_SHUFFLE(3, 3, 1, 1));
      const __m128i vprod02 = _mm_add_epi64(_mm_mul_epi32(vacc0123, vmultiplier), vrounding);
      const __m128i vprod13 = _mm_add_epi64(_mm_mul_epi32(vacc13, vmultiplier), vrounding);
      const __m128i vacc57 = _mm_shuffle_epi32(vacc4567, _MM_SHUFFLE(3, 3, 1, 1));
      const __m128i vprod46 = _mm_add_epi64(_mm_mul_epi32(vacc4567, vmultiplier), vrounding);
      const __m128i vprod57 = _mm_add_epi64(_mm_mul_epi32(vacc57, vmultiplier), vrounding);
      const __m128i vacc9B = _mm_shuffle_epi32(vacc89AB, _MM_SHUFFLE(3, 3, 1, 1));
      const __m128i vprod8A = _mm_add_epi64(_mm_mul_epi32(vacc89AB, vmultiplier), vrounding);
      const __m128i vprod9B = _mm_add_epi64(_mm_mul_epi32(vacc9B, vmultiplier), vrounding);
      const __m128i vaccDF = _mm_shuffle_epi32(vaccCDEF, _MM_SHUFFLE(3, 3, 1, 1));
      const __m128i vprodCE = _mm_add_epi64(_mm_mul_epi32(vaccCDEF, vmultiplier), vrounding);
      const __m128i vprodDF = _mm_add_epi64(_mm_mul_epi32(vaccDF, vmultiplier), vrounding);
      const __m128i vaccHJ = _mm_shuffle_epi32(vaccGHIJ, _MM_SHUFFLE(3, 3, 1, 1));
      const __m128i vprodGI = _mm_add_epi64(_mm_mul_epi32(vaccGHIJ, vmultiplier), vrounding);
      const __m128i vprodHJ = _mm_add_epi64(_mm_mul_epi32(vaccHJ, vmultiplier), vrounding);
      const __m128i vaccLN = _mm_shuffle_epi32(vaccKLMN, _MM_SHUFFLE(3, 3, 1, 1));
      const __m128i vprodKM = _mm_add_epi64(_mm_mul_epi32(vaccKLMN, vmultiplier), vrounding);
      const __m128i vprodLN = _mm_add_epi64(_mm_mul_epi32(vaccLN, vmultiplier), vrounding);

      const __m128i vq31prod02 = _mm_srli_epi64(vprod02, 31);
      const __m128i vq31prod13 = _mm_add_epi64(vprod13, vprod13);
      const __m128i vq31prod46 = _mm_srli_epi64(vprod46, 31);
      const __m128i vq31prod57 = _mm_add_epi64(vprod57, vprod57);
      const __m128i vq31prod8A = _mm_srli_epi64(vprod8A, 31);
      const __m128i vq31prod9B = _mm_add_epi64(vprod9B, vprod9B);
      const __m128i vq31prodCE = _mm_srli_epi64(vprodCE, 31);
      const __m128i vq31prodDF = _mm_add_epi64(vprodDF, vprodDF);
      const __m128i vq31prodGI = _mm_srli_epi64(vprodGI, 31);
      const __m128i vq31prodHJ = _mm_add_epi64(vprodHJ, vprodHJ);
      const __m128i vq31prodKM = _mm_srli_epi64(vprodKM, 31);
      const __m128i vq31prodLN = _mm_add_epi64(vprodLN, vprodLN);

      const __m128i vq31prod0123 = _mm_blend_epi16(vq31prod02, vq31prod13, 0xCC);
      const __m128i vq31prod4567 = _mm_blend_epi16(vq31prod46, vq31prod57, 0xCC);
      const __m128i vq31prod89AB = _mm_blend_epi16(vq31prod8A, vq31prod9B, 0xCC);
      const __m128i vq31prodCDEF = _mm_blend_epi16(vq31prodCE, vq31prodDF, 0xCC);
      const __m128i vq31prodGHIJ = _mm_blend_epi16(vq31prodGI, vq31prodHJ, 0xCC);
      const __m128i vq31prodKLMN = _mm_blend_epi16(vq31prodKM, vq31prodLN, 0xCC);

      const __m128i vremainder_mask = _mm_load_si128((const __m128i*) params->sse2.remainder_mask);
      const __m128i vrem0123 =
        _mm_add_epi32(_mm_and_si128(vq31prod0123, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod0123));
      const __m128i vrem4567 =
        _mm_add_epi32(_mm_and_si128(vq31prod4567, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod4567));
      const __m128i vrem89AB =
        _mm_add_epi32(_mm_and_si128(vq31prod89AB, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod89AB));
      const __m128i vremCDEF =
        _mm_add_epi32(_mm_and_si128(vq31prodCDEF, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prodCDEF));
      const __m128i vremGHIJ =
        _mm_add_epi32(_mm_and_si128(vq31prodGHIJ, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prodGHIJ));
      const __m128i vremKLMN =
        _mm_add_epi32(_mm_and_si128(vq31prodKLMN, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prodKLMN));

      const __m128i vremainder_threshold = _mm_load_si128((const __m128i*) params->sse2.remainder_threshold);
      const __m128i vshift = _mm_load_si128((const __m128i*) params->sse2.shift);
      vacc0123 =
        _mm_sub_epi32(_mm_sra_epi32(vq31prod0123, vshift), _mm_cmpgt_epi32(vrem0123, vremainder_threshold));
      vacc4567 =
        _mm_sub_epi32(_mm_sra_epi32(vq31prod4567, vshift), _mm_cmpgt_epi32(vrem4567, vremainder_threshold));
      vacc89AB =
        _mm_sub_epi32(_mm_sra_epi32(vq31prod89AB, vshift), _mm_cmpgt_epi32(vrem89AB, vremainder_threshold));
      vaccCDEF =
        _mm_sub_epi32(_mm_sra_epi32(vq31prodCDEF, vshift), _mm_cmpgt_epi32(vremCDEF, vremainder_threshold));
      vaccGHIJ =
        _mm_sub_epi32(_mm_sra_epi32(vq31prodGHIJ, vshift), _mm_cmpgt_epi32(vremGHIJ, vremainder_threshold));
      vaccKLMN =
        _mm_sub_epi32(_mm_sra_epi32(vq31prodKLMN, vshift), _mm_cmpgt_epi32(vremKLMN, vremainder_threshold));

      const __m128i voutput_zero_point = _mm_load_si128((const __m128i*) params->sse2.output_zero_point);
      __m128i vout01234567 = _mm_adds_epi16(_mm_packs_epi32(vacc0123, vacc4567), voutput_zero_point);
      __m128i vout89ABCDEF = _mm_adds_epi16(_mm_packs_epi32(vacc89AB, vaccCDEF), voutput_zero_point);
      __m128i voutGHIJKLMN = _mm_adds_epi16(_mm_packs_epi32(vaccGHIJ, vaccKLMN), voutput_zero_point);

      const __m128i voutput_min = _mm_load_si128((const __m128i*) params->sse2.output_min);
      const __m128i voutput_max = _mm_load_si128((const __m128i*) params->sse2.output_max);
      vout01234567 = _mm_min_epi16(_mm_max_epi16(vout01234567, voutput_min), voutput_max);
      vout89ABCDEF = _mm_min_epi16(_mm_max_epi16(vout89ABCDEF, voutput_min), voutput_max);
      voutGHIJKLMN = _mm_min_epi16(_mm_max_epi16(voutGHIJKLMN, voutput_min), voutput_max);

      __m128i vout0123456789ABCDEF = _mm_packs_epi16(vout01234567, vout89ABCDEF);
      __m128i voutGHIJKLMNGHIJKLMN = _mm_packs_epi16(voutGHIJKLMN, voutGHIJKLMN);

      _mm_storeu_si128((__m128i*) output, vout0123456789ABCDEF);
      _mm_storel_epi64((__m128i*) (output + 16), voutGHIJKLMNGHIJKLMN);
      output += 24;
    }
    if XNN_UNLIKELY(c != 0) {
      const int8_t* k = (const int8_t*) ((uintptr_t) w + 24 * sizeof(int32_t));
      do {
        __m128i vacc0123 = _mm_loadu_si128((const __m128i*) w);


        const __m128i vi0x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i0));
        const __m128i vk0x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(k));
        i0 += 4;

        vacc0123 = _mm_macc_epi32(vi0x0123, vk0x0123, vacc0123);

        const __m128i vi1x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i1));
        const __m128i vk1x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 24)));
        i1 += 4;

        vacc0123 = _mm_macc_epi32(vi1x0123, vk1x0123, vacc0123);

        const __m128i vi2x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i2));
        const __m128i vk2x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 48)));
        i2 += 4;

        vacc0123 = _mm_macc_epi32(vi2x0123, vk2x0123, vacc0123);

        const __m128i vi3x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i3));
        const __m128i vk3x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 72)));
        i3 += 4;

        vacc0123 = _mm_macc_epi32(vi3x0123, vk3x0123, vacc0123);

        const __m128i vi4x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i4));
        const __m128i vk4x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 96)));
        i4 += 4;

        vacc0123 = _mm_macc_epi32(vi4x0123, vk4x0123, vacc0123);

        const __m128i vi5x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i5));
        const __m128i vk5x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 120)));
        i5 += 4;

        vacc0123 = _mm_macc_epi32(vi5x0123, vk5x0123, vacc0123);

        const __m128i vi6x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i6));
        const __m128i vk6x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 144)));
        i6 += 4;

        vacc0123 = _mm_macc_epi32(vi6x0123, vk6x0123, vacc0123);

        const __m128i vi7x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i7));
        const __m128i vk7x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 168)));
        i7 += 4;

        vacc0123 = _mm_macc_epi32(vi7x0123, vk7x0123, vacc0123);

        const __m128i vi8x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i8));
        const __m128i vk8x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 192)));
        i8 += 4;

        vacc0123 = _mm_macc_epi32(vi8x0123, vk8x0123, vacc0123);

        const __m128i vi9x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i9));
        const __m128i vk9x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 216)));
        i9 += 4;

        vacc0123 = _mm_macc_epi32(vi9x0123, vk9x0123, vacc0123);

        const __m128i vi10x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i10));
        const __m128i vk10x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 240)));
        i10 += 4;

        vacc0123 = _mm_macc_epi32(vi10x0123, vk10x0123, vacc0123);

        const __m128i vi11x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i11));
        const __m128i vk11x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 264)));
        i11 += 4;

        vacc0123 = _mm_macc_epi32(vi11x0123, vk11x0123, vacc0123);

        const __m128i vi12x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i12));
        const __m128i vk12x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 288)));
        i12 += 4;

        vacc0123 = _mm_macc_epi32(vi12x0123, vk12x0123, vacc0123);

        const __m128i vi13x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i13));
        const __m128i vk13x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 312)));
        i13 += 4;

        vacc0123 = _mm_macc_epi32(vi13x0123, vk13x0123, vacc0123);

        const __m128i vi14x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i14));
        const __m128i vk14x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 336)));
        i14 += 4;

        vacc0123 = _mm_macc_epi32(vi14x0123, vk14x0123, vacc0123);

        const __m128i vi15x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i15));
        const __m128i vk15x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 360)));
        i15 += 4;

        vacc0123 = _mm_macc_epi32(vi15x0123, vk15x0123, vacc0123);

        const __m128i vi16x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i16));
        const __m128i vk16x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 384)));
        i16 += 4;

        vacc0123 = _mm_macc_epi32(vi16x0123, vk16x0123, vacc0123);

        const __m128i vi17x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i17));
        const __m128i vk17x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 408)));
        i17 += 4;

        vacc0123 = _mm_macc_epi32(vi17x0123, vk17x0123, vacc0123);

        const __m128i vi18x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i18));
        const __m128i vk18x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 432)));
        i18 += 4;

        vacc0123 = _mm_macc_epi32(vi18x0123, vk18x0123, vacc0123);

        const __m128i vi19x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i19));
        const __m128i vk19x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 456)));
        i19 += 4;

        vacc0123 = _mm_macc_epi32(vi19x0123, vk19x0123, vacc0123);

        const __m128i vi20x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i20));
        const __m128i vk20x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 480)));
        i20 += 4;

        vacc0123 = _mm_macc_epi32(vi20x0123, vk20x0123, vacc0123);

        const __m128i vi21x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i21));
        const __m128i vk21x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 504)));
        i21 += 4;

        vacc0123 = _mm_macc_epi32(vi21x0123, vk21x0123, vacc0123);

        const __m128i vi22x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i22));
        const __m128i vk22x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 528)));
        i22 += 4;

        vacc0123 = _mm_macc_epi32(vi22x0123, vk22x0123, vacc0123);

        const __m128i vi23x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i23));
        const __m128i vk23x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 552)));
        i23 += 4;

        vacc0123 = _mm_macc_epi32(vi23x0123, vk23x0123, vacc0123);

        const __m128i vi24x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32(i24));
        const __m128i vk24x0123 = _mm_cvtepi8_epi32(_mm_loadu_si32((const void*) (k + 576)));
        i24 += 4;

        vacc0123 = _mm_macc_epi32(vi24x0123, vk24x0123, vacc0123);

        w = (const void*) ((uintptr_t) w + 4 * sizeof(int32_t));
        k += 4;

        const __m128i vmultiplier = _mm_load_si128((const __m128i*) params->sse2.multiplier);
        const __m128i vrounding = _mm_load_si128((const __m128i*) params->sse2.rounding);

        const __m128i vacc13 = _mm_shuffle_epi32(vacc0123, _MM_SHUFFLE(3, 3, 1, 1));

        const __m128i vprod02 = _mm_add_epi64(_mm_mul_epi32(vacc0123, vmultiplier), vrounding);
        const __m128i vprod13 = _mm_add_epi64(_mm_mul_epi32(vacc13, vmultiplier), vrounding);

        const __m128i vq31prod02 = _mm_srli_epi64(vprod02, 31);
        const __m128i vq31prod13 = _mm_add_epi64(vprod13, vprod13);

        const __m128i vq31prod0123 = _mm_blend_epi16(vq31prod02, vq31prod13, 0xCC);

        const __m128i vremainder_mask = _mm_load_si128((const __m128i*) params->sse2.remainder_mask);
        const __m128i vrem0123 =
          _mm_add_epi32(_mm_and_si128(vq31prod0123, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod0123));

        const __m128i vremainder_threshold = _mm_load_si128((const __m128i*) params->sse2.remainder_threshold);
        const __m128i vshift = _mm_load_si128((const __m128i*) params->sse2.shift);
        vacc0123 =
          _mm_sub_epi32(_mm_sra_epi32(vq31prod0123, vshift), _mm_cmpgt_epi32(vrem0123, vremainder_threshold));

        const __m128i voutput_zero_point = _mm_load_si128((const __m128i*) params->sse2.output_zero_point);
        __m128i vout0123 = _mm_adds_epi16(_mm_packs_epi32(vacc0123, vacc0123), voutput_zero_point);

        const __m128i voutput_min = _mm_load_si128((const __m128i*) params->sse2.output_min);
        const __m128i voutput_max = _mm_load_si128((const __m128i*) params->sse2.output_max);
        vout0123 = _mm_min_epi16(_mm_max_epi16(vout0123, voutput_min), voutput_max);

        vout0123 = _mm_packs_epi16(vout0123, vout0123);

        if XNN_LIKELY(c >= 4) {
          _mm_storeu_si32(output, vout0123);
          output += 4;
          c -= 4;
        } else {
          if (c & 2) {
            *((uint16_t*) output) = (uint16_t) _mm_extract_epi16(vout0123, 0);
            vout0123 = _mm_srli_epi32(vout0123, 16);
            output += 2;
          }
          if (c & 1) {
            *output = (int8_t) _mm_extract_epi8(vout0123, 0);
            output += 1;
          }
          c = 0;
        }
      } while (c != 0);
    }

    output = (int8_t*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}
