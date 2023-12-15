#include "runGame.h"
#include "SDL2_handler.h"

void runGame::run()
{
    SDL2_handler handler;

    handler.loadHelloWorld();
    SDL_BlitSurface(handler.helloWorld, nullptr, handler.surface, nullptr);
    SDL_UpdateWindowSurface(handler.window);
    SDL_Event e; bool quit = false; while(!quit){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } } // SDL_POLLEVENT USES A TON OF RESOURCES!!!

    return;
}
