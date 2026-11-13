#include "arithmetic.h"
#include "my_error.h"
#include <limits.h>

int add(int value_1, int value_2, int *result) {

   if ((value_2 > 0 && value_1 > INT_MAX - value_2) ||
       (value_2 < 0 && value_1 < INT_MIN - value_2)) {
      return -E_INTOVERFLOW;
   }

   *result = value_1 + value_2;
   return 0;
}

int subtract(int value_1, int value_2, int *result) {

   if ((value_2 < 0 && value_1 > INT_MAX + value_2) ||
       (value_2 > 0 && value_1 < INT_MIN + value_2)) {
      return -E_INTOVERFLOW;
   }

   *result = value_1 - value_2;
   return 0;
}

int multiply(int value_1, int value_2, int *result) {

   if ((value_1 > 0) && ((value_2 > 0 && value_1 > INT_MAX / value_2) ||
                         (value_2 < 0 && value_2 < INT_MIN / value_1))) {
      return -E_INTOVERFLOW;
   }
   if ((value_1 < 0) && ((value_2 > 0 && value_1 < INT_MIN / value_2) ||
                         (value_2 < 0 && value_1 < INT_MAX / value_2))) {
      return -E_INTOVERFLOW;
   }

   *result = value_1 * value_2;
   return 0;
}

int divide(int value_1, int value_2, int *result) {

   if (value_2 == 0) {
      return -E_DIVBYZERO;
   }

   if (value_1 == INT_MIN && value_2 == -1) {
      return -E_INTOVERFLOW;
   }

   *result = value_1 / value_2;
   return 0;
}