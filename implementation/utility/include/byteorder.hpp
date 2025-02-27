// Copyright (C) 2014-2015 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef VSOMEIP_BYTEORDER_HPP
#define VSOMEIP_BYTEORDER_HPP

#if defined(LINUX)
#include <endian.h>
#elif defined(FREEBSD)
#include <sys/endian.h>
#else
// TEST IF THERE COULD BE AN ERROR!
//#error "Undefined OS (only Linux/FreeBSD are currently supported)"
#endif

#if __BYTE_ORDER == __LITTLE_ENDIAN

#define VSOMEIP_BYTES_TO_WORD(x0, x1) ((x0) << 8 | (x1))
#define VSOMEIP_BYTES_TO_LONG(x0, x1, x2, x3) ((x0) << 24 | (x1) << 16 | (x2) << 8 | (x3))

#define VSOMEIP_WORDS_TO_LONG(x0, x1) ((x0) << 16 | (x1))

#define VSOMEIP_WORD_BYTE0(x) ((x) & 0xFF)
#define VSOMEIP_WORD_BYTE1(x) ((x) >> 8)

#define VSOMEIP_LONG_BYTE0(x) ((x) & 0xFF)
#define VSOMEIP_LONG_BYTE1(x) (((x) >> 8) & 0xFF)
#define VSOMEIP_LONG_BYTE2(x) (((x) >> 16) & 0xFF)
#define VSOMEIP_LONG_BYTE3(x) (((x) >> 24) & 0xFF)

#define VSOMEIP_LONG_WORD0(x) ((x) & 0xFFFF)
#define VSOMEIP_LONG_WORD1(x) (((x) >> 16) & 0xFFFF)

#elif __BYTE_ORDER == __BIG_ENDIAN

#define VSOMEIP_BYTES_TO_WORD(x0, x1) ((x1) << 8 | (x0))
#define VSOMEIP_BYTES_TO_LONG(x0, x1, x2, x3) ((x3) << 24 | (x2) << 16 | (x1) << 8 | (x0))

#define VSOMEIP_WORD_BYTE0(x) ((x) >> 8)
#define VSOMEIP_WORD_BYTE1(x) ((x) & 0xFF)

#define VSOMEIP_LONG_BYTE0(x) (((x) >> 24) & 0xFF)
#define VSOMEIP_LONG_BYTE1(x) (((x) >> 16) & 0xFF)
#define VSOMEIP_LONG_BYTE2(x) (((x) >> 8) & 0xFF)
#define VSOMEIP_LONG_BYTE3(x) ((x) & 0xFF)

#define VSOMEIP_LONG_WORD0(x) ((((x) >> 16) & 0xFFFF)
#define VSOMEIP_LONG_WORD1(x) (((x) & 0xFFFF)

#else

#error "__BYTE_ORDER is not defined!"

#endif

#endif // VSOMEIP_BYTEORDER_HPP
