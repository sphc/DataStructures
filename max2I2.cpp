//C++ file

//================================================
//
//      Filename: max2I2.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-10 14:19:00
// Last Modified: 2020-08-10 14:27:46
//
//================================================

#include <algorithm>
#include <iostream>

//从arr[lo, hi)中找出最大的两个整数arr[x1], arr[x2]
void max2I2(const int *arr, int lo, int hi, int &x1, int &x2)
{
    if (2 > hi - lo) {
        return;
    }
    x1 = lo;
    x2 = lo + 1;
    if (arr[x1] < arr[x2]) {
        std::swap(x1,  x2);
    }
    for (int i = lo + 2; i < hi; ++i) {
        if (arr[x2] < arr[i]) {
            x2 = i;
            if (arr[x1] < arr[i]) {
                std::swap(x1, x2);
            }
        }
    }
}

int main()
{
    int arr[] = { 1, 3, 9, 5, 7 };
    int x1, x2;
    max2I2(arr, 0, 5, x1, x2);
    std::cout << "x1: " << arr[x1] << ", x2: " << arr[x2] << std::endl;
    return 0;
}
