#include "SDL2_handler.h"

SDL2_handler::SDL2_handler()
{

    window = nullptr;
    surface = nullptr;
    startScreen = nullptr;

    // Get Parent Directory
    std::filesystem::path cur_path = std::filesystem::current_path();
    SDKpath = cur_path.parent_path().string(); // This is TouhouSDK

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError();
        exit(1);
    }

    window = SDL_CreateWindow("Touhou: ScarletDevilKingdom",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << "SDL window could not be created! SDL_Error: " << SDL_GetError();
        exit(2);
    }

    surface = SDL_GetWindowSurface(window);
}

SDL2_handler::~SDL2_handler()
{
    SDL_FreeSurface(surface);
    surface = nullptr;
    SDL_FreeSurface(startScreen);
    startScreen = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;
    //SDL_DestroyRenderer();
    SDL_Quit();
}

void SDL2_handler::loadStartScreen()
{
    std::string assetPath = SDKpath + "\\ScarletDevilKingdom\\assets\\test\\press.bmp";
    startScreen = SDL_LoadBMP(assetPath.c_str());

    if (startScreen == nullptr)
    {
        std::cout << "SDL surface helloWorld could not be loaded! SDL_Error: " << SDL_GetError();
    }
}

SDL_Surface* SDL2_handler::loadSurface(char* path)
{
    SDL_Surface* loadedSurface = SDL_LoadBMP(path);

    return loadedSurface;
}

void SDL2_handler::updateSurface(SDL_Surface* newSurface)
{
    SDL_BlitSurface(newSurface, nullptr, surface, nullptr);
    SDL_UpdateWindowSurface(window);
}