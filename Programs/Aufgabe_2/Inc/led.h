#ifndef LED_H
#define LED_H

#include "decoder.h"
#include <stdint.h>

#define BSRR_MASK_ERROR (0x01u << 5) // Maske Pin 21 für Fehlererkennung
#define BSRR_MASK_BACKWARD (0x01u << 6) // Maske Pin 22 für Rückwärts
#define BSRR_MASK_FORWARD (0x01u << 7) // Maske Pin 23 für Vorwärts

void led_update_direction(Decoder_t *decoder);
void led_update_counter(Decoder_t *decoder);

/*
#define MASK_LED_FORWARD 0xFFFF0080U
#define MASK_LED_BACKWARD 0xFFFF0040U
#define MASK_LED_ERROR 0xFFFF0020U
#define MASK_LED_RESET 0xFFFF0000U

#define MASK_COUNTER_LOW 0xFFU
#define MASK_COUNTER_BSSR 0xFFFF0000U

void led_direction_update(const Encoder_Direction_t *direction);

void led_counter_update(const int32_t *counter);

void led_error();

void led_reset();
*/
#endif