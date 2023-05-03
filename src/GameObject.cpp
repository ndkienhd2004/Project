#include "../include/GameObject.h"
#include "../include/texturemanager.h"
#include "../include/Component/Controller.h"


GameObject::GameObject(const char* texturesheet,int x,int y)
{
    control = new Controller(velocityX, velocityY);
    objTexture= texturemanager::Loadtexture(texturesheet);
    heartTexture = texturemanager::Loadtexture("asset/heart.png");
    xpos=x;
    ypos=y;
     down[0]={0,390,130,130};

     left[0]={390,650,130,130};
     left[1]={390,520,130,130};
     left[2]={520,390,130,130};

     right[0]={520,0,130,130};
     right[1]={390,130,130,130};
     right[2]={260,260,130,130};

     up[0]={0,0,130,130};


     mCollider = new Collider(&xpos, &ypos, 120, 120);
}
void GameObject::Update(){
    int lastx = xpos;
    int lasty = ypos;

    xpos += velocityX;
    ypos += velocityY;
    if(xpos <= 0) xpos = 0;
    if(ypos <= 0) ypos = 0;
    if(xpos + 56 >= 1280) xpos = lastx;
    if(ypos + 80 >= 720) ypos = lasty;

    if(Controller::index==1){
        currentpos=right[1];
    }
    if(Controller::index==2){
        currentpos=left[1];
    }
    if(Controller::index==3){
        currentpos=up[0];
    }
    if(Controller::index==4){
        currentpos=down[0];
    }
    if(Controller::index==0&&Controller::lastindex==1){
        currentpos=right[1];
    }
    if(Controller::index==0&&Controller::lastindex==2){
        currentpos=left[1];
    }
    if(Controller::index==0&&Controller::lastindex==3){
        currentpos=up[0];
    }
    if(Controller::index==0&&Controller::lastindex==4){
        currentpos=down[0];
    }
    if(velocityX>0&&velocityY>0){
        currentpos=right[2];
    }
    if(velocityX<0&&velocityY>0){
        currentpos=left[2];
    }
    if(velocityX<0&&velocityY<0){
        currentpos=left[0];
    }
    if(velocityX>0&&velocityY<0){
        currentpos=right[0];
    }


    destRect.x=xpos;
    destRect.y=ypos;

    destRect.w=130;
    destRect.h=130;

    mCollider->Update();


    for(auto& ar : AmoVec)
    {
        ar->Update();
    }

    for(auto& ar : AmoVec)
    {
        if(ar->destrect_.x < 0 || ar->destrect_.y < 0 || ar->destrect_.x > 1280 || ar->destrect_.y > 720) ar->destroy();
    }

    AmoVec.erase(remove_if(AmoVec.begin(), AmoVec.end(),
                    [](AmoObject* amos) {return !amos->isActive();}), AmoVec.end());
}

void GameObject::Render(){
    SDL_Rect heartSrc = {0,0,250,250};
    SDL_Rect heartDest = {0,10,30,30};
    for(int i=1;i<=hp;++i){
        heartDest.x = i*50 + 5;
        texturemanager::Draw(heartTexture, heartSrc, heartDest);
    }

    for(auto& ar : AmoVec)
    {
        ar->Render();
    }

    SDL_RenderCopy(Game::gRenderer,objTexture,&currentpos,&destRect);
}
