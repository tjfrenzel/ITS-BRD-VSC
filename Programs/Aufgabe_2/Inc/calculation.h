#ifndef CALCULATION_H
#define CALCULATION_H

#include "decoder.h"
#include <stdint.h>

#define DEGREE_MAX 360
#define DEGREE_PHASE_CHANGE 0.3
#define US_TO_S 1000000.0

typedef struct {
    int32_t counter;
    uint32_t timestamp;
    uint8_t initialized;
} Calculation_t;

void calculation_init(Calculation_t *calc, Decoder_t *decoder);

int calculate_angle(double * result, Decoder_t *decoder);

int calculate_speed(double * result, Decoder_t *decoder, Calculation_t *calc);

#endif