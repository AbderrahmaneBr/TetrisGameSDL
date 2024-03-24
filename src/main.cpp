#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "utils/CircularLL.hpp"
#include "ShapeObject.hpp"

extern "C" int SDL_main(int argc, char* argv[]) {
    
    // Create a circular singly linked list of Shape Objects
    CircularLinkedList<Object> list;
    Object obj1(RECTANGLE, RED);
    Object obj2(TRIANGLE, BLUE);
    Object obj3(CIRCLE, YELLOW);
    Object obj4(DIAMOND, RED);
    Object obj5(CIRCLE, GREEN);

    list.addRight(obj1);
    list.addRight(obj2);
    list.addRight(obj3);
    list.addRight(obj4);
    // list.addRight(obj5);

    list.displayShapeObject();
    list.addRight(obj5);
    std::cout << std::endl;
    list.displayShapeObject();


    // SDL_Init(SDL_INIT_VIDEO);

    // SDL_Window* window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    // if (!window) {
    //     SDL_Log("Failed to create window: %s", SDL_GetError());
    //     return 1;
    // }

    // SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // if (!renderer) {
    //     SDL_Log("Failed to create renderer: %s", SDL_GetError());
    //     return 1;
    // }

    // SDL_Rect rect = { 100, 100, 200, 200 };
    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    // SDL_RenderFillRect(renderer, &rect);
    // SDL_RenderPresent(renderer);

    // SDL_Delay(5000);

    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();

    return 0;
}
