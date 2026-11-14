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
#include "calculation.h"
#include "encoder.h"
#include "decoder.h"
#include "init.h"
#include "lcd.h"
#include "led.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"

int main(void) {
   
   //Initialisierung von Clock, Mode und Pullup der GPIOs inkludiert
   initITSboard(); // Initialisierung des ITS Boards
   GUI_init(DEFAULT_BRIGHTNESS); // Initialisierung der GUI

   Encoder_t encoder;
   Decoder_t decoder;   

   //Super loop
   while (1) {

      encoder_read(&encoder);
      decoder.error_code = decoder_decode(&encoder, &decoder);
      if (!decoder.error_code) {
         led_update_direction(&decoder);
         led_update_counter(&decoder);
         continue; // Schleife fortsetzen, um weitere Eingaben zu ignorieren
      }

      if (encoder.reset_button_pressed){
         init_decoder(&decoder);
      }

      /*
      // Eingänge einlesen
      button_read();
      encoder_read(&encoder);
      
      // Phase auswerten
      // Phasenzähler aktualisieren
      decoder_decode(&encoder, &decoder);

      // Winkel berechnen
      calculate_angle(&angle, &decoder);
      
      // Winkelgeschwindigkeit berechnen
      calculate_speed(&speed, &decoder, &calc);
      
      // LEDs aktualisieren
      led_direction_update(&decoder.direction);
      led_counter_update(&decoder.counter);
      
      // LCD aktualisieren
      */
   }
}

// EOF
