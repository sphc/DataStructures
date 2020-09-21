/*
 * @Author       : sphc
 * @Description  : ---
 * @Email        : jinkai0916@outlook.com
 * @Date         : 2020-09-21 10:45:37
 * @LastEditors  : sphc
 * @LastEditTime : 2020-09-21 14:22:54
 */

#include "Test.h"
#include "Vector.h"

template <typename T>
void printVector(const Vector<T> &v)
{
    for (typename Vector<T>::Rank i = 0; i != v.size(); ++i) {
        std::cout << v[i] << std::endl;
    }
}

int main()
{
    // Vector<Test> v1;
    // Vector<Test> v2(5, 3);
    // Vector<Test> v3(5, 3, Test{7});

    // const int Size = 5;
    // Test arr[Size];
    // Vector<Test> v4(arr, Size);
    // Vector<Test> v5(arr, 1, 4);
    // Vector<Test> v6(v5);
    // Vector<Test> v7(v5, 2, 3);

    // Vector<int> v8;
    // for (int i = 0; i < 5; ++i) {
    //     v8.insert(i);
    // }
    // v8[2] = 10;
    // v8.insert(2, 20);
    // v8.insert(2, 30);
    // for (Vector<int>::Rank i = 0; i != v8.size(); ++i) {
    //     std::cout << v8[i] << std::endl;
    // }
    // printVector(v8);
    // std::cout << v8.size() << std::endl;

    return 0;
}