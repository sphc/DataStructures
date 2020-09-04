//C++ file

//================================================
//
//      Filename: reverseI.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-06 10:22:08
// Last Modified: 2020-08-06 10:29:44
//
//================================================

#include <iostream>
#include <cstddef>

//数组倒置（迭代版）
void reverseI(int *arr, std::size_t n)
{
    if (0 == n) {
        return;
    }
    std::size_t lo = 0, hi = n - 1;
    while (lo < hi) {
        std::swap(arr[lo++], arr[hi--]);
    }
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    reverseI(arr, sizeof(arr) / sizeof(arr[0]));
    for (auto x : arr) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    return 0;
}
