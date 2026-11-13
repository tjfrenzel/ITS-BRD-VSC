#ifndef DECODER_H
#define DECODER_H

#include <stdint.h>
#include "encoder.h"


typedef enum {
    DECODED_DIR_BACKWARD = -1,
    DECODED_DIR_NONE = 0,
    DECODED_DIR_FORWARD = 1,
} direction_enum;

typedef struct {
    direction_enum direction;
    int phase_counter;
    uint32_t timestamp;
} Decoder_t;

int decoder_decode(Encoder_t *encoder, Decoder_t *decoder);
/*
void decoder_init(Decoder_t *decoder, Encoder_t *encoder);

int decoder_decode(Decoder_t *decoder, Encoder_t *encoder);
*/
#endif