#include "Game.hpp"
#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject* player;
GameObject* enemy;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialized!...." << std::endl;
        window = SDL_CreateWindow(title, xpos,ypos,width,height,flags);
        if(window)
        {
            std::cout << "Window Created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {  
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            std::cout << "renderer Created" << std::endl;
        }
        
        isRunning = true;
    }

    player = new GameObject("./../assets/triangle.png", 0, 0);
    enemy  = new GameObject("./../assets/glow_frame.png", 50, 50);
}

void Game::handleEvents()
{

    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        
        default:
            break;

    }

}

void Game::update()
{
   player->Update();
   enemy->Update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);

}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

bool Game::running()
{
    return isRunning;
}