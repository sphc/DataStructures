/*
 * @Author       : sphc
 * @Description  : ---
 * @Email        : jinkai0916@outlook.com
 * @Date         : 2020-08-25 14:45:55
 * @LastEditors  : sphc
 * @LastEditTime : 2020-10-12 21:38:58
 */

#ifndef VECTOR__H
#define VECTOR__H

#include <iostream>
#include <memory>
#include <algorithm>
#include <utility>
#include <cassert>
#include <cstdlib>

template <typename T, typename Allocator = std::allocator<T>>
class Vector {
public:
    typedef int Rank; // 秩

    // 构造函数 OK
    explicit Vector(int c = DefaultCapacity, int s = 0, const T &v = T{}); // 容量c、规模s、元素初始值v
    Vector(const T *A, Rank n);
    Vector(const T *A, Rank lo, Rank hi);
    Vector(Vector<T, Allocator> &&V) = delete;
    Vector(const Vector<T, Allocator> &V);
    Vector(const Vector<T, Allocator> &V, Rank lo, Rank hi);

    // 析构函数 OK
    ~Vector();

    // 只读访问接口
    // OK
    const T &operator[](Rank r) const;
    // OK
    Rank size() const;
    Rank capacity() const;
    // OK
    bool empty() const; // 返回相邻逆序元素对的总数
    // OK
    int disordered() const;
    // OK
    Rank find(const T &e) const; // 无序向量查找
    // OK
    Rank find(const T &e, Rank lo, Rank hi) const; // 无序向量查找
    Rank search(const T &e) const; // 有序向量查找
    Rank search(const T &e, Rank lo, Rank hi) const; // 有序向量查找

    // 可写访问接口
    // OK
    T &operator[](Rank r);
    Vector<T, Allocator> &operator=(Vector<T, Allocator> &&rhs) = delete;
    // OK
    Vector<T, Allocator> &operator=(const Vector<T, Allocator> &rhs);
    // OK
    T remove(Rank r);
    // OK
    int remove(Rank lo, Rank hi);
    // OK
    Rank insert(Rank r, const T &e);
    // OK
    Rank insert(const T &e); // 默认作为末元素插入
    void sort(Rank lo, Rank hi);
    // OK
    void sort();
    // OK
    void unsort(Rank lo, Rank hi);
    // OK
    void unsort();
    // OK
    int deduplicate(); // 无序向量去重
    // OK
    int uniquify(); // 有序向量去重
    void shrink();

    // 遍历 OK
    void traverse(void (*visit)(T &));
    template <typename VST> void traverse(VST &visit);
private:
    using AllocTraits = std::allocator_traits<Allocator>;
    static Allocator allocator;
    static const int DefaultCapacity; // 默认的初始容量

    Rank _size;
    int _capacity;
    T *_elem;

    // void expand();
    bool bubble(Rank lo, Rank hi); // 扫描交换
    void bubbleSort(Rank lo, Rank hi); // 起泡排序算法
    void merge(Rank lo, Rank mi, Rank hi); // 归并算法
    void mergeSort(Rank lo, Rank hi); // 归并排序算法

    Rank max(Rank lo, Rank hi); // 选取最大元素
    void selectionSort(Rank lo, Rank hi); // 选择排序算法
    Rank partition(Rank lo, Rank hi); // 轴点构造算法
    void quickSort(Rank lo, Rank hi); // 快速排序算法
    void heapSort(Rank lo, Rank hi); // 堆排序

    void free(); // 释放内部空间
    // 分配capacity的空间，并拷贝A[lo, hi)至新的空间，返回新空间的首地址
    T *alloc_copy(int capacity, const T *A, Rank lo, Rank hi);
};

template <typename T, typename Allocator>
Allocator Vector<T, Allocator>::allocator{ };

template <typename T, typename Allocator>
const int Vector<T, Allocator>::DefaultCapacity = 3;

template <typename T, typename Allocator>
// T: default_constructable copy_assignable
Vector<T, Allocator>::Vector(int c, int s, const T &v) :
    _size(s), _capacity(c), _elem(allocator.allocate(c)) // check: size of c
    // _size(0), _capacity(c), _elem(new T[c]) // check: size of c
{
    // assert 0 <= s && s <= c
    // while (_size < s) {
        // _elem[_size++] = v;
        // AllocTraits::construct(allocator, _elem + _size++, v);
    // }
    std::uninitialized_fill_n(_elem, _size, v);
}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(const T *A, Rank n) :
    Vector(A, 0, n) { }

