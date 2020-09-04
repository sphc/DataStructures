//C++ file

//================================================
//
//      Filename: LCSI.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-11 12:06:12
// Last Modified: 2020-08-11 12:17:49
//
//================================================

#include <iostream>

//求A、B最长公共子序列的长度
int LCSI(const char *A, int lenA, const char *B, int lenB)
{
    int dp[100][100];
    for (int i = 0; i < 100; ++i) {
        dp[i][0] = dp[0][i] = 0;
    }
    for (int i = 1; i <= lenA; ++i) {
        for (int j = 1; j <= lenB; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][ j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j] < dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j];
            }
        }
    }
    return dp[lenA][lenB];
}

int main()
{
    char a[] = "asymptotic";
    char b[] = "spot";
    std::cout << LCSI(a, 10, b, 4) << std::endl;
    return 0;
}
