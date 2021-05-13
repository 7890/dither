/*
 *  DTPalette.h
 *  dither Utility
 *
 *  Palette generation, type and function declarations.
 *
 */

#ifndef _DT_PALETTE_H_
#define _DT_PALETTE_H_

#include <DTPixel.h>

typedef struct {
	int size;
	DTPixel *colors;
} DTPalette;

DTPalette *StandardPaletteBW(int size);
DTPalette *StandardPaletteRGB();

DTPixel FindClosestColorFromPalette(DTPixel pixel, DTPalette *palette);

#endif
