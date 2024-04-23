# pragma once
#ifndef GAME_MAP_H
#define GAME_MAP_H
#define MAX_TILE 20
#include "CommonFunc.h"
#include "Baseobject.h"

class TileMat : public BaseObject
{
    public:
   TileMat(){;}
   ~TileMat(){;}
};
class GameMap
{
public:
    GameMap(){;}
    ~GameMap(){;}

    void LoadMap(std::string path);
    void LoadTiles(SDL_Renderer* screen);
    void DrawMap(SDL_Renderer* screen);
    Map getMap() const{return game_map_;};
    void SetMap(Map& map_data) {game_map_ = map_data;};
    //void ShowNPC(SDL_Renderer* des);
protected:
     Map game_map_;
     TileMat tile_mat[MAX_TILE];
}; 
#endif