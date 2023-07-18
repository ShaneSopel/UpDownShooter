#include "Game.hpp"

class Map
{
public:

    Map();
    ~Map();

    void LoadMap(int arr[20][25]);
    void DrawMap();

private:

    SDL_Rect src;
    SDL_Rect dest;

    SDL_Texture* space;
    SDL_Texture* objects;
    SDL_Texture* things;

    int map[20][25];
    

};