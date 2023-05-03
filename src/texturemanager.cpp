#include "../include/texturemanager.h"
#include"../include/game.h"

SDL_Texture* texturemanager:: Loadtexture(const char* text){

    SDL_Surface* chrter = IMG_Load(text);
    if(chrter == NULL){
        std::cout << "texture error:" << IMG_GetError() << std::endl;
}
    SDL_Texture* tex= SDL_CreateTextureFromSurface(Game::gRenderer,chrter);
    SDL_FreeSurface(chrter);
    return tex;
}
void texturemanager::Draw(SDL_Texture* Tex,SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(Game::gRenderer, Tex, &src , &dest);
}
void texturemanager::renderTexture(SDL_Texture* texture, int x, int y)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(Game::gRenderer, texture, NULL, &dest);
}
