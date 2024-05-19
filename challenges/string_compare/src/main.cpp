#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

string compare_string(string arrStr[], int arrLength)
{
    int strlen = arrStr[0].length(); 
    int index_arr;
    for (int i = 0; i < arrLength; i++)
    {
        if (arrStr[i].length() < strlen)
        {
            strlen = arrStr[i].length();
            index_arr = i;
        }   
    }

    return arrStr[index_arr];
}

int main ()
{
    string arrStr[] = {"adcadcadca", "ascdcadar", "aadads", "adcad", "addscad"};
    int arrLength = sizeof(arrStr) / sizeof(*arrStr);

    cout << compare_string(arrStr, arrLength) << endl;
    return 0;
}