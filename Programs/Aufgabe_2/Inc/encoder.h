#ifndef ENCODER_H
#define ENCODER_H

#include <stdint.h>

typedef struct {
    uint8_t phase;
    uint32_t timestamp;
}Encoder_t;

void encoder_read(Encoder_t *encoder);

#endif