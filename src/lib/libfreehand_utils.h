/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libfreehand project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef __LIBFREEHAND_UTILS_H__
#define __LIBFREEHAND_UTILS_H__

#include <vector>
#include <stdio.h>
#include <string>
#include <math.h>
#include <librevenge/librevenge.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define FH_EPSILON 1E-6
#define FH_ALMOST_ZERO(m) (fabs(m) <= FH_EPSILON)

#ifdef _MSC_VER

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned uint32_t;
typedef unsigned __int64 uint64_t;
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef __int64 int64_t;

#else

#ifdef HAVE_CONFIG_H

#include <config.h>

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif

#else

// assume that the headers are there inside LibreOffice build when no HAVE_CONFIG_H is defined
#include <stdint.h>
#include <inttypes.h>

#endif

#endif

// debug message includes source file and line number
//#define VERBOSE_DEBUG 1

// do nothing with debug messages in a release compile
#ifdef DEBUG
#ifdef VERBOSE_DEBUG
#define FH_DEBUG_MSG(M) printf("%15s:%5d: ", __FILE__, __LINE__); printf M
#define FH_DEBUG(M) M
#else
#define FH_DEBUG_MSG(M) printf M
#define FH_DEBUG(M) M
#endif
#else
#define FH_DEBUG_MSG(M)
#define FH_DEBUG(M)
#endif

namespace libfreehand
{

uint8_t readU8(librevenge::RVNGInputStream *input);
uint16_t readU16(librevenge::RVNGInputStream *input);
uint32_t readU32(librevenge::RVNGInputStream *input);
int8_t readS8(librevenge::RVNGInputStream *input);
int16_t readS16(librevenge::RVNGInputStream *input);
int32_t readS32(librevenge::RVNGInputStream *input);

void _appendUTF16(librevenge::RVNGString &text, std::vector<unsigned short> &characters);
void _appendMacRoman(librevenge::RVNGString &text, unsigned char character);

class EndOfStreamException
{
};

class GenericException
{
};

} // namespace libfreehand

#endif // __LIBFREEHAND_UTILS_H__
/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
