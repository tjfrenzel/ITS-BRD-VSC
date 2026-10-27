#include "display.h"
#include "errorhandling.h"

int error_code = 0;

void process_error_code(int error_code){
    switch (error_code) {
        case STACKOVERFLOW:
            print_stdout("Error: Stack Overflow \n");
            break;
        case STACKUNDERFLOW:
            print_stdout("Error: Stack Underflow \n");
            break;
        case EMPTYSTACK:
            print_stdout("Error: Stack is empty \n");
            break;
        case NOTENOUGHTELEMENTS:
            print_stdout("Error: Not enough elements on the stack \n");
            break;
        case INTEGEROVERFLOW:
            print_stdout("Error: Integer overflow \n");
            break;
        case DIVISIONBYZERO:
            print_stdout("Error: Division by zero \n");
            break;
		default:
			break;
    }
}