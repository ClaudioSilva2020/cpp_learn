/**
 * @file merge_sort.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "include/merge_sort.hpp"

#include <iostream>
#include <vector>

using namespace std;

int merge_sort_object = 0;

/**
 * @brief Merge Sort
 * 
 * @param arr the array to sort
 */
MergeSort::MergeSort()
{
    merge_sort_object++;
}

MergeSort::~MergeSort()
{
    merge_sort_object--;
}

void MergeSort::merge(int *arr, int start, int end, int mid)
{
    int i, j, k, aux_arr[MAX_LENGTH_ARR];
    i = start;
    j = mid + 1;
    k = start;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            aux_arr[k] = arr[i];
            k++;
            i++;
        }else 
        {
            aux_arr[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        aux_arr[k] = arr[i];
        k++;
        j++;
    }

    while (j <= end)
    {
        aux_arr[k] = arr[j];
        k++;
        j++;
    }

    for (i = start; i < k; i++)
    {
        arr[i] = aux_arr[i];
    }

}

void MergeSort::merge_sort(int *arr, int start, int end)
{
    int mid;
    if (start < end)
    {
        //Divide the array at mid and sort independently using merge_sort
        mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        //Merge or conquer sortede arrays
        merge(arr, start, mid, end);
    }    
}



