#pragma once
#ifndef mapp_h
#define mapp_h

#include "game.h"
#include "texturemanager.h"
#include "ThreatsObject.h"
#include "SupportObject.h"


class mapp{
public:
    mapp(const char* sheet,int _width,int _height,int _speed);
    ~mapp();
    std::vector<ThreatsObject*>& getThreatsvec() {return ThreatsVec;}
    std::vector<SupportObject*>& getSpvec() {return SpVec;}
    void Update();
    void RenderBottom();
    void RenderMiddle();
    void AddMonster(ThreatsObject* threat);
    void AddSupportItem(SupportObject* sp);

private:
    int width,height,speed;
    int offset = 0;
    SDL_Rect src1,dest1,src2,dest2;
    SDL_Texture* bkgr;
    std::vector<ThreatsObject*> ThreatsVec;
    std::vector<SupportObject*> SpVec;
};




#endif // mapp_h
