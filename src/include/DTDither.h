/*
 *  DTDither.h
 *  dither Utility
 *
 *  Dithering methods declarations
 *
 */

#ifndef _DT_DITHER_H_
#define _DT_DITHER_H_

#include <DTImage.h>
#include <DTPalette.h>

void ApplyFloydSteinbergDither(DTImage *image, DTPalette *palette);

#endif
