/**
 * @file my_error.h
 * @author Trung Duc Nguyen, Tim-Jonas Frenzel
 * @date 29.10.26
 * @brief Header file of module containing error definitions and error
 * conversion.
 */

#ifndef MY_ERROR_H
#define MY_ERROR_H

#define E_STACKOVERFLOW 1001
#define E_STACKUNDERFLOW 1002
#define E_DIVBYZERO 1003
#define E_INTOVERFLOW 1004

char *my_strerror(int);

#endif