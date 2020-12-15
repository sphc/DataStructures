/*
 * @Author       : sphc
 * @Description  : ---
 * @Email        : jinkai0916@outlook.com
 * @Date         : 2019-08-17 13:11:11
 * @LastEditors  : sphc
 * @LastEditTime : 2020-12-15 12:31:40
 */

#include <span>
#include <ctime>
#include <cstddef>
#include <iostream>
#include <algorithm>

void swap(int &lhs, int &rhs)
{
    int tmp{lhs};
    lhs = rhs;
    rhs = tmp;
}

// void myBubblesort(int *A, std::size_t n)
// {
//     bool sorted = false;
//     for (std::size_t i = 1; !sorted && i < n; ++i) { //n-1趟扫描交换
//         sorted = true;
//         for (std::size_t j = 1; j < n - i + 1; ++j) { //扫描交换
//             if (A[j - 1] > A[j]) {
//                 swap(A[j - 1], A[j]);
//                 sorted = false;
//             }
//         }
//     }
// }

// void bubblesort1A(int *A, std::size_t n)
// {
//     bool sorted = false;
//     while (!sorted) {
//         sorted = true;
//         for (std::size_t i = 1; i < n; ++i) {
//             if (A[i - 1] > A[i]) {
//                 swap(A[i - 1], A[i]);
//                 sorted = false;
//             }
//         }
//         --n;
//     }
// }

// void test(const std::string &funName,
//           void (*testFun)(int *A, std::size_t n),
//           int *testData, const int TEST_SIZE = 10000)
// {
//     std::clock_t start = std::clock();
//     testFun(testData, TEST_SIZE);
//     std::clock_t end = std::clock();
//     std::cout << "========================";
//     std::cout << "function " << funName;
//     std::cout << "========================" << std::endl;
//     std::cout << "data size : " << TEST_SIZE << std::endl;;
//     std::cout << "time consumption : " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
// }

// int main()
// {
//     std::srand(std::time(NULL));
//     const int TEST_SIZE = 100000;
//     int *a = new int[TEST_SIZE];
//     int *b = new int[TEST_SIZE];
//     for (std::size_t j = 0; j < 20; ++j) {
//         for (std::size_t i = 0; i < TEST_SIZE; ++i) {
//             b[i] = a[i] = rand();
//         }
//         test("myBubblesort", myBubblesort, b, TEST_SIZE);
//         test("bubblesort1A", bubblesort1A, a, TEST_SIZE);
//         std::cout << std::endl;
//     }
//     return 0;
// }

void myBubblesort(std::span<int> items)
{
    bool sorted{false};
    for (decltype(items.size()) i{1}; !sorted && i < items.size(); ++i) { //n-1趟扫描交换
        sorted = true;
        for (decltype(items.size()) j{1}; j < items.size() - i + 1; ++j) { //扫描交换
            if (items[j] < items[j - 1]) {
                swap(items[j - 1], items[j]);
                sorted = false;
            }
        }
    }
}

void bubblesort1A(std::span<int> items)
{
    auto n = items.size();
    bool sorted{false};
    while (!sorted) {
        sorted = true;
        for (decltype(n) i{1}; i < n; ++i) {
            if (items[i] < items[i - 1]) {
                swap(items[i - 1], items[i]);
                sorted = false;
            }
        }
        --n;
    }
}

void test(const std::string &funName,
          void (*testFun)(std::span<int>),
          std::span<int> testData)
{
    std::clock_t start = std::clock();
    testFun(testData);
    std::clock_t end = std::clock();
    std::cout << "========================";
    std::cout << "function " << funName;
    std::cout << "========================" << std::endl;
    std::cout << "data size : " << testData.size() << std::endl;;
    std::cout << "time consumption : " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
}

int main()
{
    std::srand(std::time(NULL));
    constexpr std::size_t TEST_SIZE = 100000;
    std::array<int, TEST_SIZE> a;
    std::array<int, TEST_SIZE> b;
    for (std::size_t j = 0; j < 20; ++j) {
        auto assignRandomNumber = [] (auto &item) { item = rand(); };
        std::for_each(std::begin(a), std::end(a), assignRandomNumber);
        std::for_each(std::begin(b), std::end(b), assignRandomNumber);
        test("myBubblesort", myBubblesort, b);
        test("bubblesort1A", bubblesort1A, a);
        std::cout << std::endl;
    }
    return 0;
}