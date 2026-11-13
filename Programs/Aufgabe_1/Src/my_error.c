#include "my_error.h"

char *my_strerror(int err_number) {

   if (err_number < 0) {
      err_number = -err_number;
   }

   switch (err_number) {
   case E_STACKOVERFLOW:
      return "Error: Stack Overflow";

   case E_STACKUNDERFLOW:
      return "Error: Stack Underflow";

   case E_INTOVERFLOW:
      return "Error: Integer Overflow";

   case E_DIVBYZERO:
      return "Error: Division by zero";

   default:
      return "Unknown Error";
   }
}