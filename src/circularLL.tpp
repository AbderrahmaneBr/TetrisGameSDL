#include <iostream>
#include "utils/circularLL.hpp"


template <class T>
Node<T>::Node(T value) {
    data = value;
    next = nullptr;
}

template <class T>
CircularLinkedList<T>::CircularLinkedList() {
    head = nullptr;
}

template <class T>
CircularLinkedList<T>::~CircularLinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
        if (current == head) break;
    }
}

template <class T>
void CircularLinkedList<T>::insertAtBeginning(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node<T>* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

template <class T>
void CircularLinkedList<T>::display() {
    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Node<T>* temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    std::cout << std::endl;
}
