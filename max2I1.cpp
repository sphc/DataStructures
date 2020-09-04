//C++ file

//================================================
//
//      Filename: max2I1.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-10 14:00:19
// Last Modified: 2020-08-10 14:17:21
//
//================================================

#include <iostream>

//从arr[lo, hi)中找出最大的两个整数arr[x1], arr[x2]
void max2I1(const int *arr, int lo, int hi, int &x1, int &x2)
{
    if (2 > hi - lo) {
        return;
    }
    x2 = x1 = lo;
    for (int i = lo + 1; i < hi; ++i) {
        if (arr[x1] < arr[i]) {
            x1 = i;
        }
    }
    if (x1 == lo) {
        x2 = x1 + 1;
    }
    for (int i = lo; i < x1; ++i) {
        if (arr[x2] < arr[i]) {
            x2 = i;
        }
    }
    for (int i = x1 + 1; i < hi; ++i) {
        if (arr[x2] < arr[i]) {
            x2 = i;
        }
    }
}

int main()
{
    int arr[] = { 1, 3, 9, 5, 7 };
    int x1, x2;
    max2I1(arr, 0, 5, x1, x2);
    std::cout << "x1: " << arr[x1] << ", x2: " << arr[x2] << std::endl;
    return 0;
}
