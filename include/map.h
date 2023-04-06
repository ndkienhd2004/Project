#pragma once
#ifndef map_h
#define map_h
#include "game.h"

class Map{
public:
    Map();
    ~Map();

    void Loadmap(int arr[20][25]);
    void Drawmap();

private:
    SDL_Rect srcMap,destMap;

    SDL_Texture* Dirt;
    SDL_Texture* Water;
    SDL_Texture* Grass;

    int mmap[20][25];


};

#endif // map_h
