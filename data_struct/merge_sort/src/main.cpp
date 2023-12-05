/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "main.hpp"
#include "merge_sort.hpp"

int main()
{
    
    int myarray[30], num;
    cout<<"Enter number of elements to be sorted:";
    cin>>num;
    cout<<"Enter "<<num<<" elements to be sorted:";

    MergeSort mymerge;

    mymerge.merge_sort(myarray, 0, num+1);


    return 0;
}
