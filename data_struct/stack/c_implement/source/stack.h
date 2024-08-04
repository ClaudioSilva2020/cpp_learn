/**
 * @file stack.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __STACK_H__
#define __STACK_H__

#define MAX_STACK_SIZE 100

typedef struct _stack_t 
{
    int *data;
    int height;
    int peek;
} stack_t;

stack_t *stack_init(int size);
int is_stack_empty(stack_t * stack );
int is_stack_full(stack_t * stack );
void push_stack(stack_t * stack, int data);
int pop_stack(stack_t * stack );
void print_stack(stack_t * stack);


#endif /* __STACK_H__ */