#include "stack.h"
#include "display.h"
#include "errorhandling.h"
#include <stdio.h>

typedef struct {
   int array[STACK_SIZE];
   int top;
} Stack;

static Stack stack;

void init_stack() { stack.top = -1; }

int push(int value) {
   if (stack.top >= STACK_SIZE - 1) {
      return STACKOVERFLOW;
   }
   stack.array[++stack.top] = value;
   return 0;
}

int pop(int *value) {
   if (stack.top < 0) {
      return STACKUNDERFLOW;
   }
   *value = stack.array[stack.top--];
   return 0;
}

int prt_top() {
   if (stack.top < 0) {
      return EMPTYSTACK;
   }
   char str_buffer[STR_BUFFER_SIZE];
   sprintf(str_buffer, "%d", stack.array[stack.top]);
   print_stdout(str_buffer);
   print_stdout("\n");
   return 0;
}

int prt_three() {
   int var1;
   int var2;
   int var3;
   char str_buffer[STR_BUFFER_SIZE];

   error_code = pop(&var1);
   if (error_code != 0) {
      return error_code;
   }
   sprintf(str_buffer, "%d", var1);
   print_stdout(str_buffer);
   print_stdout("\n");

   error_code = pop(&var2);
   if (error_code != 0) {
      push(var1);
      return error_code;
   }
   sprintf(str_buffer, "%d", var2);
   print_stdout(str_buffer);
   print_stdout("\n");

   error_code = pop(&var3);
   if (error_code != 0) {
      push(var2);
      push(var1);
      return error_code;
   }
   sprintf(str_buffer, "%d", var3);
   print_stdout(str_buffer);
   print_stdout("\n");

   push(var3);
   push(var2);
   push(var1);
   return 0;
}

void clear() {
   stack.top = -1;
   error_code = 0;
   clear_stdout();
}

int double_top() {
   if (stack.top < 0) {
      return EMPTYSTACK;
   }
   if (stack.top >= STACK_SIZE - 1) {
      return STACKOVERFLOW;
   }
   push(stack.array[stack.top]);
   return 0;
}

int swap() {
   if (stack.top < 1) {
      return NOTENOUGHTELEMENTS;
   }
   int temp = stack.array[stack.top];
   stack.array[stack.top] = stack.array[stack.top - 1];
   stack.array[stack.top - 1] = temp;
   return 0;
}

int rollback(int var1, int var2) {
   push(var2);
   push(var1);
   return INTEGEROVERFLOW;
}