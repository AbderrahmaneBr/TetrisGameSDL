cmake_minimum_required(VERSION 3.15)
project(TetrisGame)

set(SOURCE_FILES src/main.cpp src/ShapeObject.cpp src/CircularLL.cpp src/ShapeList.cpp)

include_directories(include)

# Add your source file here
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
