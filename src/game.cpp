#include"../include/game.h"
#include "../include/texturemanager.h"
#include "../include/GameObject.h"
#include "../include/mapp.h"
#include "../include/AmoObject.h"
#include "../include/ThreatsObject.h"
#include "../include/Collision.h"
#include "../include/TextObject.h"
#include "../include/MixerManager.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* Game::gRenderer = nullptr;
GameObject* Game::player = NULL;
SDL_Event Game::e;
mapp* mmap;
Text* scoretext;
Game::Game(){}
Game::~Game(){}
int Game::score=0;
SDL_Texture* menu;
SDL_Texture* scoremenu;
Text* bestscore;
Text* gameover;
Uint64 timeNow;
Uint64 timeStart;
Uint64 timetoheal;
Uint64 timeShield;
int index;
bool shield = false;
SDL_Texture* Shield;

void Game::Initialize(){
    running = true;
    TTF_Init();

    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        std::cout << "Subsystem initialised..." << std::endl;
    gWindow=SDL_CreateWindow("game",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1280,720,SDL_WINDOW_SHOWN);

    if(gWindow==NULL){
        std::cout << "can't create window" << SDL_GetError() << std::endl;
        running = false;
    }
    gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED||SDL_RENDERER_PRESENTVSYNC);

    if(gRenderer==NULL){
        std::cout << "can't create renderer" << SDL_GetError() << std::endl;
        running = false;
    }

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        std::cout << "SDL_image could not initialize! SDL_image Error:" << IMG_GetError() << std::endl;
        running = false;
    }

     //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error:" << Mix_GetError()<< std::endl;
        running = false;
    }

     //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        std::cout <<  "SDL_ttf could not initialize! SDL_ttf Error:" <<  TTF_GetError() << std::endl;
        running = false;
    }

    SDL_SetRenderDrawColor(gRenderer,255,255,255,255);
    }else running == false;

    srand(time(NULL));
    player = new GameObject("asset/plane.png",640,360);
    scoretext = new Text("asset/SedgwickAveDisplay-Regular.ttf",960,0,28);
    mmap = new mapp("asset/Nebula Aqua-Pink.png",1280,720,1);
    timeNow = 0;
    timetoheal=5000;
    timeStart = SDL_GetTicks64();
    timeShield=0;
    menu= texturemanager::Loadtexture("asset/startmenu.png");
    scoremenu= texturemanager::Loadtexture("asset/ScoreMenu .png");
    Shield=texturemanager::Loadtexture("asset/blueshield.png");
    MixerManager::LoadMusic("Star Wars.mp3", "StarWar");
    MixerManager::LoadSoundEffect("laser.wav","laser");
    MixerManager::LoadSoundEffect("Breast.wav","Breast");
    MixerManager::LoadSoundEffect("Barrier.wav","Barrier");
    MixerManager::LoadSoundEffect("Recovery.wav","Heal");
}

void Game::handling_event(){
    while(SDL_PollEvent(&e)!= 0)
    {
        switch(e.type)
        {
            case SDL_QUIT:
                running=false;
                printMenu=false;
                printGameOver=false;
                break;
        }
        player->getController()->HandleEvent(e);
    }
}
void Game::Update(){
   player->Update();
   mmap->Update();
   for(auto& th : mmap->getThreatsvec())
   {
       if(Collision::isCollide(player->getCollider()->colliderRect, th->getCollider()->colliderRect))
       {
           std::cout << "You lose" << std::endl;
           if(shield==false){
                player->hp--;
                MixerManager::PlaySoundEffect("Breast",20);
           }
           th->destroy();
       }
   }
     for(auto& sp : mmap->getSpvec())
   {
       if(Collision::isCollide(player->getCollider()->colliderRect, sp->getCollider()->colliderRect))
       {   if(sp->e==1){
           if(player->hp<4){
            MixerManager::PlaySoundEffect("Heal",20);
           std::cout << "You are healing" << std::endl;
           player->hp++;
       }
            }
            else{
                timeShield=SDL_GetTicks64()+5000;
                MixerManager::PlaySoundEffect("Barrier",20);
                shield=true;
            }
           sp->destroy();
       }
   }

    if(player->hp==0){ running=false;}
   for(auto& ar : player->getAmoVec())
   {
       for(auto& th : mmap->getThreatsvec())
       {
           if(Collision::isCollide(ar->getCollider()->colliderRect, th->getCollider()->colliderRect))
           {
               std::cout << "Hit monster!" << std::endl;
               MixerManager::PlaySoundEffect("Breast",20);
               score++;
               th->destroy();
               ar->destroy();
           }
       }
   }
        std::string scoreString = "Score: " + std::to_string(score);
        scoretext->setText(scoreString);
    if(SDL_GetTicks64()-timeStart <= 30000 ){
   if(SDL_GetTicks64() >= timeNow)
   {
       mmap->AddMonster(new ThreatsObject("asset/asteroid.png",0,0));
       timeNow = SDL_GetTicks64() + 500;
   }
}else{
    if(SDL_GetTicks64()-timeStart > 30000 ){
       if(SDL_GetTicks64() >= timeNow)
   {
       mmap->AddMonster(new ThreatsObject("asset/asteroid.png",0,0));
       timeNow = SDL_GetTicks64() + 200;
        }
    }
}

    if((SDL_GetTicks64()-timeStart)>timetoheal){
       mmap->AddSupportItem(new SupportObject(0,0));
       timetoheal = SDL_GetTicks64()-timeStart + 10000;
                                            }
    if(SDL_GetTicks64()>timeShield){
        shield=false;
    }
}

