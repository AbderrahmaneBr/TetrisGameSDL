#ifndef SHAPELIST_HPP
#define SHAPELIST_HPP
#include "utils/CircularLL.hpp"
#include "ShapeObject.hpp"
#include "math.h"
#include <random>

template <typename T>
class ShapeList
{
public:
    CircularLinkedList<Object> list;

    ShapeList() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist_shape(0, 3);
        std::uniform_int_distribution<std::mt19937::result_type> dist_color(0, 3);

        for (int i = 0; i < 6; i++) {
            COLOR color;
            SHAPE shape;

            switch (dist_color(rng)) {
            case 0:
                color = RED;
                break;
            case 1:
                color = GREEN;
                break;
            case 2:
                color = BLUE;
                break;
            case 3:
                color = YELLOW;
                break;
            }

            switch (dist_shape(rng)) {
            case 0:
                shape = RECTANGLE;
                break;
            case 1:
                shape = CIRCLE;
                break;
            case 2:
                shape = TRIANGLE;
                break;
            case 3:
                shape = DIAMOND;
                break;
            }

            list.addRight(Object(shape, color));
        }

    }

    CircularLinkedList<Object>* exportColor(COLOR color) {
        Node<Object>* temp = list.head;
        CircularLinkedList<Object>* result = new CircularLinkedList<Object>();

        do {
            if ((temp->data).getColor() == color) {
                result->addRight(temp->data);
            }
            temp = temp->next;
        } while (temp != list.head);

        return result;
    }

    CircularLinkedList<Object> exportShape(SHAPE shape) {
        Node<Object>* temp = list.head;
        CircularLinkedList<Object> result;

        do {
            if ((temp->data).getShape() == shape) {
                result.addRight(temp->data);
            }
            temp = temp->next;
        } while (temp != list.head);

        return result;
    }

    void shiftColor(COLOR targetColor) {
        CircularLinkedList<Object> *ShapeListRed = exportColor(RED);
        Node<Object>* temp = ShapeListRed->head;
        (temp->data).setShape(RECTANGLE);
        
    }



};

#endif
