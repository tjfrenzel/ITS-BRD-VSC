/**
 ******************************************************************************
 * @file    main.c
 * @author  Franz Korf
 * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/

#include "calculator.h"
#include "display.h"
#include "init.h"
#include "my_error.h"
#include "scanner.h"
#include "stack.h"
#include "stm32f4xx_hal.h"
#include "token.h"
#include <stdio.h>

#define POLL_DELAY 10
#define CHAR_BUFFER 32

int main(void) {
   initITSboard(); // Initialisierung des ITS Boards

   init_display();

   while (1) {

      int err = 0;

      T_token token = next_token();

      switch (token.tok) {
      case NUMBER:
         err = push(token.val);
         break;

      case PLUS:
         err = calc_add();
         break;

      case MINUS:
         err = calc_sub();
         break;

      case MULT:
         err = calc_mul();
         break;

      case DIV:
         err = calc_div();
         break;

      case PRT: {
         int out;
         err = peek(&out);

         if (err == 0) {
            clear_stdout();
            char msg[CHAR_BUFFER];
            sprintf(msg, "%d", out);
            print_stdout(msg);
         }
         break;
      }
      case PRT_ALL: {
         T_peek3result result = {.count = 0};
         err = peek_3(&result);

         if (err == 0) {
            clear_stdout();
            char msg[3][CHAR_BUFFER];

            for (int i = 0; i < result.count; i++) {
               sprintf(msg[i], "%d\n", result.values[i]);
            }
            for (int i = 0; i < result.count; i++) {
               print_stdout(msg[i]);
            }
         }
         break;
      }
      case CLEAR:
         set_normal_mode();
         clear();
         break;

      case DOUBLE:
         err = copy();
         break;

      case SWAP:
         err = swap();
         break;

      default:
         break;
      }

      if (err < 0) {
         set_err_mode();
         print_stdout(my_strerror(err));
      }

      HAL_Delay(POLL_DELAY);
   }
}