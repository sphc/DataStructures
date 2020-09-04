//C++ file

//================================================
//
//      Filename: max2R.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-10 14:28:21
// Last Modified: 2020-08-10 15:18:50
//
//================================================

#include <iostream>
#include <algorithm>

//从arr[lo, hi)中找出最大的两个整数arr[x1], arr[x2]
void max2R(const int *arr, int lo, int hi, int &x1, int &x2)
{
    if (3 < hi - lo) {
        int mid = (lo + hi) / 2;
        int x1l, x2l, x1r, x2r;
        max2R(arr, lo, mid + 1, x1l, x2l);
        max2R(arr, mid + 1, hi, x1r, x2r);
        if (arr[x1l] < arr[x1r]) {
            x1 = x1r;
            x2 = x1l < x2r ? x2r : x1l;
        } else {
            x1 = x1l;
            x2 = x1r < x2l ? x2l : x1r;
        }
    } else if (2 == hi - lo) {
        x1 = lo;
        x2 = lo + 1;
        if (arr[x1] < arr[x2]) {
            std::swap(x1, x2);
        }
    } else if (3 == hi - lo) {
        max2R(arr, lo, lo + 2, x1, x2);
        if (arr[x2] < arr[lo + 2]) {
            x2 = lo + 2;
            if (arr[x1] < arr[x2]) {
                std::swap(x1, x2);
            }
        }
    }
}

int main()
{
    int arr[] = { 1, 3, 9, 5, 7 };
    int x1, x2;
    max2R(arr, 0, 5, x1, x2);
    std::cout << "x1: " << arr[x1] << ", x2: " << arr[x2] << std::endl;
    return 0;
}
