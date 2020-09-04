//C++ file

//================================================
//
//      Filename: fibI.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-06 13:51:43
// Last Modified: 2020-08-06 13:56:14
//
//================================================

#include <cstddef>
#include <iostream>

//计算Fibonacci数列的第n项（迭代版）：O(n)
long long fibI(std::size_t n)
{
    long long prev = 1, cur = 0;
    while (n--) {
        cur += prev;
        prev = cur - prev;
    }
    return cur;
}

int main()
{
    std::cout << fibI(10) << std::endl;
    return 0;
}
