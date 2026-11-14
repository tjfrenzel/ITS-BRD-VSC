#include "decoder.h"
#include <stdint.h>
#include "encoder.h"
#include "myerror.h"


int decoder_decode(Encoder_t *encoder, Decoder_t *decoder) {
    
    if (decoder->error_code) {
        return decoder->error_code;
    }

    int phase_diff = encoder->phase_new - encoder->phase_old;
    encoder->phase_old = encoder->phase_new;

    switch (phase_diff) {
        case 1:
        case -3:
            decoder->direction = DECODED_DIR_FORWARD;
            decoder->phase_counter++;
            decoder->timestamp = encoder->timestamp;
            break;
        case -1:
        case 3:
            decoder->direction = DECODED_DIR_BACKWARD;
            decoder->phase_counter--;
            decoder->timestamp = encoder->timestamp;
            break;
        case 0:
            decoder->direction = DECODED_DIR_NONE;
            break;
        default:
            return decoder->error_code = ERROR;
    };
    return 0;
}

void init_decoder (Decoder_t *decoder){
    decoder->direction = DECODED_DIR_NONE;
    decoder->phase_counter = 0;
    decoder->error_code = 0;
}

/*
static const int8_t DECODER_TABLE[16] = {
    0, -1, 1, 2,
    1, 0, 2, -1,
    -1, 2, 0, 1,
    2, 1, -1, 0,
};
 
void decoder_init(Decoder_t *decoder, Encoder_t *encoder)
{
    decoder->phase = encoder->phase;
    decoder->counter = 0;
    decoder->direction = ENCODER_DIR_NONE;
    decoder->timestamp = encoder->timestamp;
    decoder->initialized = 1;
}

int decoder_decode(Decoder_t *decoder, Encoder_t *encoder){
    
    int8_t result;
    uint8_t index;
    
    if(!decoder->initialized){
        
        decoder->phase = encoder->phase;
        decoder->timestamp = encoder->timestamp;
        decoder->counter = 0;
        decoder->direction = ENCODER_DIR_NONE;
        decoder->initialized = 1;

        return 0;
    }

    index = (encoder->phase << 2) | decoder->phase;

    result = DECODER_TABLE[index];

    if (result == ENCODER_DIR_FORWARD || result == ENCODER_DIR_BACKWARD){
        
        decoder->direction = (Encoder_Direction_t)result;
        decoder->counter += decoder->direction;
        decoder->phase = encoder->phase;
        decoder->timestamp = encoder->timestamp;
    }

    return result;
}
*/