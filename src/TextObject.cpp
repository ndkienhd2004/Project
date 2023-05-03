#include "../include/TextObject.h"


Text::Text(const char* filepath, int x, int y, int z) {
   font = TTF_OpenFont(filepath,z);
    m_texture = nullptr;
    m_position = { x, y, 0, 0 };
    m_text = "";
}


Text::~Text() {}


void Text::setText(std::string text) {
    m_text = text;

    if (m_texture) {
        SDL_DestroyTexture(m_texture);
    }

    SDL_Surface* surface = TTF_RenderText_Blended(font, m_text.c_str(), m_color);
    m_texture = SDL_CreateTextureFromSurface(Game::gRenderer, surface);
    m_position.w = surface->w;
    m_position.h = surface->h;
    SDL_FreeSurface(surface);
}
void Text::changesize(int w,int h){
    m_position.w=w;
    m_position.h=h;
}
void Text::setPoss(int x, int y){
    m_position.x=x;
    m_position.y=y;
}
void Text::setColor(int x,int y,int z){
    m_color.r=x;
    m_color.g=y;
    m_color.b=z;
}

void Text::render() {
    SDL_RenderCopy(Game::gRenderer, m_texture, NULL, &m_position);
}
