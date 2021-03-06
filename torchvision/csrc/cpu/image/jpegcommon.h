#pragma once

// clang-format off
#include <cstdio>
#include <cstddef>
// clang-format on
#include <jpeglib.h>
#include <setjmp.h>
#include <string>

static const JOCTET EOI_BUFFER[1] = {JPEG_EOI};
struct torch_jpeg_error_mgr {
  struct jpeg_error_mgr pub; /* "public" fields */
  char jpegLastErrorMsg[JMSG_LENGTH_MAX]; /* error messages */
  jmp_buf setjmp_buffer; /* for return to caller */
};

typedef struct torch_jpeg_error_mgr* torch_jpeg_error_ptr;
void torch_jpeg_error_exit(j_common_ptr cinfo);
