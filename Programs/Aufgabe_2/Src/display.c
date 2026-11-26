#include "display.h"
#include <stdio.h>
#include "lcd.h"

void init_display(){
    lcdGotoXY(0, 0);
    lcdPrintlnS("=== Drehmotor ===");

    lcdGotoXY(0, 1);
    lcdPrintlnS("Winkel:");

    lcdGotoXY(0, 2);
    lcdPrintlnS("Geschw.:");
}