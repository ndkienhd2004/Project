#pragma once
#ifndef Collision_h
#define COllision_h

class Collision
{
public:
    static bool isCollide(const SDL_Rect& recta, const SDL_Rect& rectb)
    {
        if(
            recta.x + recta.w >= rectb.x &&
            rectb.x + rectb.w >= recta.x &&
            recta.y + recta.h >= rectb.y &&
            rectb.y + rectb.h >= recta.y
            ) {return true;}

        return false;
    }
};

#endif // Collision_h
