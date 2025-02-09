// Copyright (c) the JPEG XL Project Authors. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <stdio.h>
#include <stdlib.h>

#include <tuple>

#include "lib/extras/codec.h"
#include "lib/extras/encode_jpeg.h"
#include "lib/jxl/base/file_io.h"
#include "lib/jxl/codec_in_out.h"

namespace jpegxl {
namespace tools {

int HBDJPEGMain(int argc, const char* argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s input output.jpg [distance]\n", argv[0]);
    return 1;
  }
  fprintf(stderr, "Compressing %s to %s\n", argv[1], argv[2]);
  jxl::CodecInOut io;
  if (!jxl::SetFromFile(argv[1], jxl::extras::ColorHints{}, &io)) {
    fprintf(stderr, "Failed to read image %s.\n", argv[1]);
    return 1;
  }
  jxl::extras::JpegSettings settings;
  settings.xyb = false;
  settings.distance = 1.0f;
  if (argc >= 4) {
    settings.distance = atof(argv[3]);
  }
  std::vector<uint8_t> output;
  JXL_CHECK(jxl::extras::EncodeJpeg(io.Main(), settings, nullptr, &output));
  if (!jxl::WriteFile(output, argv[2])) {
    fprintf(stderr, "Failed to write to \"%s\"\n", argv[2]);
    return 1;
  }
  return 0;
}

}  // namespace tools
}  // namespace jpegxl

int main(int argc, const char** argv) {
  return jpegxl::tools::HBDJPEGMain(argc, argv);
}
