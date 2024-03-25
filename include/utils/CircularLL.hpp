#ifndef CIRCULARLL_HPP
#define CIRCULARLL_HPP

#include "ShapeObject.hpp"

template <typename T>
class Node {
public:
    T* data;
    Node<T>* next;
    Node<T>* prev;

    Node(T* value);
};

template <typename T>
class CircularLinkedList {
public:
    Node<T>* head;

    CircularLinkedList();
    ~CircularLinkedList();
    void addLeft(T* value);
    void addRight(T* value);
    void removeLeft();
    void removeRight();
    void removeNode(Node<T>* node);
    void display();
};

#endif // CIRCULARLL_HPP
