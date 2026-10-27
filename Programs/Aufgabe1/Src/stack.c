#include "display.h"
#include "stack.h"
#include "errorhandling.h"

Stack stack;

void init_stack(){
    stack.top = -1;
}

int push(int value){
    if (stack.top >= STACK_SIZE - 1){
        return STACKOVERFLOW;
    }
    stack.array[++stack.top] = value;
    return 0;
}

int pop(int *value){
    if (stack.top < 0){
        return STACKUNDERFLOW;
    }
    *value = stack.array[stack.top--];
    return 0;
}

int prt_top(){
    if (stack.top < 0){
        return EMPTYSTACK;
    }
    char str_buffer[STR_BUFFER_SIZE];
    int_to_str(stack.array[stack.top], str_buffer);
    print_stdout(str_buffer);
    print_stdout("\n");
    return 0;
}

int prt_three(){
    if (stack.top < 0){
        return EMPTYSTACK;
    }
    char str_buffer[STR_BUFFER_SIZE];
    for (int i = stack.top; i >= 0; i--) {
        int_to_str(stack.array[i], str_buffer);
        print_stdout(str_buffer);
        print_stdout("\n");
    }
    return 0;
}

void clear(){
    stack.top = -1;
    clear_stdout();
}

int double_top(){
    if (stack.top < 0){
        return EMPTYSTACK;
    }
    if (stack.top >= STACK_SIZE - 1){
        return STACKOVERFLOW;
    }
    push(stack.array[stack.top]);
    return 0;
}

int swap(){
    if (stack.top < 1){
        return NOTENOUGHTELEMENTS;
    }
    int temp = stack.array[stack.top];
    stack.array[stack.top] = stack.array[stack.top - 1];
    stack.array[stack.top - 1] = temp;
    return 0;
}

char* int_to_str(int value, char *str_buffer) {
    int i = 0;
    long long temp = value;
    int is_negative = 0;
    
    if (stack.top < 0) {
        str_buffer[0] = '0';
        str_buffer[1] = '\0';
        return str_buffer;
    }

    if (value < 0) {
        is_negative = 1;
        temp = -temp;
    }
    
    // Ziffern zählen
    int digits = 0;
    long long temp2 = temp;
    do {
        digits++;
        temp2 /= 10;
    } while (temp2 > 0);
    
    if (is_negative) {
        str_buffer[0] = '-';
        i = 1;
    }
    
    // Ziffern von rechts nach links speichern
    for (int j = digits - 1; j >= 0; j--) {
        str_buffer[i + j] = (char)('0' + (temp % 10));  // Cast to fix warning
        temp /= 10;
    }
    str_buffer[i + digits] = '\0';  // Null-Terminator
    return str_buffer;
}