#include "stack_util.h"
#include "stack.h"

int peek(int *val_ptr) {

   int err = pop(val_ptr);
   if (err < 0) {
      return err;
   }

   push(*val_ptr);

   return 0;
}

int peek_3(T_peek3result *result) {

   int err = pop(&result->values[0]);

   if (err < 0) {
      return err;
   }

   result->count++;

   err = pop(&result->values[1]);

   if (err < 0) {
      push(result->values[0]);
      return 0;
   }

   result->count++;

   err = pop(&result->values[2]);

   if (err < 0) {
      push(result->values[1]);
      push(result->values[0]);
      return 0;
   }

   result->count++;

   for (int i = result->count - 1; i >= 0; i--) {
      push(result->values[i]);
   }

   return 0;
}

int swap() {

   int val_1;
   int val_2;

   int err = pop(&val_1);
   if (err < 0) {
      return err;
   }

   err = pop(&val_2);
   if (err < 0) {
      push(val_1);
      return err;
   }

   push(val_1);
   push(val_2);

   return 0;
}

int copy() {

   int val;

   int err = pop(&val);
   if (err < 0) {
      return err;
   }

   push(val);

   err = push(val);
   if (err < 0) {
      return err;
   }

   return 0;
}