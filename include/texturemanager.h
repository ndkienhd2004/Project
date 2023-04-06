#pragma once
#ifndef texture_h
#define texture_h

#include<bits/stdc++.h>
#include<SDL_image.h>

class texturemanager{
public:
    static SDL_Texture* Loadtexture(const char* filename);
    static void  Draw(SDL_Texture* Tex, SDL_Rect src, SDL_Rect dest);


};

#endif // texture
