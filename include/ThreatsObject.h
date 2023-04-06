#pragma once
#ifndef ThreatsObject_h
#define ThreatsObject_h
#include "game.h"
#include "texturemanager.h"
#include "Component/Collider.h"

class ThreatsObject{
public:
    ThreatsObject(const char* s,int x,int y);
    ~ThreatsObject();
    bool isActive() {return active;}
    void destroy() {active = false;}
    Collider* getCollider() {return mCollider;}
    void Update();
    void Render();
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


#endif // ThreatsObject_h
