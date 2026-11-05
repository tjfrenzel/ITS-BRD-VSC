/**
 * @file calculator.h
 * @author Trung Duc Nguyen, Tim-Jonas Frenzel
 * @date 29.10.26
 * @brief Header file of module wrapping arithmetic operations into stack
 * operations.
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

typedef int (*arithmetic_operation)(int, int, int *);

int calc_add();

int calc_sub();

int calc_mul();

int calc_div();

int calc(arithmetic_operation);

#endif