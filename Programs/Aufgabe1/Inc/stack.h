/**
 * @file stack.h
 * @brief Header file of input module.
 */

#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 10
#define STR_BUFFER_SIZE 50

/*
 ****************************************************************************************
 * @brief :
 * @return
 ****************************************************************************************/


void init_stack(void);
int push(int value);
int pop(int *value);
int prt_top(void);
int prt_three(void);
void clear(void);
int double_top(void);
int swap(void);
int rollback(int var1, int var2);
// char* int_to_str(int value, char *str_buffer);

#endif /* STACK_H */
// EOF
