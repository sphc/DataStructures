//C++ file

//================================================
//
//      Filename: fibBR.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-06 13:28:10
// Last Modified: 2020-08-06 13:36:05
//
//================================================

#include <iostream>
#include <cstddef>

//计算Fibonacci数列的第n项（二分递归版）：O(2^n)
long long fibBR(std::size_t n)
{ return 2u > n ? n : fibBR(n - 1) + fibBR(n - 2); }

int main()
{
    std::cout << fibBR(10) << std::endl;
    return 0;
}
