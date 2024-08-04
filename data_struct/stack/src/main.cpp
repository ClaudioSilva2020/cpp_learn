/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "main.h"

using namespace std;

int main(int argc, const char* argv[])
{
    stack_type item;
    Stack newStack;
    int option;

    cout << "Type a option to control the stack \n";
    
    do
    {
        cout << " Type option 0 to stop the application";
        cout << "\n";
        cout << " Type option 1 to print the stack";
        cout << "\n";
        cout << " Type option 2 to input data at stack";
        cout << "\n";
        cout << " Type option 3 to delete data of stack";
        cout << "\n";
        cout << " Type option 4 to print size of the stack";
        cout << "\n";
        cout << " Type option 5 to clear the stack";
        cout << "\n";

        cin >> option;

        switch (option)
        {
            case 1:
            {
                newStack.print();
                break;
            }
            case 2:
            {
                cout << "Enter data: ";
                cout << "\n";
                cin >> item;
                newStack.push(item);
                break;
            }
            case 3:
            {
                newStack.pop();
                break;
            }
            case 4:
            {
                cout << "size of the stack: " << newStack.length() << "\n";
            }
            case 5:
            {
                newStack.clear();
                break;
            }
        }
        
    }while (option != 0);

}