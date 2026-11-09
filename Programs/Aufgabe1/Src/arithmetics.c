#include "errorhandling.h"
#include "stack.h"
#include <stdint.h>

int add() {
   int var1;
   int var2;

   error_code = pop(&var1);
   if (error_code != 0) {
      return error_code;
   }

   error_code = pop(&var2);
   if (error_code != 0) {
      push(var1);
      return error_code;
   }

   if ((var1 > 0 && var2 > 0 && var1 > INT32_MAX - var2) ||
       (var1 < 0 && var2 < 0 && var1 < INT32_MIN - var2)) {
      error_code = rollback(var1, var2);
      return error_code;
   }

   push(var2 + var1);
   return 0;
}

int subtract() {
   int var1;
   int var2;

   error_code = pop(&var1);
   if (error_code != 0) {
      return error_code;
   }

   error_code = pop(&var2);
   if (error_code != 0) {
      push(var1);
      return error_code;
   }

   if ((var1 < 0 && var2 > INT32_MAX + var1) ||
       (var1 > 0 && var2 < INT32_MIN + var1)) {
      error_code = rollback(var1, var2);
      return error_code;
   }

   push(var2 - var1);
   return 0;
}

int multiply() {
   int var1;
   int var2;

   error_code = pop(&var1);
   if (error_code != 0) {
      return error_code;
   }

   error_code = pop(&var2);
   if (error_code != 0) {
      push(var1);
      return error_code;
   }

   // positives Ergebnis
   if (((var1 > 0 && var2 > 0) && (var1 > (INT32_MAX / var2))) ||
       ((var1 > 0 && var2 < 0) && (var2 < (INT32_MIN / var1))) ||
       ((var1 < 0 && var2 > 0) && (var1 < (INT32_MIN / var2))) ||
       ((var1 < 0 && var2 < 0) && (var1 < (INT32_MAX / var2)))) {
      error_code = rollback(var1, var2);
      return error_code;
   }

   push(var2 * var1);
   return 0;
}

int divide() {
   int var1;
   int var2;

   error_code = pop(&var1);
   if (error_code != 0) {
      return error_code;
   }

   error_code = pop(&var2);
   if (error_code != 0) {
      push(var1);
      return error_code;
   }

   if (var1 == 0) {
      push(var2);
      push(var1);
      return DIVISIONBYZERO;
   }

   if (var1 == INT32_MIN && var2 == -1) {
      error_code = rollback(var1, var2);
      return error_code;
   }

   push(var2 / var1);
   return 0;
}