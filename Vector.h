//head file

//================================================
//
//      Filename: Vector.h
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-25 14:45:55
// Last Modified: 2020-09-09 13:01:55
//
//================================================

#ifndef VECTOR__H
#define VECTOR__H

const int DefaultCapacity = 3;

template <typename T> class Vector {
public:
    typedef int Rank;

    Vector(int c = DefaultCapacity, int s = 0, const T &v = T{});
    Vector(const T *A, Rank n);
    Vector(const T *A, Rank lo, Rank hi);
    Vector(const Vector<T> &V);
    Vector(const Vector<T> &V, Rank lo, Rank hi);
    ~Vector();

    //只读访问接口
    Rank size() const;
    bool empty() const;
    int disordered() const;
    Rank find(const T &e) const;
    Rank find(const T &e, Rank lo, Rank hi) const;
    Rank search(const T &e) const;
    Rank search(const T &e, Rank lo, Rank hi) const;

    //可写访问接口
    //T &operator[](Rank r) const;
    Vector<T> &operator=(const Vector<T> &rhs);
    T remove(Rank r);
    int remove(Rank lo, Rank hi);
    Rank insert(Rank r, const T &e);
    Rank insert(const T &e);
    void sort(Rank lo, Rank hi);
    void sort();
    void unsort(Rank lo, Rank hi);
    void unsort();
    int deduplicate();
    int uniquify();

    //遍历
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
};

template <typename T>
//T: default_constructable copy_assignable
Vector<T>::Vector(int c, int s, const T &v) :
    _capacity(c), _size(0), _elem(new T[c]) // check: size of c
{
    //assert 0 <= s && s <= c
    while (_size < s) {
        _elem[_size++] = v;
    }
}

template <typename T>
Vector<T>::Vector(const T *A, Rank n) :
    Vector(A, 0, n) { }

template <typename T>
Vector<T>::Vector(const T *A, Rank lo, Rank hi);

template <typename T>
Vector<T>::Vector(const Vector<T> &V) :
    Vector(V, 0, V.size()) { }

template <typename T>
//check: value of lo and hi
Vector<T>::Vector(const Vector<T> &V, Rank lo, Rank hi) :
    Vector(V._elem, lo, hi) { }

template <typename T>
Vector<T>::~Vector();

#endif