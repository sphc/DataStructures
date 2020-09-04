//C++ file

//================================================
//
//      Filename: reverse.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-05 15:29:58
// Last Modified: 2020-08-06 10:20:13
//
//================================================

#include <cstddef>
#include <algorithm>
#include <iostream>

//数组倒置（多递归基递归版）
void reverse(int *arr, std::size_t lo, std::size_t hi)
{
    if (lo < hi) {
        std::swap(arr[lo], arr[hi]);
        reverse(arr, lo + 1, hi - 1);
    }
}

void reverse(int *arr, std::size_t n)
{
    if (n == 0) {
        return;
    }
    reverse(arr, 0, n - 1);
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    reverse(arr, sizeof(arr) / sizeof(arr[0]));
    for (auto x : arr) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    return 0;
}