void Game::Render(){
    SDL_RenderClear(gRenderer);
    mmap->RenderBottom();
    mmap->RenderMiddle();
    player->Render();
    scoretext->render();
    if(shield==true){
    texturemanager::renderTexture(Shield,player->xpos,player->ypos);
    }
    SDL_RenderPresent(gRenderer);
}

void Game::clean(){
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    score=0;
    player->hp=4;
    gWindow=NULL;
    gRenderer=NULL;

}

void Game::StartMenu(){
    MixerManager::PlayMusic("StarWar",20);
    printMenu=true;
    while(printMenu==true){
        SDL_RenderCopy(gRenderer,menu,NULL,NULL);
        SDL_RenderPresent(gRenderer);
        SDL_Event e;
            SDL_PollEvent(&e);
            switch(e.type){
                case SDL_KEYDOWN:
                    switch(e.key.keysym.sym){
                        case SDLK_RETURN:
                                printMenu=false;
                                break;
                        case SDLK_ESCAPE:
                            running=false;
                            printMenu=false;
                            printGameOver=false;
                            break;
                    }
                    break;
                case SDL_QUIT:
                            running=false;
                            printMenu=false;
                            printGameOver=false;
                            break;
            }
    }

}

void Game::ScoreMenu(){
    play_again=false;
    while(printGameOver==true){
    SDL_RenderCopy(gRenderer,scoremenu,NULL,NULL);
    gameover = new Text("asset/TT Rounds Neue Trial Compressed Bold Italic.ttf",640,360,72);
    bestscore= new Text("asset/TT Rounds Neue Trial Compressed Bold Italic.ttf",640,360,72);
    std::string scoreString = "Your Score: " + std::to_string(score);
    std::string HScore;
    std::fstream myfile("highsc.txt", std::ios::in | std::ios::out);
    std::getline(myfile,HScore);
    myfile.close();

    if(score > stoi(HScore))
    {
        HScore = std::to_string(score);
    }
    std::string HighScore = "Your Best Score:" +HScore;

    std::ofstream writeFile("highsc.txt");
    writeFile << HScore;
    writeFile.close();

    bestscore->setColor(88,185,71);
    bestscore->changesize(520,120);
    bestscore->setText(HighScore);
    bestscore->setPoss(400,540);
    bestscore->render();
    gameover->setColor(88,185,71);
    gameover->changesize(520,120);
    gameover->setText(scoreString);
    gameover->setPoss(450,480);
    gameover->render();
        SDL_RenderPresent(gRenderer);
        SDL_Event e;
            SDL_PollEvent(&e);
            switch(e.type){
                case SDL_KEYDOWN:
                    switch(e.key.keysym.sym){
                        case SDLK_RETURN:
                                play_again=true;
                                printGameOver=false;
                                break;
                        case SDLK_ESCAPE:
                            running=false;
                            printGameOver=false;
                            break;
                    }
                    break;
                case SDL_QUIT:
                            running=false;
                            printGameOver=false;
                            break;
            }
    }
}





