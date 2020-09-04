//C++ file

//================================================
//
//      Filename: sumR.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-05 15:07:17
// Last Modified: 2020-08-06 10:18:13
//
//================================================

#include <cstddef>
#include <iostream>

//数组求和算法（线性递归版）
int sumR(const int *arr, std::size_t n)
{
    if (0 == n) {
        return 0;
    }
    return arr[n - 1] + sumR(arr, n - 1);
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << sumR(a, 10) << std::endl;
    return 0;
}
