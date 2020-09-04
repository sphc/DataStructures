//head file

//================================================
//
//      Filename: LinkedList.hpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-08-31 14:30:52
// Last Modified: 2020-08-31 14:30:52
//
//================================================

#ifndef LINKED_LIST__H
#define LINKED_LIST__H

template <typename T> class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;
    bool isInList(const T &obj) const;

    void addToHead(const T &obj);
    void addToTail(const T &obj);
    //删除时，链表是否为空由用户程序检查
    T deleteFromHead();
    T deleteFromTail();
    void deleteNode(const T &obj);
private:
    struct Node {
        T info;
        Node *next;

        Node() : next(nullptr) { }
        Node(const T &obj, Node *ptr = nullptr) :
            info(obj), next(ptr) { }
    };

    Node *head, *tail;
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node *p = head;
    while (p) {
        p = p->next;
        delete head;
        head = p;
    }
}

template <typename T>
bool LinkedList<T>::isEmpty() const { return nullptr == head; }

template <typename T>
bool LinkedList<T>::isInList(const T &obj) const
{
    Node *p = head;
    while (p && p->info != obj) {
        p = p->next;
    }
    return p;
}

template <typename T>
void LinkedList<T>::addToHead(const T &obj)
{
    if (isEmpty()) {
        head = tail = new Node(obj);
    } else {
        head = new Node(obj, head);
    }
}

template <typename T>
void LinkedList<T>::addToTail(const T &obj)
{
    if (isEmpty()) {
        head = tail = new Node(obj);
    } else {
        tail = tail->next = new Node(obj);
    }
}

template <typename T>
T LinkedList<T>::deleteFromHead()
{
    Node *hptr = head;
    T ret = hptr->info;
    head = head->next;
    if (hptr == tail) {
        tail = head;
    }
    delete hptr;
    return ret;
}

template <typename T>
T LinkedList<T>::deleteFromTail()
{
    Node *tptr = tail;
    T ret = tptr->info;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        Node *p = head;
        while (p->next != tail) {
            p = p->next;
        }
        tail = p;
    }
    delete tptr;
    return ret;
}

template <typename T>
void LinkedList<T>::deleteNode(const T &obj)
{
    Node **p = &head;
    while (*p && (*p)->info != obj) {
        p = &((*p)->next);
    }
    if (!*p) { return; }
    Node *q = *p;
    *p = (*p)->next;
    delete q;
    if (nullptr == head) { tail = nullptr; }
}

#endif
