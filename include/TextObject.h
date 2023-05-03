#pragma once
#ifndef TextObject_h
#define TextObject_h
#include "game.h"
#include <bits/stdc++.h>
#include <SDL_ttf.h>

class Text {
public:
    Text(const char* filepath, int x, int y,int z);
    ~Text();

    void setText(std::string text);
    void render();
    void changesize(int x, int y);
    void setPoss(int x,int y);
    void setColor(int x,int y,int z);
private:
    TTF_Font* font;
    SDL_Color m_color = { 255, 255, 255, 255 };
    SDL_Texture* m_texture;
    SDL_Rect m_position;
    std::string m_text;
};








#endif // TextObject_h
