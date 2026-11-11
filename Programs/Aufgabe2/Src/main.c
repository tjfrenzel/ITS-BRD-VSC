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
#include "gpio.h"
#include "finalstatemachine.h"
#include "display.h"

int main(void) {
   initITSboard(); // Initialisierung des ITS Boards

   GUI_init(DEFAULT_BRIGHTNESS); // Initialisierung des LCD Boards mit Touch
   TP_Init(false); // Initialisierung des LCD Boards mit Touch

   init_display(); // Initialisierung der Anzeige

   // Test in Endlosschleife
   const int POLL_DELAY = 10000;
   while (1) {
      read_inputs(); // Eingänge lesen
      get_phase(); // Phase bestimmen
      get_state(); // Zustand bestimmen
      output_led(); // LEDs ausgeben

      HAL_Delay(POLL_DELAY);
   }
}

// EOF
