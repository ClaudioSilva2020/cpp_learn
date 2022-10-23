/**
 * @file stack.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "stack.h"

Stack::Stack()
{
    height = 0;
    data = new stack_type[MAX_STACK_SIZE];
}

Stack::~Stack()
{
    delete[] data;
}

bool Stack::isEmpty()
{
    return (height == 0);
}

bool Stack::isFull()
{
    return (height == MAX_STACK_SIZE);
}

void Stack::push(stack_type stack_data)
{
    if (isFull())
    {
        cout << "The stack is full";
        return;
    }else
    {
        data[height] = stack_data;
        height++;
    }
}

stack_type Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty";
        return -1;
    }else
    {
        cout << "The deleted data is " << height;
        cout << "\n";
        height--;
        return data[height];
    }
}

int Stack::length()
{
    return height;
}

void Stack::clear()
{
    height = 0;
    delete[] data;
}

void Stack::print()
{
    cout << "[";
    for (int i = 0; i < height; i++)
    {
        cout << data[i] << " ";
    }
    cout << "]\n";
}
