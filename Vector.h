/*
 * @Author       : sphc
 * @Description  : ---
 * @Email        : jinkai0916@outlook.com
 * @Date         : 2020-08-25 14:45:55
 * @LastEditors  : sphc
 * @LastEditTime : 2020-09-23 14:14:43
 */

#ifndef VECTOR__H
#define VECTOR__H

#include <utility>
#include <cassert>

inline const int DefaultCapacity = 3;

template <typename T> class Vector {
public:
    typedef int Rank;

    Vector(int c = DefaultCapacity, int s = 0, const T &v = T{});
    Vector(const T *A, Rank n);
    Vector(const T *A, Rank lo, Rank hi);
    Vector(const Vector<T> &V);
    Vector(const Vector<T> &V, Rank lo, Rank hi);
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
    Vector<T> &operator=(const Vector<T> &rhs);
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
    Rank _size;
    int _capacity;
    T *_elem;

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

template <typename T>
// T: default_constructable copy_assignable
Vector<T>::Vector(int c, int s, const T &v) :
    _size(0), _capacity(c), _elem(new T[c]) // check: size of c
{
    // assert 0 <= s && s <= c
    while (_size < s) {
        _elem[_size++] = v;
    }
}

template <typename T>
Vector<T>::Vector(const T *A, Rank n) :
    Vector(A, 0, n) { }

template <typename T>
// check: value of lo and hi
// assert lo <= hi
Vector<T>::Vector(const T *A, Rank lo, Rank hi) :
    _size(hi - lo), _capacity(_size), _elem(alloc_copy(_capacity, A, lo, hi))
{ }

template <typename T>
Vector<T>::Vector(const Vector<T> &V) :
    Vector(V, 0, V.size()) { }

template <typename T>
Vector<T>::Vector(const Vector<T> &V, Rank lo, Rank hi) :
    Vector(V._elem, lo, hi) { }

template <typename T>
Vector<T>::~Vector() { free(); }


template <typename T>
const T &Vector<T>::operator[](Rank r) const
{ return _elem[r]; }

template <typename T>
Vector<T>::Rank Vector<T>::size() const
{ return _size; }

template <typename T>
bool Vector<T>::empty() const
{ return 0 == size(); }

template <typename T>
int Vector<T>::disordered() const
{
    int rcnt = 0;
    for (Rank i = 0; i < _size - 1; ++i) {
        if (_elem[i + 1] < _elem[i]) {
            ++rcnt;
        }
    }
    return rcnt;
}

template <typename T>
Vector<T>::Rank Vector<T>::find(const T &e) const
{ return find(e, 0, _size); }

template <typename T>
Vector<T>::Rank Vector<T>::find(const T &e, Rank lo, Rank hi) const
{
    // assert 0 <= lo && lo <= hi && hi <= _size
    while (lo <= --hi && _elem[hi] != e) { }
    return hi;
}

// template <typename T>
// Vector<T>::Rank Vector<T>::search(const T &e) const;

// template <typename T>
// Vector<T>::Rank Vector<T>::search(const T &e, Rank lo, Rank hi) const;


template <typename T>
T &Vector<T>::operator[](Rank r)
{ return const_cast<T &>(const_cast<const Vector &>(*this)[r]); }

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &rhs)
{
    if (this != &rhs) {
        free();
        _capacity = _size = rhs.size();
        _elem = alloc_copy(_capacity, rhs._elem, 0, rhs.size());
    }
    return *this;
}

template <typename T>
T Vector<T>::remove(Rank r) { return remove(r, r + 1); }

template <typename T>
T Vector<T>::remove(Rank lo, Rank hi)
{
    // assert 0 <= lo && lo < hi && hi <= _size
    assert(lo < hi);
    T ret = _elem[hi - 1];
    while (hi != _size) {
        _elem[lo++] = _elem[hi++];
    }
    _size = lo;
    return ret;
}

template <typename T>
Vector<T>::Rank Vector<T>::insert(Rank r, const T &e)
{
    if (_size == _capacity) {
        _capacity *= 2;
        T *newElem = alloc_copy(_capacity, _elem, 0, _size);
        free();
        _elem = newElem;
    }
    Rank i = _size;
    while (i != r) {
        _elem[i] = _elem[i - 1];
        --i;
    }
    _elem[i] = e;
    ++_size;
    return r;
}

template <typename T>
Vector<T>::Rank Vector<T>::insert(const T &e)
{ return insert(size(), e); }

// template <typename T>
// void Vector<T>::sort(Rank lo, Rank hi);

// template <typename T>
// void Vector<T>::sort();

// template <typename T>
// void Vector<T>::unsort(Rank lo, Rank hi);

// template <typename T>
// void Vector<T>::unsort();

// template <typename T>
// int Vector<T>::deduplicate();


// template <typename T>
// int Vector<T>::uniquify();

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


template <typename T>
void Vector<T>::free() { delete [] _elem; }

template <typename T>
T *Vector<T>::alloc_copy(int capacity, const T *A, Rank lo, Rank hi)
{
    // assert 0 <= lo && lo <= hi
    T *newElem = new T[capacity];
    Rank size = 0;
    while (lo != hi) {
        newElem[size++] = A[lo++];
    }
    return newElem;
}

#endif