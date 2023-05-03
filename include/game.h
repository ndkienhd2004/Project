#pragma once
#ifndef game_h
#define game_h

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

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
    static int score;
    void StartMenu();
    void updateScore();
    void ScoreMenu();
    bool play_again;
private:
    bool printMenu= true;
    bool printGameOver=true;
    bool running;
    SDL_Window* gWindow;
};


#endif // game
