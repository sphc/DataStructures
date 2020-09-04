//head file

//================================================
//
//      Filename: Vector.h
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-25 14:45:55
// Last Modified: 2020-09-04 04:34:31
//
//================================================

#ifndef VECTOR__H
#define VECTOR__H

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T> class Vector {
public:
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0);
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
    Vector<T> &operator=(const Vector<T> &);
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

#endif
