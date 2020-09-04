//C++ file

//================================================
//
//      Filename: sum.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-06 10:33:51
// Last Modified: 2020-08-06 13:59:11
//
//================================================

#include <cstddef>
#include <iostream>

//数组求和（二分递归版）
int sum(const int *arr, std::size_t lo, std::size_t hi)
{
    if (lo == hi) {
        return arr[lo];
    }
    std::size_t mid = (lo + hi) / 2;
    return sum(arr, lo, mid) + sum(arr, mid + 1, hi);
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << sum(a, 0, 9) << std::endl;
    return 0;
}
