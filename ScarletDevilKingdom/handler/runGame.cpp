#include "runGame.h"
#include "SDL2_handler.h"

void runGame::run()
{
    SDL2_handler handler;

    handler.loadStartScreen();
    SDL_BlitSurface(handler.startScreen, nullptr, handler.surface, nullptr);
    SDL_UpdateWindowSurface(handler.window);


    // Main Game Loop
    SDL_Event event;
    bool quit = false;

    while (!quit)
    {
        // handle closing the window
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
                break;
            }

            // if key was pressed
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                        handler.updateSurface(handler.loadSurface("C:\\Users\\Legit\\Desktop\\TouhouSDK\\ScarletDevilKingdom\\assets\\test\\up.bmp"));
                        break;
                    case SDLK_DOWN:
                        handler.updateSurface(handler.loadSurface("C:\\Users\\Legit\\Desktop\\TouhouSDK\\ScarletDevilKingdom\\assets\\test\\down.bmp"));
                        break;
                    case SDLK_LEFT:
                        handler.updateSurface(handler.loadSurface("C:\\Users\\Legit\\Desktop\\TouhouSDK\\ScarletDevilKingdom\\assets\\test\\left.bmp"));
                        break;
                    case SDLK_RIGHT:
                        handler.updateSurface(handler.loadSurface("C:\\Users\\Legit\\Desktop\\TouhouSDK\\ScarletDevilKingdom\\assets\\test\\right.bmp"));
                        break;
                    default:
                        handler.updateSurface(handler.loadSurface("C:\\Users\\Legit\\Desktop\\TouhouSDK\\ScarletDevilKingdom\\assets\\test\\press.bmp"));
                        break;
                }
            }
        }
    }

    return;
}
