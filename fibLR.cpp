//C++ file

//================================================
//
//      Filename: fibLR.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-06 13:37:27
// Last Modified: 2020-08-06 14:49:06
//
//================================================

#include <cstddef>
#include <iostream>

//计算Fibonacci数列第n项（线性递归版）
std::pair<long long, long long> _fibLR(std::size_t n)
{
    if (0 == n) {
        return {1, 0};
    }
    auto [prevPrev, prev] = _fibLR(n - 1);
    return {prev, prev + prevPrev};
}

long long fibLR(std::size_t n) { return _fibLR(n).second; }

int main()
{
    std::cout << fibLR(10) << std::endl;
    return 0;
}
