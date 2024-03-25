#ifndef SHAPELIST_HPP
#define SHAPELIST_HPP
#include "utils/CircularLL.hpp"
#include "ShapeObject.hpp"

template <typename T>
class ShapeList
{
public:
    CircularLinkedList<Object> list;

    ShapeList() {
        // Creating 6 Objects and Adding them to list
        list.addRight(Object::random());
        list.addRight(Object::random());
        list.addRight(Object::random());
        list.addRight(Object::random());
        list.addRight(Object::random());
        list.addRight(Object::random());

    }

    CircularLinkedList<Object>* exportColor(COLOR color) {
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

    CircularLinkedList<Object>* exportShape(SHAPE shape) {
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

    void addLeft(Object* obj){
        list.addLeft(obj);
    };

    void addRight(Object* obj){
        list.addRight(obj);
    };

    void removeLeft(){
        list.removeLeft();
    }

    void removeRight(){
        list.removeRight();
    }

    void display(){
        list.display();
    }

    void shiftColor(COLOR targetColor) {
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

    void shiftShape(SHAPE targetShape) {
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





};

#endif
