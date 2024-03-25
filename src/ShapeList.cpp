#include <iostream>
#include "ShapeList.hpp"
#include "utils/CircularLL.hpp"
#include "ShapeObject.hpp"

template <typename T>
ShapeList<T>::ShapeList() {
    // Creating 6 Objects and Adding them to list
    score = 0;

    list.addRight(Object::random());
    list.addRight(Object::random());
    list.addRight(Object::random());
    list.addRight(Object::random());
    list.addRight(Object::random());
    list.addRight(Object::random());

}

template <typename T>
CircularLinkedList<Object>* ShapeList<T>::exportColor(COLOR color) {
    Node<Object>* temp = list.head;
    CircularLinkedList<Object>* result = new CircularLinkedList<Object>();

    int ctr=0;

    do {
        if ((temp->data)->getColor() == color) {
            result->addRight(temp->data);
            ctr++;
        }
        temp = temp->next;
    } while (temp != list.head);

    if(!ctr) return nullptr;
    return result;
}

template <typename T>
CircularLinkedList<Object>* ShapeList<T>::exportShape(SHAPE shape) {
    Node<Object>* temp = list.head;
    CircularLinkedList<Object>* result = new CircularLinkedList<Object>();
    int ctr=0;

    do {
        if ((temp->data)->getShape() == shape) {
            result->addRight(temp->data);
            ctr++;
        }
        temp = temp->next;
    } while (temp != list.head);

    if(!ctr) return nullptr;
    return result;
}

template <typename T>
void ShapeList<T>::checkIdenticalShapes() {
    // Add Bonus to score when 3 objects with the same shape, 3 objects with the same color are next to each other
    Node<Object>* temp = list.head;

    do {
        Node<Object>* obj1 = temp;
        Node<Object>* obj2 = temp->next;
        Node<Object>* obj3 = temp->next->next;

        if((obj1->data->getColor() == obj2->data->getColor() && obj2->data->getColor() == obj3->data->getColor()) || 
            (obj1->data->getShape() == obj2->data->getShape() && obj2->data->getShape() == obj3->data->getShape()))
        {
            // Remove Duplicates
            list.removeNode(obj1);
            list.removeNode(obj2);
            list.removeNode(obj3);

            // Add 3 Objects as replacement
            addRight(Object::random());
            addRight(Object::random());
            addRight(Object::random());

            // Increment Score
            score++;

            break;
        }
        
        temp = temp->next;

    } while(temp->next->next->next != list.head);
}

template <typename T>
void ShapeList<T>::addLeft(Object* obj) {
    list.addLeft(obj);
}

template <typename T>
void ShapeList<T>::addRight(Object* obj) {
    list.addRight(obj);
}

template <typename T>
void ShapeList<T>::removeLeft() {
    list.removeLeft();
}

template <typename T>
void ShapeList<T>::removeRight() {
    list.removeRight();
}

template <typename T>
void ShapeList<T>::display() {
    std::cout << "List: ";
    list.display();
    std::cout << std::endl << "Score: " << score;
}

template <typename T>
void ShapeList<T>::shiftColor(COLOR targetColor) {
    CircularLinkedList<Object> *ShapeList = exportColor(targetColor);

    if(ShapeList == nullptr) {
        return;
    }

    Node<Object>* temp = ShapeList->head;
    SHAPE prevShape = temp->prev->data->getShape();
    SHAPE currShape;
    do {
        currShape = temp->data->getShape();
        temp->data->setShape(prevShape);
        prevShape = currShape;
        temp = temp->next;
    } while(temp != ShapeList->head);
}

template <typename T>
void ShapeList<T>::shiftShape(SHAPE targetShape) {
    CircularLinkedList<Object> *ShapeList = exportShape(targetShape);

    if(ShapeList == nullptr) {
        return;
    }

    Node<Object>* temp = ShapeList->head;
    COLOR prevShape = temp->prev->data->getColor();
    COLOR currShape;
    do {
        currShape = temp->data->getColor();
        temp->data->setColor(prevShape);
        prevShape = currShape;
        temp = temp->next;
    } while(temp != ShapeList->head);
}

// Explicit instantiation for ShapeList<Object>
template class ShapeList<Object>;
