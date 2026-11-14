
#include "encoder.h"
#include "stm32f429xx.h"
#include "timer.h"

void encoder_read(Encoder_t *encoder){
    uint32_t gpio_state;

    // GPIO-Eingänge auslesen
    gpio_state = GPIOF->IDR;

    // Phase bilden: Bits isolieren
    encoder->phase_new = (phase_enum) (gpio_state & IDR_MASK_ENCODER);

    // Reset-Button-Zustand erfassen
    encoder->reset_button_pressed = (gpio_state & IDR_MASK_RESET_BUTTON) != 0;

    // Zeitstempel erfassen
    encoder->timestamp = getTimeStamp();
}
