/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char **argv)
{
    stack_t *my_stack = stack_init(MAX_STACK_SIZE);
    int stack_peek = 0;
    int option;
    int args;

    do 
    {
        printf("Type a option to manage stack usage.\n");
        printf("0. To exit the program \n");
        printf("1. To Push data at stack \n");
        printf("2. To Pop data from stack \n");
        printf("3. To print the stack \n");

        scanf("%d", &option);

        switch (option)
        {
            case 1:
            {
                printf("Type a arg to push at stack \n");
                scanf("%d", &args);
                push_stack(my_stack, args);
                stack_peek++;
                break;
            }
            case 2:
            {
                printf("An argument it had removed of stack \n");
                pop_stack(my_stack);
                stack_peek--;
                break;
            }
            case 3:
            {
                print_stack(my_stack);
                break;
            }
        }


    }while (option != 0);


    return 0;
}