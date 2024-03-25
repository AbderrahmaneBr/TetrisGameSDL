#include <iostream>
#include "utils/Colors.hpp"
#include "utils/CircularLL.hpp"

template <typename T>
Node<T>::Node(T* value) : data(value), next(nullptr), prev(nullptr) {}

template <typename T>
CircularLinkedList<T>::CircularLinkedList() : head(nullptr) {}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
        if (current == head) break;
    }
}

template <typename T>
void CircularLinkedList<T>::addLeft(T* value) {
    Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node<T>* last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
            head = newNode; // Update the head to the new node (in order to start displaying from it)
        }
}

template <typename T>
void CircularLinkedList<T>::addRight(T* value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node<T>* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;

    }
}

template <typename T>
void CircularLinkedList<T>::removeLeft() {
    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node<T>* last = head->prev;
    Node<T>* newHead = head->next;
    if (head == last) {
        delete head;
        head = nullptr;
    } else {
        last->next = newHead;
        newHead->prev = last;
        delete head;
        head = newHead;
    }
}

template <typename T>
void CircularLinkedList<T>::removeRight() {
    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node<T>* last = head->prev;
    Node<T>* newLast = last->prev;
    if (head == last) {
        delete head;
        head = nullptr;
    } else {
        newLast->next = head;
        head->prev = newLast;

    }
}

template <typename T>
void CircularLinkedList<T>::removeNode(Node<T>* node) {
    if (node == nullptr) {
        return;
    }

    if (node == head) {
        // Special case if node is the head
        if (head->next == head) {
            // If there's only one node in the list
            delete head;
            head = nullptr;
        } else {
            Node<T>* last = head->prev;
            head = head->next;
            last->next = head;
            head->prev = last;
            delete node;
        }
    } else {
        // Regular case for nodes that are not the head
        Node<T>* prevNode = node->prev;
        Node<T>* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete node;
    }
}


template <typename T>
void CircularLinkedList<T>::display() {
    if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

    Node<T>* temp = head;
    do {
        int objectColor = (temp->data)->getColor();
        int objectShape = (temp->data)->getShape();

        std::string buffer;
        switch (objectColor)
        {
        case 0:
            buffer.append(RED_PAINT);
            break;
        case 1:
            buffer.append(GREEN_PAINT);
            break;
        case 2:
            buffer.append(BLUE_PAINT);
            break;
        case 3:
            buffer.append(YELLOW_PAINT);
            break;
        
        default:
            break;
        }

        switch (objectShape)
        {
        case 0: // Rectangle
            buffer.append("■"); // ■
            break;
        case 1: // Circle
            buffer.append("●"); // ●
            break;
        case 2: // Triangle
            buffer.append("▲"); // ▲
            break;
        case 3: // Diamond
            buffer.append("◆"); // ◆
            break;
        
        default:
            break;
        }

        buffer.append(PAINT_END); // Closing Style

        std::cout << buffer << " ";

        temp = temp->next;
    } while (temp != head);

    return;
}

template class CircularLinkedList<Object>;