template <typename T, typename Allocator>
// check: value of lo and hi
// assert lo <= hi
Vector<T, Allocator>::Vector(const T *A, Rank lo, Rank hi) :
    _size(hi - lo), _capacity(_size), _elem(alloc_copy(_capacity, A, lo, hi))
{ }

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(const Vector<T, Allocator> &V) :
    Vector(V, 0, V.size()) { }

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(const Vector<T, Allocator> &V, Rank lo, Rank hi) :
    Vector(V._elem, lo, hi) { }

template <typename T, typename Allocator>
Vector<T, Allocator>::~Vector() { free(); }


template <typename T, typename Allocator>
const T &Vector<T, Allocator>::operator[](Rank r) const
{ return _elem[r]; }

template <typename T, typename Allocator>
Vector<T, Allocator>::Rank Vector<T, Allocator>::size() const
{ return _size; }

template <typename T, typename Allocator>
Vector<T, Allocator>::Rank Vector<T, Allocator>::capacity() const
{ return _capacity; }

template <typename T, typename Allocator>
bool Vector<T, Allocator>::empty() const
{ return 0 == size(); }

template <typename T, typename Allocator>
int Vector<T, Allocator>::disordered() const
{
    int rcnt = 0;
    for (Rank i = 0; i < _size - 1; ++i) {
        if (_elem[i + 1] < _elem[i]) {
            ++rcnt;
        }
    }
    return rcnt;
}

template <typename T, typename Allocator>
Vector<T, Allocator>::Rank Vector<T, Allocator>::find(const T &e) const
{ return find(e, 0, _size); }

template <typename T, typename Allocator>
Vector<T, Allocator>::Rank Vector<T, Allocator>::find(const T &e, Rank lo, Rank hi) const
{
    // assert 0 <= lo && lo <= hi && hi <= _size
    while (lo <= --hi && _elem[hi] != e) { }
    return hi;
}

// template <typename T, typename Allocator>
// Vector<T, Allocator>::Rank Vector<T, Allocator>::search(const T &e) const;

// template <typename T, typename Allocator>
// Vector<T, Allocator>::Rank Vector<T, Allocator>::search(const T &e, Rank lo, Rank hi) const;


template <typename T, typename Allocator>
T &Vector<T, Allocator>::operator[](Rank r)
{ return const_cast<T &>(const_cast<const Vector &>(*this)[r]); }

template <typename T, typename Allocator>
Vector<T, Allocator> &Vector<T, Allocator>::operator=(const Vector<T, Allocator> &rhs)
{
    auto newSize = rhs.size();
    auto newElem = alloc_copy(newSize, rhs._elem, 0, rhs.size());
    free();
    _elem = newElem;
    _capacity = _size = newSize;
    return *this;
}

template <typename T, typename Allocator>
T Vector<T, Allocator>::remove(Rank r)
{
    // assert 0 <= r && r < _size
    T ret = _elem[r];
    remove(r, r + 1);
    return ret;
}

template <typename T, typename Allocator>
int Vector<T, Allocator>::remove(Rank lo, Rank hi)
{
    // assert 0 <= lo && lo <= hi && hi <= _size
    // while (hi != _size) {
    //     _elem[lo++] = _elem[hi++];
    // }
    if (lo == hi) { return 0; }
    auto last = std::copy(_elem + hi, _elem + _size, _elem + lo);
    // while (lo < _size) {
    //     AllocTraits::destroy(allocator, _elem + --_size);
    // }
    std::destroy(last, _elem + _size);
    _size = last - _elem;
    return hi - lo;
}

template <typename T, typename Allocator>
Vector<T, Allocator>::Rank Vector<T, Allocator>::insert(Rank r, const T &e)
{
    // assert 0 <= r && r <= _size
    if (_size == _capacity) {
        auto newSize = _size;
        auto newCapacity = 2 * _capacity;
        T *newElem = alloc_copy(newCapacity, _elem, 0, _size);
        free();
        _size = newSize;
        _capacity = newCapacity;
        _elem = newElem;
    }
    if (r == _size) {
        AllocTraits::construct(allocator, _elem + _size, e);
    } else {
        AllocTraits::construct(allocator, _elem + _size, T());
        // Rank i = _size;
        // while (i != r) {
        //     _elem[i] = _elem[i - 1];
        //     --i;
        // }
        std::copy_backward(_elem + r, _elem + _size, _elem + _size + 1);
        _elem[r] = e;
    }
    ++_size;
    return r;
}

