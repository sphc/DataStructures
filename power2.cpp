//C++ file

//================================================
//
//      Filename: power2.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-05 15:51:13
// Last Modified: 2020-08-06 10:20:58
//
//================================================

#include <cstddef>
#include <iostream>
#include <algorithm>

//幂函数2^n算法（优化递归版），n >= 0
long long power2(std::size_t n)
{
    if (0 == n) {
        return 1;
    }
    long long tmp = power2(n / 2);
    long long tmp_sqr = tmp * tmp;
    return n % 2 ? tmp_sqr * 2 : tmp_sqr;
}

int main()
{
    std::cout << power2(5) << std::endl;
    std::cout << power2(10) << std::endl;
    std::cout << power2(40) << std::endl;
    return 0;
}
