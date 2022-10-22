/**
 * @file merge_sort.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

#define MAX_LENGTH_ARR 50

class MergeSort 
{
    public:
        int *arr;
        int start;
        int end;
    public:

        // Constructor
        MergeSort();
        ~MergeSort();

        // Functions

        /**
         * @brief Merge sort function. this function gets a desorted list and Divide the list.
         * 
         * @param arr  Array of desorted elements
         * @param start the start index
         * @param end  the end index
         */
        
        void merge_sort(int *arr, int start, int end);
        /**
         * @brief This function gets a divided list and sort list
         * 
         * @param arr Array of desorted elements
         * @param start The start index
         * @param end The end index
         * @param mid The mid index
         */
        void merge(int *arr, int start, int end, int mid);
    
};