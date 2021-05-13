/* 
 *  DTPalette.c
 *  dither Utility
 *
 *  Palette functions implementation.
 *
 */

#include <DTPalette.h>
#include <stdlib.h>
#include <math.h>

DTPalette *
StandardPaletteBW(int size)
{
    if (size < 2) return NULL;

    DTPalette *palette = malloc(sizeof(DTPalette));
    palette->size = size;
    palette->colors = malloc(sizeof(DTPixel) * size);

    float step = 255.0f / (size - 1);
    int i;
    for (i = 0; i < size; i++)
	palette->colors[i] = PixelFromRGB(
	    roundf(i*step),
	    roundf(i*step),
	    roundf(i*step)
	);

    return palette;
}

DTPalette *
StandardPaletteRGB()
{
    DTPalette *palette = malloc(sizeof(DTPalette));
    palette->size = 16;
    palette->colors = malloc(sizeof(DTPixel) * palette->size);
    palette->colors[0] = PixelFromRGB(0xFF, 0x00, 0x00);
    palette->colors[1] = PixelFromRGB(0x00, 0xFF, 0x00);
    palette->colors[2] = PixelFromRGB(0x00, 0x00, 0xFF);
    palette->colors[3] = PixelFromRGB(0x00, 0xFF, 0xFF);
    palette->colors[4] = PixelFromRGB(0xFF, 0x00, 0xFF);
    palette->colors[5] = PixelFromRGB(0xFF, 0xFF, 0x00);
    palette->colors[6] = PixelFromRGB(0x00, 0x00, 0x00);
    palette->colors[7] = PixelFromRGB(0xFF, 0xFF, 0xFF);

    palette->colors[8]  = PixelFromRGB(0x88, 0x00, 0x00);
    palette->colors[9]  = PixelFromRGB(0x00, 0x88, 0x00);
    palette->colors[10] = PixelFromRGB(0x00, 0x00, 0x88);
    palette->colors[11] = PixelFromRGB(0x00, 0x88, 0x88);
    palette->colors[12] = PixelFromRGB(0x88, 0x00, 0x88);
    palette->colors[13] = PixelFromRGB(0x88, 0x88, 0x00);
    palette->colors[14] = PixelFromRGB(0x00, 0x00, 0x00);
    palette->colors[15] = PixelFromRGB(0x88, 0x88, 0x88);

    return palette;
}

DTPixel
FindClosestColorFromPalette(DTPixel needle, DTPalette *palette)
{
    // search for smallest Euclidean distance
    int index=0;
    int d, minimal = 255 * 255 * 3 + 1;
    int dR, dG, dB;
    DTPixel current;

    int i;
    for (i = 0; i < palette->size; i++) {
	current = palette->colors[i];
	dR = needle.r - current.r;
	dG = needle.g - current.g;
	dB = needle.b - current.b;
	d = dR * dR + dG * dG + dB * dB;
	if (d < minimal) {
	    minimal = d;
	    index = i;
	}
    }

    return palette->colors[index];
}
