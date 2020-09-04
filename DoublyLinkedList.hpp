//head file

//================================================
//
//      Filename: DoublyLinkedList.hpp
//
//        Author: sphc - jinkai0916@outlook.com
//   Description: ---
//       Created: 2020-09-03 07:10:58
// Last Modified: 2020-09-03 07:10:58
//
//================================================

#ifndef DOUBLY_LINKED_LIST__H
#define DOUBLY_LINKED_LIST__H

template <typename T> class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

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
        Node *prev;
        Node *next;

        Node() : prev(nullptr), next(nullptr) { }
        Node(const T &obj, Node *p = nullptr, Node *n = nullptr) :
            info(obj), prev(p), next(n) { }
    };

    Node *head, *tail;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) { }

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (head) {
        Node *p = head;
        head = head->next;
        delete p;
    }
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const { return nullptr == head; }

template <typename T>
bool DoublyLinkedList<T>::isInList(const T &obj) const
{
}

template <typename T>
void DoublyLinkedList<T>::addToHead(const T &obj)
{
    if (isEmpty()) {
        head = tail = new Node(obj);
        return;
    }
    head = head->prev = new Node(obj, nullptr, head);
}

template <typename T>
void DoublyLinkedList<T>::addToTail(const T &obj)
{
    if (isEmpty()) {
        head = tail = new Node(obj);
        return;
    }
    tail = tail->next = new Node(obj, tail);
}

template <typename T>
T DoublyLinkedList<T>::deleteFromHead()
{
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }
    head = head->next;
    delete head->prev;
    head->prev = nullptr;
}

template <typename T>
T DoublyLinkedList<T>::deleteFromTail()
{
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::deleteNode(const T &obj)
{
    Node *p = head;
    while (p && p->info != obj) {
        p = p->next;
    }
    if (!p) { return; }
    if (head == tail) {
        delete p;
        head = tail = nullptr;
        return;
    }
    if (p == head) {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    } else if (p == tail) {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    } else {
        Node *q = p->prev;
        q->next = p->next;
        p->next->prev = q;
        delete p;
    }
}

#endif
