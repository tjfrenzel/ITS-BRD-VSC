/**
 * @file stack.h
 * @author Trung Duc Nguyen, Tim-Jonas Frenzel
 * @date 29.10.26
 * @brief Header file of module containing stack operations.
 */

#ifndef STACK_UTIL_H
#define STACK_UTIL_H

typedef struct {
   int values[3];
   int count;
} T_peek3result;

int peek(int *);

int peek_3(T_peek3result *);

int swap();

int copy();

#endif