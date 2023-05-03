#pragma once
#ifndef Collider_h
#define Collider_h

#include <SDL.h>

class Collider
{
public:
    Collider(int* x, int* y, int w, int h);
    ~Collider();
    void Update()
    {
        colliderRect = {*xpos,*ypos,width,height};
    }
    SDL_Rect colliderRect;
private:
    int *xpos;
    int *ypos;
    int width;
    int height;
};

#endif // Collider_h
