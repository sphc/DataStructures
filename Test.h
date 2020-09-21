/*
 * @Author       : sphc
 * @Description  : ---
 * @Email        : jinkai0916@outlook.com
 * @Date         : 2020-09-21 10:48:41
 * @LastEditors  : sphc
 * @LastEditTime : 2020-09-21 11:13:18
 */

#ifndef TEST__H
#define TEST__H

#include <iostream>

class Test {
public:
    Test() { std::cout << "Test()" << std::endl; }
    Test(int a) { std::cout << "Test(int)" << std::endl; }
    Test(const Test &obj) { std::cout << "Test(const Test &)" << std::endl; }
    Test(Test &&obj) { std::cout << "Test(Test &&)" << std::endl; }
    ~Test() { std::cout << "~Test()" << std::endl;}

    Test &operator=(const Test &rhs) { std::cout << "operator=(const Test &)" << std::endl; return *this; }
    Test &operator=(Test &&rhs) { std::cout << "operator=(Test &&)" << std::endl; return *this; }
};

#endif