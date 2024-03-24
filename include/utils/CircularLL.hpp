#ifndef CIRCULARLL_HPP
#define CIRCULARLL_HPP
#include "utils/Colors.hpp"

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T value) : data(value), next(nullptr) {}

};

template <typename T>
class CircularLinkedList {
private:
    Node<T>* head;

public:
    CircularLinkedList() : head(nullptr) {}

    ~CircularLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
            if (current == head) break;
        }
    }
    
    void addLeft(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void addRight(T value) {
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
        }
    }

    
    void display() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        typeid(T);

        Node<T>* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    
        return;

    }

    void displayShapeObject() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        typeid(T);

        Node<T>* temp = head;
        do {
            int objectColor = (temp->data).getColor();
            int objectShape = (temp->data).getColor();

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
                buffer.append("\u25A0"); // ■
                break;
            case 1: // Circle
                buffer.append("\u25CF"); // ●
                break;
            case 2: // Triangle
                buffer.append("\u25B2"); // ▲
                break;
            case 3: // Diamond
                buffer.append("\u25C6"); // ◆
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
};

#endif // CIRCULARLL_HPP
