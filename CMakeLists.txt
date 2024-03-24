cmake_minimum_required(VERSION 3.15)
project(TetrisGame)

# Find SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add your source file here
add_executable(TetrisGame src/main.cpp)

# Link against SDL2 library
target_link_libraries(TetrisGame ${SDL2_LIBRARIES})
