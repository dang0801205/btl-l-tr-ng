
#ifndef COMMON_H
#define COMMON_H
#include "src/include/SDL2/SDL.h"
#include "src/include/SDL2/SDL_image.h"
#include "src/include/SDL2/SDL_ttf.h"
#include <iostream>
#include <string.h>
#include <math.h>
static SDL_Window* g_window;
static SDL_Renderer* g_screen;
static SDL_Event g_event;

const int FRAME_PER_SECOND = 25;
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPT = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 0xff;

#define TILE_SIZE  64    
#define  MAX_MAP_X  400
#define   MAX_MAP_Y  10
#define BLANK_TILE 0
struct Input
{ int left_;
  int right_;
  int  up_;
  int down_;
  int jump_;
};
struct Map 
{
   int start_x_;
   int start_y_;

   int max_x_;
   int max_y_;

   int tile[MAX_MAP_Y][MAX_MAP_X];
   std::string file_name;
};
#endif




