#include <iostream>
#include "ShapeObject.hpp"
#include "math.h"
#include <random>

Object::Object(SHAPE _shape, COLOR _color)
{
    shape = _shape;
    color = _color;
}

SHAPE Object::getShape()
{
    return shape;
}

COLOR Object::getColor()
{
    return color;
}

void Object::setShape(SHAPE _shape)
{
    shape = _shape;
}

void Object::setColor(COLOR _color)
{
    color = _color;
}

Object* Object::random()
{
    std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist_shape(0, 3);
        std::uniform_int_distribution<std::mt19937::result_type> dist_color(0, 3);

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

        Object *obj = new Object(shape, color);

        return obj;
}