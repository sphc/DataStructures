/*
 * @Author       : sphc
 * @Description  : ---
 * @Email        : jinkai0916@outlook.com
 * @Date         : 2020-09-21 10:45:37
 * @LastEditors  : sphc
 * @LastEditTime : 2020-10-19 21:22:04
 */

#include "Test.h"
#include "Vector.h"
#include <ctime>
#include <cstdlib>

template <typename T>
void printVector(const Vector<T> &v)
{
    for (typename Vector<T>::Rank i = 0; i != v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void f(int &n) { std::cout << n << " "; }

class F {
public:
    void operator()(int n) { std::cout << n << ", "; }
};

// template <typename T>
// class AddSpace {
// public:
//     AddSpace(const T &obj) : ref(obj) { }
// private:
//     const T &ref;
// };

// template <typename T>
// std::ostream &operator<<(std::ostream &os, AddSpace<T> rhs)
// { return os << rhs.ref << ' '; }

int main()
{
    // Vector<Test> v1;
    // Vector<Test> v2(5, 3);
    // Vector<Test> v3(5, 3, Test{7});
    // v1.insert(Test{});
    // v1.insert(Test{});
    // v1.insert(Test{});
    // v1.insert(Test{});
    // v1.remove(1);
    // std::cout << v1.capacity() << std::endl;
    // v1.insert(1);
    // v1.insert(1);
    // v1.insert(1);
    // v1.insert(1);
    // v1.insert(1);
    // std::cout << v1.capacity() << std::endl;
    // v1 = 4;
    // std::cout << v1.capacity() << std::endl;
    // v1.insert(1);
    // v1.insert(1);
    // v1.insert(1);
    // v1.insert(1);
    // v1.insert(1);
    // std::cout << v1.capacity() << std::endl;

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
    //     std::cout << v8[i] << " ";
    // }
    // std::cout << std::endl;
    // printVector(v8);
    // std::cout << "v8.size():" << v8.size() << std::endl;

    // v8 = v8;
    // printVector(v8);
    // Vector<int> v9;
    // v9 = v8;
    // printVector(v9);

    // Vector<int> v10;
    // v10.insert(1);
    // v10.insert(2);
    // v10.insert(3);
    // v10.insert(4);
    // v10.insert(5);
    // std::cout << "v10.disordered(): " << v10.disordered() << std::endl;
    // Vector<int> v11;
    // v11.insert(1);
    // v11.insert(3);
    // v11.insert(2);
    // v11.insert(5);
    // v11.insert(4);
    // std::cout << "v11.disordered(): " << v11.disordered() << std::endl;
    // std::cout << "v11.find(2):  " << v11.find(2) << std::endl;
    // std::cout << "v11.find(20):  " << v11.find(20) << std::endl;
    // std::cout << "v11.find(2, 1, 4):  " << v11.find(2, 1, 4) << std::endl;
    // std::cout << "v11.find(20, 1, 4):  " << v11.find(20, 1, 4) << std::endl;
    // // v11.remove(2);
    // v11.remove(2, 4);
    // printVector(v11);

    // Vector<int> v12;
    // v12.insert(20);
    // v12.insert(10);
    // v12.insert(21);
    // v12.insert(30);
    // v12.insert(25);
    // v12.insert(15);
    // v12.insert(20);
    // v12.insert(17);
    // v12.insert(27);
    // v12.insert(20);
    // v12.insert(24);
    // v12.insert(16);
    // v12.insert(20);
    // v12.insert(17);
    // v12.insert(27);
    // v12.insert(20);
    // v12.insert(24);
    // v12.insert(16);
    // for (int i = 10; i < 35; ++i) {
    //     v12.insert(i);
    // }
    // v12.traverse(f);
    // std::cout << std::endl;
    // auto del_cnt = v12.deduplicate();
    // std::cout << "delete " << del_cnt << " element" << (1 < del_cnt ? "s." : ".") << std::endl;
    // auto fobj = F{};
    // v12.traverse(fobj);
    // std::cout << std::endl;

    // Vector<int> v13;
    // v13.insert(10);
    // v13.insert(10);
    // v13.insert(10);
    // v13.insert(11);
    // v13.insert(13);
    // v13.insert(15);
    // v13.insert(15);
    // v13.insert(15);
    // v13.insert(15);
    // v13.insert(17);
    // v13.insert(19);
    // v13.insert(21);
    // v13.insert(21);
    // v13.insert(21);
    // v13.insert(21);
    // v13.insert(21);
    // v13.insert(23);
    // v13.insert(25);
    // v13.insert(28);
    // v13.insert(33);
    // v13.insert(33);
    // v13.insert(33);
    // v13.insert(33);
    // v13.insert(35);
    // v13.insert(35);
    // v13.insert(37);
    // v13.insert(37);
    // v13.insert(39);
    // v13.insert(39);
    // v13.insert(39);
    // v13.insert(41);
    // v13.insert(50);
    // v13.insert(55);
    // v13.insert(55);
    // v13.insert(55);
    // v13.insert(61);
    // v13.traverse(f);
    // std::cout << std::endl;
    // auto del_cnt = v13.uniquify();
    // std::cout << "delete " << del_cnt << " element" << (1 < del_cnt ? "s." : ".") << std::endl;
    // auto fobj = F{};
    // v13.traverse(fobj);
    // std::cout << std::endl;

    // std::time_t t;
    // std::srand(static_cast<unsigned>(std::time(&t)));
    // Vector<int> v14;
    // v14.insert(10);
    // v14.insert(11);
    // v14.insert(13);
    // v14.insert(15);
    // v14.insert(17);
    // v14.insert(19);
    // v14.insert(21);
    // v14.insert(23);
    // v14.insert(25);
    // v14.insert(28);
    // v14.insert(33);
    // v14.insert(35);
    // v14.insert(37);
    // v14.insert(39);
    // v14.insert(41);
    // v14.insert(50);
    // v14.insert(55);
    // v14.insert(61);
    // v14.traverse(f);
    // std::cout << std::endl;
    // // v14.unsort(0, 0);
    // // v14.unsort(0, 1);
    // // v14.unsort(0, 2);
    // // v14.unsort(0, 3);
    // // v14.unsort(5, 9);
    // v14.unsort();
    // v14.traverse(f);
    // std::cout << std::endl;

    // Vector<int> v15;
    // v15.insert(10);
    // v15.insert(11);
    // v15.insert(13);
    // v15.insert(15);
    // v15.insert(17);
    // v15.insert(19);
    // v15.insert(21);
    // v15.insert(23);
    // v15.insert(25);
    // v15.insert(28);
    // v15.insert(33);
    // v15.insert(35);
    // v15.insert(37);
    // v15.insert(39);
    // v15.insert(41);
    // v15.insert(50);
    // v15.insert(55);
    // v15.insert(61);
    // std::cout << "capacity: " << v15.capacity() << ", size: " << v15.size() << std::endl;
    // v15.traverse(f);
    // std::cout << std::endl;
    // v15.shrink();
    // std::cout << "capacity: " << v15.capacity() << ", size: " << v15.size() << std::endl;
    // v15.traverse(f);
    // std::cout << std::endl;
    // v15.remove(0, v15.size());
    // std::cout << "capacity: " << v15.capacity() << ", size: " << v15.size() << std::endl;
    // v15.traverse(f);
    // std::cout << std::endl;
    // v15.shrink();
    // std::cout << "capacity: " << v15.capacity() << ", size: " << v15.size() << std::endl;
    // v15.traverse(f);
    // std::cout << std::endl;

    Vector<int> v16;
    // v16.empty(); // test [[nodiscard]]
    std::cout << "v16.search(21):" << v16.search(21) << std::endl;
    v16.insert(10);
    std::cout << "v16.search(21):" << v16.search(21) << std::endl;
    std::cout << "v16.search(10):" << v16.search(10) << std::endl;
    v16.insert(11);
    std::cout << "v16.search(21):" << v16.search(21) << std::endl;
    std::cout << "v16.search(11):" << v16.search(11) << std::endl;
    v16.insert(13);
    std::cout << "v16.search(21):" << v16.search(21) << std::endl;
    v16.insert(15);
    v16.insert(17);
    v16.insert(19);
    v16.insert(21);
    std::cout << "v16.search(21):" << v16.search(21) << std::endl;
    v16.insert(23);
    v16.insert(25);
    v16.insert(28);
    v16.insert(33);
    v16.insert(35);
    v16.insert(37);
    v16.insert(39);
    v16.insert(41);
    v16.insert(50);
    v16.insert(55);
    v16.insert(61);
    std::cout << "v16.search(21):" << v16.search(21) << std::endl;
    std::cout << "v16.search(22):" << v16.search(22) << std::endl;
    std::cout << "v16.search(21, 3, 3):" << v16.search(21, 3, 3) << std::endl;
    std::cout << "v16.search(22, 3, 3):" << v16.search(22, 3, 3) << std::endl;
    std::cout << "v16.search(21, 3, 4):" << v16.search(21, 3, 4) << std::endl;
    std::cout << "v16.search(22, 3, 4):" << v16.search(15, 3, 4) << std::endl;
    std::cout << "v16.search(21, 3, 5):" << v16.search(21, 3, 5) << std::endl;
    std::cout << "v16.search(22, 3, 5):" << v16.search(17, 3, 5) << std::endl;
    std::cout << "v16.search(21, 3, 7):" << v16.search(21, 3, 7) << std::endl;
    std::cout << "v16.search(22, 3, 7):" << v16.search(22, 3, 7) << std::endl;
    // v16.empty(); // test [[nodiscard]]

    return 0;
}
