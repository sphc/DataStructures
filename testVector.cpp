/*
 * @Author       : sphc
 * @Description  : ---
 * @Email        : jinkai0916@outlook.com
 * @Date         : 2020-09-21 10:45:37
 * @LastEditors  : sphc
 * @LastEditTime : 2020-09-26 17:33:30
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
    // std::cout << "v8.size():" << v8.size() << std::endl;

    // v8 = v8;
    // printVector(v8);
    // Vector<int> v9;
    // v9 = v8;
    // printVector(v9);

    Vector<int> v10;
    v10.insert(1);
    v10.insert(2);
    v10.insert(3);
    v10.insert(4);
    v10.insert(5);
    std::cout << "v10.disordered(): " << v10.disordered() << std::endl;
    Vector<int> v11;
    v11.insert(1);
    v11.insert(3);
    v11.insert(2);
    v11.insert(5);
    v11.insert(4);
    std::cout << "v11.disordered(): " << v11.disordered() << std::endl;
    std::cout << "v11.find(2):  " << v11.find(2) << std::endl;
    std::cout << "v11.find(20):  " << v11.find(20) << std::endl;
    std::cout << "v11.find(2, 1, 4):  " << v11.find(2, 1, 4) << std::endl;
    std::cout << "v11.find(20, 1, 4):  " << v11.find(20, 1, 4) << std::endl;
    v11.remove(2);
    // v11.remove(2, 4);
    printVector(v11);

    return 0;
}