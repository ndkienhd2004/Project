#include "../include/Component/Controller.h"
#include "../include/AmoObject.h"

int Controller::index;
int Controller::lastindex = 4;
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
    if(*velocityx==0&&*velocityy==0) index=0;
    if(index!=0) lastindex=index;
}
void Controller::Update()
{

}
