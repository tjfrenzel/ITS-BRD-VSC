#ifndef DECODER_H
#define DECODER_H

#include <stdint.h>
#include "encoder.h"

typedef enum {
    ENCODER_DIR_BACKWARD = -1,
    ENCODER_DIR_NONE,
    ENCODER_DIR_FORWARD,
} Encoder_Direction_t;

typedef struct {
    uint8_t phase;
    
    int32_t counter;
    
    Encoder_Direction_t direction;
    
    uint32_t timestamp;

    uint8_t initialized;
}Decoder_t;

void decoder_init(Decoder_t *decoder, Encoder_t *encoder);

int decoder_decode(Decoder_t *decoder, Encoder_t *encoder);

#endif