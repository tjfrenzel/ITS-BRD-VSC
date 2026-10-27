/**
 * @file stack.h
 * @brief Header file of input module.
 */

#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 5
#define STR_BUFFER_SIZE 50

/*
 ****************************************************************************************
 * @brief : 
 * @return 
 ****************************************************************************************/
typedef struct {
    int array[STACK_SIZE];
    int top;
} Stack;

void init_stack(void);
int push(int value);
int pop(int *value);
int prt_top(void);
int prt_three(void);
void clear(void);
int double_top(void);
int swap(void);
char* int_to_str(int value, char *str_buffer);

#endif /* STACK_H */
// EOF
