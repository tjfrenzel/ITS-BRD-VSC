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
#include "display.h"
#include "errorhandling.h"
#include "init.h"
#include "stack.h"
#include "stm32f4xx_hal.h"
#include "token.h"
#include <stdbool.h>

int main(void) {
   initITSboard(); // Initialisierung des ITS Boards

   init_display(); // Initialisierung der Display Funktionen
   init_stack();   // Initialisierung des Stacks

   // Test in Endlosschleife
   const int POLL_DELAY = 10;
   while (1) {
      process_token();
      process_error_code(error_code);
      HAL_Delay(POLL_DELAY);
   }
}
// EOF