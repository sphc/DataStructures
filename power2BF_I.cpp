//C++ file

//================================================
//
//      Filename: power2BF_I.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-01 15:06:37
// Last Modified: 2020-08-05 16:09:05
//
//================================================

#include <cstddef>
#include <iostream>

//幂函数2^n算法（蛮力迭代版）， n >= 0
long long power2BF_I(std::size_t n)
{
    long long result = 1;
    while (n--) {
        result *= 2;
    }
    return result;
}

int main()
{
    std::cout << power2BF_I(5) << std::endl;
    std::cout << power2BF_I(10) << std::endl;
    std::cout << power2BF_I(40) << std::endl;
    return 0;
}
