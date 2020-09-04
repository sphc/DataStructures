//C++ file

//================================================
//
//      Filename: LCSR.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-11 11:07:23
// Last Modified: 2020-08-11 12:06:01
//
//================================================

#include <iostream>

//求A、B最长公共子序列的长度
int LCSR(const char *A, int lenA, const char *B, int lenB)
{
    if (lenA < 1 || lenB < 1) {
        return 0;
    }
    if (A[lenA - 1] == B[lenB - 1]) {
        return LCSR(A, lenA - 1, B, lenB - 1) + 1;
    } else {
        int ret1 = LCSR(A, lenA - 1, B, lenB);
        int ret2 = LCSR(A, lenA, B, lenB - 1);
        return ret1 < ret2 ? ret2 : ret1;
    }
}

int main()
{
    char a[] = "asymptotic";
    char b[] = "spot";
    std::cout << LCSR(a, 10, b, 4) << std::endl;
    return 0;
}
