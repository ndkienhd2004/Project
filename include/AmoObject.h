#pragma once
#ifndef AmoObject_h
#define AmoObject_h

#define WIDTH_AMO_LASER 35
#define HEIGHT_AMO_LASER 5
#define WIDTH_AMO_SPHERE 10
#define HEIGHT_AMO_SPHERE 10
#include "game.h"
#include <memory>
#include <algorithm>
#include "Component/Collider.h"

class AmoObject{
public:
    AmoObject(int _width, int _height, const char* filename , int playerXPos, int playerYPos);
    ~AmoObject();
    void Update();
    void Render();
    SDL_Rect srcrect_,destrect_;
    Collider* getCollider() {return mCollider;}
    bool isActive() {return active;}
    void destroy() {active = false;}
private:
    int index;
    bool active = true;
    SDL_Texture* ObjectTexture;
    Collider* mCollider;
};
#endif