template <typename T, typename Allocator>
Vector<T, Allocator>::Rank Vector<T, Allocator>::insert(const T &e)
{ return insert(_size, e); }

// 未测试
// template <typename T, typename Allocator>
// void Vector<T, Allocator>::sort(Rank lo, Rank hi);

// 未测试
template <typename T, typename Allocator>
void Vector<T, Allocator>::sort()
{ sort(0, _size); }

template <typename T, typename Allocator>
void Vector<T, Allocator>::unsort(Rank lo, Rank hi)
{
    // assert 0 <= lo && lo <= hi
    using std::swap;
    auto elems = _elem + lo;
    for (Rank i = hi - lo; 1 < i; --i) {
        swap(elems[std::rand() % i], elems[i - 1]);
    }
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::unsort()
{ unsort(0, _size); }

template <typename T, typename Allocator>
int Vector<T, Allocator>::deduplicate()
{
    auto oldSize = size();
    // for (Rank i = 0; i < size() - 1; ++i) {
    //     auto ret = find(_elem[i], i + 1, size());
    //     while (i < ret) {
    //         remove(ret);
    //         ret = find(_elem[i], i + 1, size());
    //     }
    // }
    for (Rank i = 1; i < size();) {
        if (auto ret = find(_elem[i], 0, i); -1 < ret) {
            remove(i);
        } else {
            ++i;
        }
    }
    return oldSize - size();
}

template <typename T, typename Allocator>
int Vector<T, Allocator>::uniquify()
{
    if (0 == size() || 1 == size()) { return 0; }
    Rank i = 0;
    for (Rank j = i + 1; j < size(); ++j) {
        if (_elem[j] != _elem[i]) {
            _elem[++i] = _elem[j];
        }
    }
    int cnt = _size - i - 1;
    _size = i + 1;
    std::destroy_n(_elem + _size, cnt);
    return cnt;
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::shrink()
{
    auto newSize = size();
    auto newCapacity = newSize ? newSize : 1;
    auto newElem = alloc_copy(newCapacity, _elem, 0, size());
    free();
    _elem = newElem;
    _size = newSize;
    _capacity =newCapacity;
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::traverse(void (*visit)(T &))
{
    for (Rank i = 0; i < size(); ++i) {
        visit(_elem[i]);
    }
}

template <typename T, typename Allocator>
template <typename VST>
void Vector<T, Allocator>::traverse(VST &visit)
{
    for (Rank i = 0; i < size(); ++i) {
        visit(_elem[i]);
    }
}


// void expand();
// void shrink();
// bool bubble(Rank lo, Rank hi);
// void bubbleSort(Rank lo, Rank hi);
// Rank max(Rank lo, Rank hi);
// void selectionSort(Rank lo, Rank hi);
// void merge(Rank lo, Rank mi, Rank hi);
// void mergeSort(Rank lo, Rank hi);
// Rank partition(Rank lo, Rank hi);
// void quickSort(Rank lo, Rank hi);
// void heapSort(Rank lo, Rank hi);


template <typename T, typename Allocator>
void Vector<T, Allocator>::free()
{
    // delete [] _elem;
    // while (0 < _size) {
    //     AllocTraits::destroy(allocator, _elem + --_size);
    // }
    std::destroy_n(_elem, _size);
    allocator.deallocate(_elem, _capacity);
}

template <typename T, typename Allocator>
T *Vector<T, Allocator>::alloc_copy(int capacity, const T *A, Rank lo, Rank hi)
{
    // assert 0 <= lo && lo <= hi
    // auto newElem = new T[capacity];
    auto newElem = allocator.allocate(capacity);
    // Rank size = 0;
    // while (lo != hi) {
        // newElem[size++] = A[lo++];
    //     AllocTraits::construct(allocator, newElem + size++, A[lo++]);
    // }
    std::uninitialized_copy(A + lo, A + hi, newElem);
    return newElem;
}

#endif