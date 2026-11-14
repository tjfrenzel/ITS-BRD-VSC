#ifndef ENCODER_H
#define ENCODER_H

#include <stdbool.h>
#include <stdint.h>

#define IDR_MASK_ENCODER (0x03U) // Maske für die beiden Encoder-Pins (Pin 0 und Pin 1)
#define IDR_MASK_RESET_BUTTON (0x40U) // Maske für den Reset-Button (Pin 6)

typedef enum {
    PHASE_A = 0,
    PHASE_B = 2,
    PHASE_C = 3,
    PHASE_D = 1,
} phase_enum;

typedef struct {
    phase_enum phase_new;
    phase_enum phase_old;
    bool reset_button_pressed;
    uint32_t timestamp;
} Encoder_t;

void encoder_read(Encoder_t *encoder);

#endif