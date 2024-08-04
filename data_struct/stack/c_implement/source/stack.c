/**
 * @file stack.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "stack.h"
#include <stdio.h>

stack_t *stack_init(int size)
{
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));

    stack->data = (int *) malloc(sizeof(stack_t)* size);
    stack->height = 0;
    return stack;
}

int is_stack_empty(stack_t * stack )
{
    return (stack->height == 0);
}

int is_stack_full(stack_t * stack )
{
    return (stack->height == MAX_STACK_SIZE);
}

void push_stack(stack_t * stack, int data)
{
    if (is_stack_full(stack))
    {
        printf("Stack is full is not possible push data!\n");
        return;
    }
    stack->data[stack->height] = data;
    stack->height++;
    print_stack(stack);
    
}

int pop_stack(stack_t * stack )
{
    if (is_stack_empty(stack))
    {
        printf("Stack is empty is not possible pop data!\n");
        return 0;
    }
    stack->height--;
    return stack->data[stack->height];
}

void print_stack(stack_t * stack)
{
    int i;
    printf(" [");
    for (i = 0; i < stack->height; i++)
    {
        printf("%d ", stack->data[i]);
    } 
    printf("]");
    printf("\n");
}