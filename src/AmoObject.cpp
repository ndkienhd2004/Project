#include "../include/AmoObject.h"
#include "../include/texturemanager.h"
#include "../include/game.h"
#include "../include/Component/Controller.h"

AmoObject::AmoObject(int _width, int _height, const char* filename , int playerXPos, int playerYPos){
      if(Controller::index!=0){
    index = Controller::index;
    }else{
    index = Controller::lastindex;
    }
    srcrect_.x = srcrect_.y = 0;
    srcrect_.w = _width;
    srcrect_.h = _height;
    destrect_.x = playerXPos;
    destrect_.y = playerYPos;
    destrect_.w = srcrect_.w /2 ;
    destrect_.h = srcrect_.h /2 ;
    ObjectTexture= texturemanager::Loadtexture(filename);


    mCollider = new Collider(&destrect_.x, &destrect_.y,destrect_.w,destrect_.h);
}

AmoObject::~AmoObject(){

}

void AmoObject::Update(){
switch(index){
    case 1:
    destrect_.x+=10;
    break;
    case 2:
    destrect_.x-=10;
    break;
    case 3:
    destrect_.y-=10;
    break;
    case 4:
    destrect_.y+=10;
    break;
}

  mCollider->Update();
}

void AmoObject::Render(){
    SDL_RenderCopy(Game::gRenderer,ObjectTexture,&srcrect_,&destrect_);
    }
