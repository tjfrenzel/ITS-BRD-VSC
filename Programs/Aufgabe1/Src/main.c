/**
 ******************************************************************************
 * @file    main.c
 * @author  Franz Korf
 * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/

#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "init.h"
#include "lcd.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <stdbool.h>
#include "display.h"
#include "stack.h"

int main(void) {
   initITSboard(); // Initialisierung des ITS Boards

   GUI_init(DEFAULT_BRIGHTNESS); // Initialisierung des LCD Boards mit Touch
   TP_Init(false); // Initialisierung des LCD Boards mit Touch

   init_display(); // Initialisierung der Display Funktionen
   init_stack();   // Initialisierung des Stacks

   // Test in Endlosschleife
   const int POLL_DELAY = 10000;
   while (1) {
      HAL_Delay(POLL_DELAY);
   }
}

// EOF
