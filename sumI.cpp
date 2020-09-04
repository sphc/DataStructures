//C++ file

//================================================
//
//      Filename: sumI.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-01 14:53:51
// Last Modified: 2020-08-05 15:11:06
//
//================================================

#include <cstddef>
#include <iostream>

//数组求和算法（迭代版）
int sumI(const int *arr, std::size_t n)
{
    int sum = 0;
    for (std::size_t i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << sumI(a, 10) << std::endl;
    return 0;
}
