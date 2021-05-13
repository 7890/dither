/* 
 *  MCQuantization.h
 *  dither Utility
 *
 *  Quantization algorithm declarations.
 *
 */

#ifndef _MC_QUANTIZATION_H_
#define _MC_QUANTIZATION_H_

#include <stdint.h>

typedef uint8_t mc_byte_t;
typedef unsigned int mc_uint_t;

typedef struct {
	mc_byte_t value[3];
} MCTriplet;

MCTriplet MCTripletMake(mc_byte_t r, mc_byte_t g, mc_byte_t b);
MCTriplet *MCQuantizeData(MCTriplet *data, mc_uint_t size, mc_byte_t level);

#endif
