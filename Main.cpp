#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

#include "include/Game.hpp"

Game *game;

int main()
{

    const int FPS = 60;
    const int framedelay = 1000 / FPS;

    Uint32 framestart;
    int    frameTime;

    game = new Game;
    game->init("swagEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

    while (game->running())
    {

        framestart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();


        frameTime = SDL_GetTicks() - framestart;

        if(framedelay > frameTime)
        {
            SDL_Delay(framedelay - frameTime);
        }

    }

    return 0;
   
}