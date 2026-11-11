#include "gpio.h"
#include "stm32f429xx.h"
#include "finalstatemachine.h"


void read_inputs() {
    gpio_t.snapshot = GPIOF->IDR; // inputs als Snapshot speichern
    gpio_t.channel_a = (gpio_t.snapshot & IDR_MASK_PIN_0) == 0;
    gpio_t.channel_b = (gpio_t.snapshot & IDR_MASK_PIN_1) == 0;
    gpio_t.reset_button = (gpio_t.snapshot & IDR_MASK_PIN_6) == 0;
}

void output_led(){
    uint32_t set_mask;

    if (state.error == ERROR) {
        return;
    }

    switch (state.current_state){
        case FORWARD:
            set_mask = BSRR_MASK_PIN_23 | (BSRR_MASK_PIN_22 << 16);
            break;
        case BACKWARD:
            set_mask = BSRR_MASK_PIN_22 | (BSRR_MASK_PIN_23 << 16);
            break;
        default:
            set_mask = BSRR_MASK_PIN_21;
            break;
    }
    GPIOE->BSRR = set_mask;                       // unsicher bei LED ausgabe
    GPIOD->BSRR = (uint8_t)(phase.phase_counter); // unsicher bei LED ausgabe
}
// to do: reset button implementieren