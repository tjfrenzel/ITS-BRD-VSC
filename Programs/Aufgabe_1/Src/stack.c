#include "stack.h"
#include "my_error.h"

static T_stack stack = {
    .ptr = -1,
};

int push(int value) {
   if (!is_full()) {
      stack.arr[++stack.ptr] = value;
      return 0;
   }
   return -E_STACKOVERFLOW;
}

int pop(int *value_ptr) {
   if (!is_empty()) {
      *value_ptr = stack.arr[stack.ptr--];
      return 0;
   }
   return -E_STACKUNDERFLOW;
}

int is_empty() { return stack.ptr == -1; }

int is_full() { return stack.ptr == (STACK_SIZE - 1); }

void clear() { stack.ptr = -1; }