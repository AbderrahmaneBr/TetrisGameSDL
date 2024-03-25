#include <iostream>
#include "utils/CircularLL.hpp"
#include "ShapeObject.hpp"
#include "ShapeList.hpp"

template <typename T>
ShapeList::ShapeList()
{
    // Creating 6 Objects and Adding them to list
    list.addRight(Object::random());
    list.addRight(Object::random());
    list.addRight(Object::random());
    list.addRight(Object::random());
    list.addRight(Object::random());
    list.addRight(Object::random());
}

