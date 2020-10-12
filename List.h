/*
 * @Author       : sphc
 * @Description  : ---
 * @Email        : jinkai0916@outlook.com
 * @Date         : 2020-10-12 23:26:32
 * @LastEditors  : sphc
 * @LastEditTime : 2020-10-13 00:00:37
 */

#ifndef LIST__H
#define LIST__H

template <typename T> class List {
public:
    // 构造函数
    List() { init(); }
    List(const List<T> &L); // 整体复制列表L
    List(const List<T> &L, Rank r, int n); //复制列表L中自第r项起的n项
    List(ListNodePosi(T) p, int n); // 复制列表中自位置p起的n项

    // 析构函数
    ~List(); // 释放（包含头、尾结点在内的）所有结点

    // 只读访问接口
    Rank size() const { }
    bool empty() const { }
    T &operator[](Rank r) const;
    ListNodePosi(T) first() const; // 首结点位置
    ListNodePosi(T) last() const; // 末结点位置
    bool valid(ListNodePosi(T) p) const; // 判断位置p是否对外合法
    int disordered() const; // 判断列表是否已排序
    ListNodePosi(T) find(const T &e) const; // 无序列表查找
    ListNodePosi(T) find(const T &e, int n, ListNodePosi(T) p) const; // 无序列表区间查找
    ListNodePosi(T) search(const T &e) const; // 有序列表查找
    ListNodePosi(T) search(const T &e, int n, ListNodePosi(T) p) const; // 有序列表区间查找
    ListNodePosi(T) selectMax(ListNodePosi(T) p, int n) const; // 在p及其n-1个后继者中选出最大者
    ListNodePosi(T) selectMax() const; // 整体最大者

    // 可写访问接口
    ListNodePosi(T) insertAsFirst(const T &e); // 将e当作首结点插入
    ListNodePosi(T) insertAsLast(const T &e); // 将e当作末结点插入
    ListNodePosi(T) insertA(ListNodePosi(T) p, const T &e); // 将e当作p的后继插入
    ListNodePosi(T) insertB(ListNodePosi(T) p, const T &e); // 将e当作p的前驱插入
    T remove(ListNodePosi(T) p); // 删除合法位置p处的结点，返回被删除结点
    void merge(List<T> &L); // 列表归并
    void sort(ListNodePosi(T) p, int n); // 列表区间排序
    void sort(); // 列表整体排序
    int deduplicate(); // 无序去重
    int uniquify(); // 有序去重
    void reverse(); // 前后倒置

    // 遍历
    void traverse(void (*visit)(T &));
    template <typename VST> void traverse(VST &visit);
private:
    int _size;
    ListNodePosi(T) header;
    ListNodePosi(T) trailer;

    void init(); // 列表创建时的初始化
    int clear(); // 清除所有结点
    void copyNodes(ListNodePosi(T), int); // 复制列表中自位置p起的n项
    void merge(ListNodePosi(T) &, int, List<T> &, ListNodePosi(T), int); // 归并
    void mergeSort(ListNodePosi(T) &, int); // 对从p开始连续的n个结点归并排序
    void selectionSort(ListNodePosi(T), int); // 对从p开始连续的n个结点选择排序
    void insertionSort(ListNodePosi(T), int); // 对从p开始连续的n个结点插入排序
};

#endif