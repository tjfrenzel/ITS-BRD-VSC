#include "calculator.h"
#include "arithmetic.h"
#include "stack.h"

int calc_add() { return calc(add); }

int calc_sub() { return calc(subtract); }

int calc_mul() { return calc(multiply); }

int calc_div() { return calc(divide); }

int calc(arithmetic_operation operation) {
   int val_1;
   int val_2;
   int result;

   int err = pop(&val_1);
   if (err < 0) {
      return err;
   }

   err = pop(&val_2);
   if (err < 0) {
      push(val_1);
      return err;
   }

   err = operation(val_2, val_1, &result);
   if (err < 0) {
      push(val_2);
      push(val_1);
      return err;
   }

   push(result);

   return 0;
}