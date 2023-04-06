#pragma once
#ifndef game_h
#define game_h

#include <bits/stdc++.h>
#include <SDL.h>

class GameObject;


class Game{
public:
    Game();
    ~Game();
    bool isRunning(){return running;}
    void Initialize();
    void handling_event();
    void Update();
    void Render();
    void clean();
    static SDL_Renderer* gRenderer;
    static SDL_Event e;
    static GameObject *player;

private:
    bool running;
    SDL_Window* gWindow;
    SDL_Texture* Text;
};


#endif // game
