#include "../include/mapp.h"


mapp::mapp(const char* sheet,int _width,int _height,int _speed){
    bkgr=texturemanager::Loadtexture(sheet);
    width=_width;
    height=_height;
    speed=_speed;
    src1.x=src2.x=src1.y=dest1.x=dest2.x=dest2.y=0;
    src1.w=src2.w=width;
    dest1.w=dest2.w=1280;
}
void mapp::Update(){
    ThreatsVec.erase(remove_if(ThreatsVec.begin(), ThreatsVec.end(),
                    [](ThreatsObject* threats) {return !threats->isActive();}), ThreatsVec.end());
    SpVec.erase(remove_if(SpVec.begin(), SpVec.end(),
                    [](SupportObject* Sp) {return !Sp->isActive();}), SpVec.end());

    if(dest1.y>=720){
        dest1.y=0;
        offset = 0;
    }
    offset += speed;
    dest1.y = offset;
    src2.y=height-offset;
    src2.h=offset;
    src1.h=height-offset;
    dest1.h=(src1.h*720)/height;
    dest2.h=(src2.h*720)/height;

    for(auto& ar : ThreatsVec)
    {
        ar->Update();
    }

    for(auto& ar : SpVec){
        ar->Update();
    }


}
void mapp::RenderBottom(){

    SDL_RenderCopy(Game::gRenderer,bkgr,&src1,&dest1);
    SDL_RenderCopy(Game::gRenderer,bkgr,&src2,&dest2);
}
void mapp::RenderMiddle(){
    for(auto& ar : ThreatsVec)
    {
        ar->Render();
    }
    for(auto& ar : SpVec)
    {
        ar->Render();

    }
}

void mapp::AddMonster(ThreatsObject* threat)
{
    ThreatsVec.push_back(threat);
}

void mapp::AddSupportItem(SupportObject* Sp)
{
    SpVec.push_back(Sp);

}

