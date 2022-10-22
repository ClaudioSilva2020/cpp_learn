/**
 * @file stack.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

#define MAX_LENGTH_STACK_SIZE 256

class Stack
{
private:
    /* data */
    int data[MAX_LENGTH_STACK_SIZE];
    int top;


public:
    Stack(/* args */);
    ~Stack();
    void push(int);
    int pop();
    int isEmpty();
    int isFull();
};

