#include "display.h"
#include "errorhandling.h"

void process_error_code(int error_code){
    switch (error_code) {
        case STACKOVERFLOW:
            print_stdout("Error: Stack Overflow");
            break;
        case STACKUNDERFLOW:
            print_stdout("Error: Stack Underflow");
            break;
        case EMPTYSTACK:
            print_stdout("Error: Stack is empty");
            break;
        case NOTENOUGHTELEMENTS:
            print_stdout("Error: Not enough elements on the stack");
            break;
        case INTEGEROVERFLOW:
            print_stdout("Error: Integer overflow");
            break;
        case DIVISIONBYZERO:
            print_stdout("Error: Division by zero");
            break;
		default:
			break;
    }
}