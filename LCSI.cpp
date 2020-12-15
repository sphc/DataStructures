/*
 * @Author       : sphc
 * @Description  : ---
 * @Email        : jinkai0916@outlook.com
 * @Date         : 2020-08-11 12:06:12
 * @LastEditors  : sphc
 * @LastEditTime : 2020-12-15 13:13:54
 */

#include <span>
#include <array>
#include <iostream>

// //求A、B最长公共子序列的长度
// int LCSI(const char *A, int lenA, const char *B, int lenB)
// {
//     int dp[100][100];
//     for (int i = 0; i < 100; ++i) {
//         dp[i][0] = dp[0][i] = 0;
//     }
//     for (int i = 1; i <= lenA; ++i) {
//         for (int j = 1; j <= lenB; ++j) {
//             if (A[i - 1] == B[j - 1]) {
//                 dp[i][j] = dp[i - 1][ j - 1] + 1;
//             } else {
//                 dp[i][j] = dp[i - 1][j] < dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j];
//             }
//         }
//     }
//     return dp[lenA][lenB];
// }

// int main()
// {
//     char a[] = "asymptotic";
//     char b[] = "spot";
//     std::cout << LCSI(a, 10, b, 4) << std::endl;
//     return 0;
// }

//求A、B最长公共子序列的长度
int LCSI(std::span<const char> A, std::span<const char> B)
{
    std::array<std::array<int, 100>, 100> dp;
    for (decltype(dp.size()) i{0}; i < dp.size(); ++i) {
        dp[i][0] = dp[0][i] = 0;
    }
    for (decltype(A.size()) i{1}; i <= A.size(); ++i) {
        for (decltype(B.size()) j{1}; j <= B.size(); ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][ j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j] < dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j];
            }
        }
    }
    return dp[A.size()][B.size()];
}

int main()
{
    char a[]{"asymptotic"};
    char b[]{"spot"};
    std::span<const char> aspan{a};
    std::span<const char> bspan{b};
    std::cout << LCSI(aspan.subspan(0, aspan.size() - 1), bspan.subspan(0, bspan.size() - 1)) << std::endl;
    return 0;
}