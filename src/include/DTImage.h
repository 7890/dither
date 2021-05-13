/*
 *  DTImage.h
 *  dither Utility
 *
 *  Basic image related structures and function declarations.
 *
 */

#ifndef _DT_IMAGE_H_
#define _DT_IMAGE_H_

#define e_PPM ".ppm"
#define e_PNG ".png"

#include <DTPixel.h>

typedef enum{
	t_PPM,
	t_PNG,
	t_UNKNOWN
} DTImageType;

typedef struct {
	int width;
	int height;
	DTImageType type;
	unsigned long resolution;
	DTPixel *pixels;
} DTImage;

DTImage *CreateImageFromFile(char *filename);
void WriteImageToFile(DTImage *img, char *filename);

#endif
