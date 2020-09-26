/*
 * @Author       : sphc
 * @Description  : ---
 * @Email        : jinkai0916@outlook.com
 * @Date         : 2020-08-25 14:45:55
 * @LastEditors  : sphc
 * @LastEditTime : 2020-09-26 17:31:51
 */

#ifndef VECTOR__H
#define VECTOR__H

#include <iostream>
#include <memory>
#include <utility>
#include <cassert>

inline const int DefaultCapacity = 3;

template <typename T, typename Allocator = std::allocator<T>>
class Vector {
public:
    typedef int Rank;

    Vector(int c = DefaultCapacity, int s = 0, const T &v = T{});
    Vector(const T *A, Rank n);
    Vector(const T *A, Rank lo, Rank hi);
    Vector(const Vector<T, Allocator> &V);
    Vector(const Vector<T, Allocator> &V, Rank lo, Rank hi);
    ~Vector();

    // 只读访问接口
    const T &operator[](Rank r) const;
    Rank size() const;
    bool empty() const;
    int disordered() const;
    Rank find(const T &e) const;
    Rank find(const T &e, Rank lo, Rank hi) const;
    Rank search(const T &e) const;
    Rank search(const T &e, Rank lo, Rank hi) const;

    // 可写访问接口
    T &operator[](Rank r);
    Vector<T, Allocator> &operator=(const Vector<T, Allocator> &rhs);
    T remove(Rank r);
    T remove(Rank lo, Rank hi);
    Rank insert(Rank r, const T &e);
    Rank insert(const T &e);
    void sort(Rank lo, Rank hi);
    void sort();
    void unsort(Rank lo, Rank hi);
    void unsort();
    int deduplicate();
    int uniquify();

    // 遍历
    void traverse(void(*)(T&));
    template <typename VST> void traverse(VST &);
private:
    using AllocTraits = std::allocator_traits<Allocator>;
    Rank _size;
    int _capacity;
    T *_elem;
    Allocator allocator;

    void copyFrom(const T *A, Rank lo, Rank hi);
    void expand();
    void shrink();
    bool bubble(Rank lo, Rank hi);
    void bubbleSort(Rank lo, Rank hi);
    Rank max(Rank lo, Rank hi);
    void selectionSort(Rank lo, Rank hi);
    void merge(Rank lo, Rank mi, Rank hi);
    void mergeSort(Rank lo, Rank hi);
    Rank partition(Rank lo, Rank hi);
    void quickSort(Rank lo, Rank hi);
    void heapSort(Rank lo, Rank hi);

    void free();
    T *alloc_copy(int capacity, const T *A, Rank lo, Rank hi);
};

template <typename T, typename Allocator>
// T: default_constructable copy_assignable
Vector<T, Allocator>::Vector(int c, int s, const T &v) :
    _size(0), _capacity(c), _elem(allocator.allocate(c)) // check: size of c
    // _size(0), _capacity(c), _elem(new T[c]) // check: size of c
{
    // assert 0 <= s && s <= c
    while (_size < s) {
        // _elem[_size++] = v;
        AllocTraits::construct(allocator, _elem + _size++, v);
    }
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
T Vector<T, Allocator>::remove(Rank r) { return remove(r, r + 1); }

template <typename T, typename Allocator>
T Vector<T, Allocator>::remove(Rank lo, Rank hi)
{
    // assert 0 <= lo && lo < hi && hi <= _size
    assert(lo < hi);
    T ret = _elem[hi - 1];
    while (hi != _size) {
        _elem[lo++] = _elem[hi++];
    }
    // _size = lo;
    while (lo < _size) {
        AllocTraits::destroy(allocator, _elem + --_size);
    }
    return ret;
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
    Rank i = _size;
    AllocTraits::construct(allocator, _elem + _size, T());
    while (i != r) {
        _elem[i] = _elem[i - 1];
        --i;
    }
    _elem[i] = e;
    ++_size;
    return r;
}

template <typename T, typename Allocator>
Vector<T, Allocator>::Rank Vector<T, Allocator>::insert(const T &e)
{ return insert(size(), e); }

// template <typename T, typename Allocator>
// void Vector<T, Allocator>::sort(Rank lo, Rank hi);

// template <typename T, typename Allocator>
// void Vector<T, Allocator>::sort();

// template <typename T, typename Allocator>
// void Vector<T, Allocator>::unsort(Rank lo, Rank hi);

// template <typename T, typename Allocator>
// void Vector<T, Allocator>::unsort();

// template <typename T, typename Allocator>
// int Vector<T, Allocator>::deduplicate();


// template <typename T, typename Allocator>
// int Vector<T, Allocator>::uniquify();

// void traverse(void(*)(T&));
// template <typename VST> void traverse(VST &);


// void copyFrom(const T *A, Rank lo, Rank hi);
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
    while (0 < _size) {
        AllocTraits::destroy(allocator, _elem + --_size);
    }
    allocator.deallocate(_elem, _capacity);
}

template <typename T, typename Allocator>
T *Vector<T, Allocator>::alloc_copy(int capacity, const T *A, Rank lo, Rank hi)
{
    // assert 0 <= lo && lo <= hi
    // auto newElem = new T[capacity];
    auto newElem = allocator.allocate(capacity);
    Rank size = 0;
    while (lo != hi) {
        // newElem[size++] = A[lo++];
        AllocTraits::construct(allocator, newElem + size++, A[lo++]);
    }
    return newElem;
}

#endif