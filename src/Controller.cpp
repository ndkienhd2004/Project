#include "../include/Component/Controller.h"
#include "../include/AmoObject.h"
#include "../include/game.h"
#include "../include/GameObject.h"
#include "../include/MixerManager.h"

int Controller::index;
int Controller::lastindex = 3;
Controller::Controller(int& velocity_x, int& velocity_y)
{
    velocityx = &velocity_x;
    velocityy = &velocity_y;

}

Controller::~Controller()
{

}

void Controller::HandleEvent(SDL_Event& e)
{
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        switch(e.key.keysym.sym)
        {
        case SDLK_UP:
            index=3;
            *velocityy += -5;
            break;
        case SDLK_DOWN:
            index=4;
            *velocityy += +5;
            break;
        case SDLK_LEFT:
            index=2;
            *velocityx += -5;
            break;
        case SDLK_RIGHT:
            index=1;
            *velocityx += +5;
            break;
        }
    }

    if(e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        switch(e.key.keysym.sym)
        {
        case SDLK_UP:
            *velocityy += +5;
            break;
        case SDLK_DOWN:
            *velocityy += -5;
            break;
        case SDLK_LEFT:
            *velocityx += +5;
            break;
        case SDLK_RIGHT:
            *velocityx += -5;
            break;
        }
    }
    if(e.type== SDL_KEYDOWN){
            switch(e.key.keysym.sym)
            {
            case SDLK_a:
                MixerManager::PlaySoundEffect("laser",20);
                if(index==1||(lastindex==1&&index==0)) Game::player->getAmoVec().push_back(new AmoObject(50, 10, "asset/lazer2.png", Game::player->xpos+130, Game::player->ypos+65));
                if(index==2||(lastindex==2&&index==0)) Game::player->getAmoVec().push_back(new AmoObject(50, 10, "asset/lazer2.png", Game::player->xpos, Game::player->ypos+65));
                if(index==3||(lastindex==3&&index==0)) Game::player->getAmoVec().push_back(new AmoObject(10, 50, "asset/lazer1.png", Game::player->xpos+65, Game::player->ypos));
                if(index==4||(lastindex==4&&index==0)) Game::player->getAmoVec().push_back(new AmoObject(10, 50, "asset/lazer1.png", Game::player->xpos+65, Game::player->ypos+130));
                break;
            case SDLK_d:
                MixerManager::PlaySoundEffect("laser",20);
                if(index==1||(lastindex==1&&index==0)) Game::player->getAmoVec().push_back(new AmoObject(100, 100, "asset/rasengan.png", Game::player->xpos+130, Game::player->ypos+50));
                if(index==2||(lastindex==2&&index==0)) Game::player->getAmoVec().push_back(new AmoObject(100, 100, "asset/rasengan.png", Game::player->xpos, Game::player->ypos+50));
                if(index==3||(lastindex==3&&index==0)) Game::player->getAmoVec().push_back(new AmoObject(100, 100, "asset/rasengan.png", Game::player->xpos+50, Game::player->ypos));
                if(index==4||(lastindex==4&&index==0)) Game::player->getAmoVec().push_back(new AmoObject(100, 100, "asset/rasengan.png", Game::player->xpos+50, Game::player->ypos+130));
                break;
                    }
    }


    if(*velocityx==0&&*velocityy==0) index=0;


    if(index!=0) lastindex=index;
}
void Controller::Update()
{

}
