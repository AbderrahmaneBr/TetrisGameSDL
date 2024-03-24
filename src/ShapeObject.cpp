#include <iostream>
#include "ShapeObject.hpp"

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