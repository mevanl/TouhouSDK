#include "SDL.h"
#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>

#pragma once
class SDL2_handler
{
public:
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    SDL_Window* window;
    SDL_Surface* surface;
    SDL_Surface* helloWorld;
    std::string SDKpath;

    SDL2_handler();
    ~SDL2_handler();
    void loadHelloWorld();
};


