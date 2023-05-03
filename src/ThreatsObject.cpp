#include <algorithm>
#include "../include/ThreatsObject.h"
#include "../include/GameObject.h"

ThreatsObject::ThreatsObject(const char* s,int x,int y){
        objTexture=texturemanager::Loadtexture(s);
        srcRect.x=x;
        srcRect.y=y;
        srcRect.w=128;
        srcRect.h=128;
        destRect.w=60;
        destRect.h=50;
         int r=rand()%3;
         if (r == 0) {
        x_poss = rand() % 1280;
        y_poss = -50;
    } else if (r == 1) {
        x_poss = -50;
        y_poss = rand() % 720;
    } else {
        x_poss = 1280 + 50;
        y_poss = rand() % 720;
    }
        double u = Game::player->xpos - x_poss;
        double v = Game::player->ypos - y_poss;
        double t = std::max(abs(u),abs(v));

        x_val= double(u)/t*5;
        y_val= double(v)/t*5;
        destRect.x=x_poss;
        destRect.y=y_poss;
        mCollider = new Collider(&destRect.x, &destRect.y, 60, 50);
}
void ThreatsObject::Update(){
    lastposx=x_poss;
    lastposy=y_poss;
    x_poss += x_val;
    y_poss += y_val;
    destRect.x=x_poss;
    destRect.y=y_poss;
    mCollider->Update();
    if(x_poss >=1380||x_poss <=-100||y_poss>=720||y_poss<=-100) destroy();

}
void ThreatsObject::Render(){
    SDL_RenderCopy(Game::gRenderer,objTexture,&srcRect,&destRect);
}
