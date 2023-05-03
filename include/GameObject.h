#pragma once
#ifndef GameObject_h
#define GameObject_h
#include "game.h"
#include <bits/stdc++.h>
#include "Component/Controller.h"
#include <vector>
#include <memory>
#include <algorithm>
#include "AmoObject.h"
#include "Component/Collider.h"

class GameObject{
public:
    GameObject(const char* texturesheet, int x, int y);
    ~GameObject();
    Controller* getController() {return control;}
    std::vector<AmoObject*>& getAmoVec() {return AmoVec;}
    Collider* getCollider() {return mCollider;}
    void Update();
    void Render();
    int xpos;
    int ypos;
    int hp=4;
private:
    Collider* mCollider;
    SDL_Rect currentpos;
    SDL_Rect left[3];
    SDL_Rect right[3];
    SDL_Rect up[1];
    SDL_Rect down[1];
    int speed=100;
    int velocityX = 0;
    int velocityY = 0;
    Controller* control;
    SDL_Texture* objTexture;
    SDL_Texture* heartTexture;
    SDL_Rect srcRect,destRect;
    std::vector<AmoObject*> AmoVec;

};


#endif // GameObject_h
