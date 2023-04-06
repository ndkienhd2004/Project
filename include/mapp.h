#pragma once
#ifndef mapp_h
#define mapp_h

#include "game.h"
#include "texturemanager.h"
#include "ThreatsObject.h"



class mapp{
public:
    mapp(const char* sheet,int _width,int _height,int _speed);
    ~mapp();
    std::vector<ThreatsObject*>& getThreatsvec() {return ThreatsVec;}
    void Update();
    void RenderBottom();
    void RenderMiddle();
    void AddMonster(ThreatsObject* threat);

private:
    int width,height,speed;
    int offset = 0;
    SDL_Rect src1,dest1,src2,dest2;
    SDL_Texture* bkgr;
    std::vector<ThreatsObject*> ThreatsVec;
};




#endif // mapp_h
