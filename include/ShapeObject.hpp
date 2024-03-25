#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "utils/Enums.hpp"

class Object {
private:
    COLOR color;
    SHAPE shape;
public:
    Object(SHAPE, COLOR);
    void setColor(COLOR);
    void setShape(SHAPE);
    SHAPE getShape();
    COLOR getColor();
    static Object* random();
};

#endif