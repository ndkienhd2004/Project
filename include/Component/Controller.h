#pragma once
#ifndef Controller_h
#define Controller_h

#include "../game.h"

class Controller{
private:
    int* velocityx;
    int* velocityy;

public:
    Controller(int& velocity_x, int& velocity_y);
    ~Controller();
    void Update();
    void HandleEvent(SDL_Event& e);
    static int index;
    static int lastindex;



};
#endif // COntroller_h
