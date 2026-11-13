#ifndef ENCODER_H
#define ENCODER_H

#include <stdint.h>

#define IDR_MASK_ENCODER (0x03U) // Maske für die beiden Encoder-Pins (Pin 0 und Pin 1)

typedef enum {
    PHASE_A = 0,
    PHASE_B = 1,
    PHASE_C = 2,
    PHASE_D = 3,
} phase_enum;

typedef struct {
    phase_enum phase_new;
    phase_enum phase_old;
    uint32_t timestamp;
} Encoder_t;

void encoder_read(Encoder_t *encoder);

#endif