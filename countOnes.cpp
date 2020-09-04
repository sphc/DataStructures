//C++ file

//================================================
//
//      Filename: countOnes.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-01 14:45:03
// Last Modified: 2020-08-01 14:48:44
//
//================================================

#include <iostream>

//统计整数二进制展开中数位1的总数
int countOnes(unsigned n)
{
    int cnt = 0;
    while (n) {
        cnt += n % 2;
        n /= 2;
    }
    return cnt;
}

int main()
{
    std::cout << countOnes(2) << std::endl;
    std::cout << countOnes(3) << std::endl;
    std::cout << countOnes(441) << std::endl;
    std::cout << countOnes(1024) << std::endl;
    return 0;
}
