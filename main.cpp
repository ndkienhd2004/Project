#include "include/Game.h"


int main(int argc, char* agrs[]){
    const int FPS=60;
    const int frameDelay= 1000/FPS;

    Uint32 frameStart;
    int frameTime;
    t:
        Game* game = new Game();
        game->Initialize();
        game->StartMenu();
            while(game->isRunning()){
                frameStart=SDL_GetTicks();

                game->handling_event();
                game->Update();
                game->Render();

                frameTime = SDL_GetTicks() - frameStart;
                if(frameDelay>frameTime) SDL_Delay(frameDelay-frameTime);
            }
        game->ScoreMenu();
        if(game->play_again== true){
                 game->clean();
                delete game;
                goto t;
        }else{
        game->clean();
        delete game;
        return 0;
}
}
