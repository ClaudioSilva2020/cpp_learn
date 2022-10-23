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

#define MAX_STACK_SIZE 256

typedef int stack_type;

using namespace std;

class Stack
{
private:
    /* data */
    stack_type* data; 
    /* Height of stack*/
    int height;


public:
    Stack(/* args */);
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(stack_type data);
    stack_type pop();
    int length();
    void clear();
    void print();
};

