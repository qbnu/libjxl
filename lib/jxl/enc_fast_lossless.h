// Copyright (c) the JPEG XL Project Authors. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef LIB_JXL_ENC_FAST_LOSSLESS_H_
#define LIB_JXL_ENC_FAST_LOSSLESS_H_
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

size_t JxlFastLosslessEncode(const unsigned char* rgba, size_t width,
                             size_t row_stride, size_t height, size_t nb_chans,
                             size_t bitdepth, bool big_endian, int effort,
                             unsigned char** output);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // LIB_JXL_ENC_FAST_LOSSLESS_H_
