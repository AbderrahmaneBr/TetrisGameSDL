cmake_minimum_required(VERSION 3.15)
project(TetrisGame)

set(SOURCE_FILES src/main.cpp src/ShapeObject.cpp)

include_directories(include)

# Find SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add your source file here
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link against SDL2 library
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
