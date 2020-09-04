//C++ file

//================================================
//
//      Filename: ordinaryElement.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-01 14:17:32
// Last Modified: 2020-08-01 14:41:50
//
//================================================

#include <cstddef>
#include <iostream>
#include <algorithm>

//从n >= 3个互异的整数中，除最大、最小者以外，任取一个“常规元素”
int ordinaryElement(int *arr, std::size_t n)
{
    if (3 > n) {
        exit(-1);
    }
    int a = arr[0], b = arr[1], c = arr[2];
    if (a > b) {
        std::swap(a, b);
    }
    if (b > c) {
        std::swap(b, c);
    }
    if (a > b) {
        std::swap(a, b);
    }
    return b;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[7] = {3, 7, 2, 9, 100, 20, 5};
    std::cout << ordinaryElement(a, 5) << std::endl;
    std::cout << ordinaryElement(b, 7) << std::endl;
    return 0;
}
