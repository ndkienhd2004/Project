#include "../include/map.h"
#include "../include/texturemanager.h"
int lv1[20][25]={
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,2,2,2,2,2,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,2,2,2,0,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,2,2,2,2,1,2,2,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,1,2,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,1,2,2,2,2,2,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,1,2,2,1,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,1,1,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,2,1,1,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

};

Map::Map(){
    Dirt= texturemanager::Loadtexture("asset/Dirt.png");
    Grass= texturemanager::Loadtexture("asset/Grass.png");
    Water= texturemanager::Loadtexture("asset/Water.png");
    Loadmap(lv1);
    srcMap.x=0;
    srcMap.y=0;
    srcMap.w=64;
    srcMap.h=64;
    destMap.w=srcMap.w;
    destMap.h=srcMap.h;
}



void Map::Loadmap(int arr[20][25]){
    for(int row=0;row<20;++row){
            for(int col=0;col<20;++col){
                mmap[row][col]=arr[row][col];
            }
    }

}

void Map::Drawmap(){
    int type=0;
    for(int row=0;row<20;++row){
            for(int col=0;col<20;++col){
                type=mmap[row][col];
                destMap.x=col*64;
                destMap.y=row*64;

            switch(type){
            case 0:
                texturemanager::Draw(Water,srcMap,destMap);
                break;
            case 1:
                texturemanager::Draw(Dirt,srcMap,destMap);
                break;
            case 2:
                texturemanager::Draw(Grass,srcMap,destMap);
                break;
            default:
                break;
                }
            }
    }
}

