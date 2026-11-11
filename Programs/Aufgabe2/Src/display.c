#import "display.h"
#import <stdbool.h>
#import "lcd.h"

static bool initialized = false;

void init_display() {
    if (initialized) {
        return; // Display already initialized
    }
    lcdGotoXY(0, 0);
    lcdPrintlnS("=== Drehmotor ===");

    lcdGotoXY(0, 1);
    lcdPrintlnS("Winkel:");

    lcdGotoXY(0, 2);
    lcdPrintlnS("Geschw.:");

    initialized = true;
}