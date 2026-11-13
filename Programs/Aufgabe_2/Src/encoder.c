
#include "encoder.h"
#include "stm32f429xx.h"
#include "timer.h"

void encoder_read(Encoder_t *encoder){
    uint32_t gpio_state;

    // GPIO-Eingänge auslesen
    gpio_state = GPIOF->IDR;

    // Phase bilden: Bits isolieren, dann tauschen 
    encoder->phase = ((gpio_state & 0x01U) << 1) | ((gpio_state & 0x02U) >> 1);

    // Zeitstempel erfassen
    encoder->timestamp = getTimeStamp();
}