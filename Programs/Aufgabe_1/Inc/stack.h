/**
 * @file stack.h
 * @author Trung Duc Nguyen, Tim-Jonas Frenzel
 * @date 29.10.26
 * @brief Header file of module containing stack operations.
 */

#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 10

typedef struct Peek3Result {
   int values[3];
   int count;
} T_peek3result;

int push(int);

int pop(int *);

int is_empty();

int is_full();

void clear();

int peek(int *);

int peek_3(T_peek3result *);

int swap();

int copy();

#endif