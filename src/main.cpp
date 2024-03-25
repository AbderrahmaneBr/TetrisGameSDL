#include <iostream>
#include "utils/Colors.hpp"
#include "utils/CircularLL.hpp"
#include "ShapeObject.hpp"
#include "ShapeList.hpp"


main(int argc, char* argv[]) {

    ShapeList<Object> shapeList;
    shapeList.list.display();
    std::cout << std::endl;
    shapeList.shiftColor(RED);
    shapeList.list.display();

    // // Color Lists
    // CircularLinkedList<Object> ShapeObjectsListRED = shapeList.exportColor(RED);
    // CircularLinkedList<Object> ShapeObjectsListGREEN = shapeList.exportColor(GREEN);
    // CircularLinkedList<Object> ShapeObjectsListYELLOW = shapeList.exportColor(YELLOW);;
    // CircularLinkedList<Object> ShapeObjectsListBLUE = shapeList.exportColor(BLUE);

    // // Shape Lists
    // CircularLinkedList<Object> ShapeObjectsListRECTANGLE = shapeList.exportShape(RECTANGLE);
    // CircularLinkedList<Object> ShapeObjectsListTRIANGLE = shapeList.exportShape(TRIANGLE);
    // CircularLinkedList<Object> ShapeObjectsListCIRCLE = shapeList.exportShape(CIRCLE);
    // CircularLinkedList<Object> ShapeObjectsListDIAMOND = shapeList.exportShape(DIAMOND);


    return 0;
}
