/**
 * @file gpio.h
 * @brief Header file for the GPIO functions.
 */

#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>

#define IDR_MASK_PIN_0 (0x01u << 0) // Maske Pin 0 für Input
#define IDR_MASK_PIN_1 (0x01u << 1) // Maske Pin 1 für Input
#define IDR_MASK_PIN_6 (0x01u << 6) // Maske Pin 2 für Input

#define BSRR_MASK_PIN_21 (0x01u << 5) // Maske Pin 21 für Fehlererkennung
#define BSRR_MASK_PIN_22 (0x01u << 6) // Maske Pin 22 für Rückwärts
#define BSRR_MASK_PIN_23 (0x01u << 7) // Maske Pin 23 für Vorwärts

/*
 ****************************************************************************************
 * @brief :
 * @return
 ****************************************************************************************/
typedef struct {
    uint32_t snapshot;
    bool channel_a;
    bool channel_b;
    bool reset_button;
} gpio;
extern gpio gpio_t;

void read_inputs(void);
void output_led(void);

#endif /* GPIO_H */
       // EOF   