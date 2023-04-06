#include "../include/AmoObject.h"
#include "../include/texturemanager.h"
#include "../include/game.h"
#include "../include/Component/Controller.h"

AmoObject::AmoObject(int _width, int _height, const char* filename , int playerXPos, int playerYPos){
    srcrect_.x = srcrect_.y = 0;
    srcrect_.w = _width;
    srcrect_.h = _height;
    destrect_.x = playerXPos;
    destrect_.y = playerYPos;
    destrect_.w = srcrect_.w /2 ;
    destrect_.h = srcrect_.h /2 ;
    ObjectTexture= texturemanager::Loadtexture(filename);
    index = Controller::index;
    mCollider = new Collider(&destrect_.x, &destrect_.y,destrect_.w,destrect_.h);
}

AmoObject::~AmoObject(){

}

void AmoObject::Update(){
  destrect_.y-=10;
  mCollider->Update();
}

void AmoObject::Render(){
    SDL_RenderCopy(Game::gRenderer,ObjectTexture,&srcrect_,&destrect_);
    }
