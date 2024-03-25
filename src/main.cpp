#include <iostream>
#include "utils/Colors.hpp"
#include "utils/CircularLL.hpp"
#include "ShapeObject.hpp"
#include "ShapeList.hpp"
#include <conio.h>


main(int argc, char* argv[]) {

    ShapeList<Object> shapeList;
    system("cls");
    shapeList.display();

    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'x') {
                break;
            } else {
                ch = _getch();

                switch (ch) {

                    case 75: // Left arrow key
                        shapeList.addRight(Object::random());
                        shapeList.removeLeft();

                        break;

                    case 77: // Right arrow key
                        shapeList.addLeft(Object::random());
                        shapeList.removeRight();

                        break;


                    case 'q':
                        shapeList.shiftColor(RED);
                        break;
                    case 'w':
                        shapeList.shiftColor(GREEN);
                        break;
                    case 'e':
                        shapeList.shiftColor(BLUE);
                        break;
                    case 'r':
                        shapeList.shiftColor(YELLOW);
                        break;
                    case 'a':
                        shapeList.shiftShape(RECTANGLE);
                        break;
                    case 's':
                        shapeList.shiftShape(CIRCLE);
                        break;
                    case 'd':
                        shapeList.shiftShape(TRIANGLE);
                        break;
                    case 'f':
                        shapeList.shiftShape(DIAMOND);
                        break;


                    default:
                        continue;
                    
                    }

                    system("cls");
                    shapeList.display();
            }
        }
    }


    return 0;
}
