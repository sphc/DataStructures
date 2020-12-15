/*
 * @Author       : sphc
 * @Description  : ---
 * @Email        : jinkai0916@outlook.com
 * @Date         : 2020-09-09 23:51:13
 * @LastEditors  : sphc
 * @LastEditTime : 2020-12-15 13:14:24
 */
//C++ file

#include <span>
#include <iostream>

// //求A、B最长公共子序列的长度
// int LCSR(const char *A, int lenA, const char *B, int lenB)
// {
//     if (lenA < 1 || lenB < 1) {
//         return 0;
//     }
//     if (A[lenA - 1] == B[lenB - 1]) {
//         return LCSR(A, lenA - 1, B, lenB - 1) + 1;
//     } else {
//         int ret1 = LCSR(A, lenA - 1, B, lenB);
//         int ret2 = LCSR(A, lenA, B, lenB - 1);
//         return ret1 < ret2 ? ret2 : ret1;
//     }
// }

// int main()
// {
//     char a[] = "asymptotic";
//     char b[] = "spot";
//     std::cout << LCSR(a, 10, b, 4) << std::endl;
//     return 0;
// }

//求A、B最长公共子序列的长度
int LCSR(std::span<const char> A, std::span<const char> B)
{
    auto lenA = A.size();
    auto lenB = B.size();
    if (lenA < 1 || lenB < 1) { return 0; }
    auto subA = A.subspan(0, lenA - 1);
    auto subB = B.subspan(0, lenB - 1);
    if (A[lenA - 1] == B[lenB - 1]) {
        return LCSR(subA, subB) + 1;
    } else {
        int ret1{LCSR(subA, B)};
        int ret2{LCSR(A, subB)};
        return ret1 < ret2 ? ret2 : ret1;
    }
}

int main()
{
    char a[]{"asymptotic"};
    char b[]{"spot"};
    std::span<const char> aspan{a};
    std::span<const char> bspan{b};
    std::cout << LCSR(aspan.subspan(0, aspan.size() - 1), bspan.subspan(0, bspan.size() - 1)) << std::endl;
    return 0;
}
