/**
 * @file stack.h
 * @author Trung Duc Nguyen, Tim-Jonas Frenzel
 * @date 29.10.26
 * @brief Header file of module containing stack operations.
 */

#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 10

typedef struct {
   int arr[STACK_SIZE];
   int ptr;
} T_stack;

int push(int);

int pop(int *);

int peek(int *);

int is_empty();

int is_full();

void clear();

#endif