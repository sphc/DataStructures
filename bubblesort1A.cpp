//C++ file

//================================================
//
//      Filename: bubblesort1A.cpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2019-08-17 13:11:11
// Last Modified: 2020-07-14 20:17:06
//
//================================================

#include <iostream>
#include <cstddef>
#include <ctime>

void swap(int &lhs, int &rhs)
{
    int tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

void myBubblesort(int *A, std::size_t n)
{
    bool sorted = false;
    for (std::size_t i = 1; !sorted && i < n; ++i) { //n-1趟扫描交换
        sorted = true;
        for (std::size_t j = 1; j < n - i + 1; ++j) { //扫描交换
            if (A[j - 1] > A[j]) {
                swap(A[j - 1], A[j]);
                sorted = false;
            }
        } 
    }
}

void bubblesort1A(int *A, std::size_t n)
{
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (std::size_t i = 1; i < n; ++i) {
            if (A[i - 1] > A[i]) {
                swap(A[i - 1], A[i]);
                sorted = false;
            }
        }
        --n;
    }
}

void test(const std::string &funName,
          void (*testFun)(int *A, std::size_t n),
          int *testData, const int TEST_SIZE = 10000)
{
    std::clock_t start = std::clock();
    testFun(testData, TEST_SIZE);
    std::clock_t end = std::clock();
    std::cout << "========================";
    std::cout << "function " << funName;
    std::cout << "========================" << std::endl;
    std::cout << "data size : " << TEST_SIZE << std::endl;;
    std::cout << "time consumption : " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
}

int main()
{
    std::srand(std::time(NULL));
    const int TEST_SIZE = 100000;
    int *a = new int[TEST_SIZE];
    int *b = new int[TEST_SIZE];
    for (std::size_t j = 0; j < 20; ++j) {
        for (std::size_t i = 0; i < TEST_SIZE; ++i) {
            b[i] = a[i] = rand();
        }
        test("myBubblesort", myBubblesort, b, TEST_SIZE);
        test("bubblesort1A", bubblesort1A, a, TEST_SIZE);
        std::cout << std::endl;
    }
    return 0;
}
