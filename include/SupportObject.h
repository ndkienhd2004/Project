#pragma once
#ifndef SupportObject_h
#define SupportObject_h
#include "game.h"
#include "texturemanager.h"
#include "Component/Collider.h"

class SupportObject{
public:
    SupportObject(int x,int y);
    ~SupportObject();
    bool isActive() {return active;}
    void destroy() {active = false;}
    Collider* getCollider() {return mCollider;}
    void Update();
    void Render();
    int e;
private:
    Collider* mCollider;
    double x_val;
    double y_val;
    double x_poss;
    double y_poss;
    SDL_Rect srcRect,destRect;
    SDL_Texture* objTexture;
    double lastposx;
    double lastposy;
    bool active = true;
};


#endif
