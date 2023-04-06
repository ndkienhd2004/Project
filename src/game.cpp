#include"../include/game.h"
#include "../include/texturemanager.h"
#include "../include/GameObject.h"
#include "../include/mapp.h"
#include "../include/AmoObject.h"
#include "../include/ThreatsObject.h"
#include "../include/Collision.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* Game::gRenderer = nullptr;
GameObject* Game::player = NULL;
SDL_Event Game::e;
mapp* mmap;

Game::Game(){}
Game::~Game(){}

Uint64 timeNow;

void Game::Initialize(){
    running = true;

    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        std::cout << "Subsystem initialised..." << std::endl;
    gWindow=SDL_CreateWindow("game",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1280,720,SDL_WINDOW_SHOWN);

    if(gWindow==NULL){
        std::cout << "can't create window" << SDL_GetError() << std::endl;
        running = false;
    }
    gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED||SDL_RENDERER_PRESENTVSYNC);

    if(gRenderer==NULL){
        std::cout << "can't create renderer" << SDL_GetError() << std::endl;
        running = false;
    }

    SDL_SetRenderDrawColor(gRenderer,255,255,255,255);
    }else running == false;\

    srand(time(NULL));
    player = new GameObject("asset/spaceshooter.png",640,360);
    mmap = new mapp("asset/Nebula Blue.png",1280,720,1);
    timeNow = 0;

}

void Game::handling_event(){
    while(SDL_PollEvent(&e)!= 0)
    {
        switch(e.type)
        {
            case SDL_QUIT:
                running=false;
                break;
            case SDL_KEYDOWN:
                    switch(e.key.keysym.sym)
                    {
                    case SDLK_a:
                        player->getAmoVec().push_back(new AmoObject(10, 50, "asset/lazer.png", player->xpos+16, player->ypos));
                        break;
                    case SDLK_d:
                        player->getAmoVec().push_back(new AmoObject(100, 100, "asset/rasengan.png", player->xpos+16, player->ypos));
                        break;
                    }
        }
        player->getController()->HandleEvent(e);
    }
}
void Game::Update(){
   player->Update();
   mmap->Update();
   for(auto& th : mmap->getThreatsvec())
   {
       if(Collision::isCollide(player->getCollider()->colliderRect, th->getCollider()->colliderRect))
       {
           std::cout << "You lose" << std::endl;
           player->hp--;
           th->destroy();
       }
   }

   for(auto& ar : player->getAmoVec())
   {
       for(auto& th : mmap->getThreatsvec())
       {
           if(Collision::isCollide(ar->getCollider()->colliderRect, th->getCollider()->colliderRect))
           {
               std::cout << "Hit monster!" << std::endl;
               th->destroy();
               ar->destroy();
           }
       }
   }

   if(SDL_GetTicks64() >= timeNow)
   {
       mmap->AddMonster(new ThreatsObject("asset/actor1.png",32,32));
       timeNow = SDL_GetTicks64() + 500;
   }
}


void Game::Render(){
    SDL_RenderClear(gRenderer);
    mmap->RenderBottom();
    mmap->RenderMiddle();
    player->Render();
    SDL_RenderPresent(gRenderer);
}

void Game::clean(){
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    gWindow=NULL;
    gRenderer=NULL;
}
