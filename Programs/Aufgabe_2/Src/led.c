#include "led.h"
#include "decoder.h"
#include "stm32f429xx.h"
#include <stdint.h>

void led_update_direction(Decoder_t *decoder){

    switch (decoder->direction) {
        case DECODED_DIR_FORWARD:
            GPIOE->BSRR = BSRR_MASK_FORWARD;
            break;
        case DECODED_DIR_BACKWARD:
            GPIOE->BSRR = BSRR_MASK_BACKWARD;
            break;
        default:
            break;
    }
}

void led_update_counter(Decoder_t *decoder){
    GPIOD->ODR = (uint8_t)(decoder->phase_counter);
}

/*
void led_direction_update(const Encoder_Direction_t *direction){
    if(*direction == ENCODER_DIR_FORWARD){
        GPIOD->BSRR = MASK_LED_FORWARD;
    }
    
    if(*direction == ENCODER_DIR_BACKWARD){
        GPIOD->BSRR = MASK_LED_BACKWARD;
    }
}

void led_counter_update(const int32_t *counter){
    uint32_t value = (uint32_t)(*counter) & MASK_COUNTER_LOW;

    GPIOD->BSRR = MASK_COUNTER_BSSR | value;
}

void led_error(){
    GPIOE->BSRR = MASK_LED_ERROR;
}

void led_reset(){
    GPIOE->BSRR = MASK_LED_RESET;
}
*/