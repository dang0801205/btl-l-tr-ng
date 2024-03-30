
#include "Baseobject.h"
#include "CommonFunc.h"
#include "game_map.h"
#include "ImpTimer.h"
#include "MainObject.h"
#include "BulletObject.h"
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

Uint32 frameStart;
int frameTime;
BaseObject layer1, layer2, layer3;
MainObject p_player;
bool InitData()
{
	bool success = true;
	int ret = SDL_Init(SDL_INIT_VIDEO);
	if(ret < 0){
		return false;
	}

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");

	g_window = SDL_CreateWindow("Game v1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!g_window){
		success = false;
	}
    else
	{
    g_screen =  SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
    if(!g_screen){
		success = false;
	}
	else{
		SDL_SetRenderDrawColor(g_screen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
	}
	}
  return success;
}
void LoadAndStretchLayers(SDL_Renderer* renderer, BaseObject& layer1, BaseObject& layer2, BaseObject& layer3, int screenWidth, int screenHeight) {
    
    layer1.LoadImg("img/background_layer_1.png", renderer);
    layer2.LoadImg("img/background_layer2.png", renderer);
    layer3.LoadImg("img/background_layer3.png", renderer);

  
    layer1.rect_.w = SCREEN_WIDTH;
    layer1.rect_.h = SCREEN_HEIGHT;

    layer2.rect_.w = SCREEN_WIDTH;
    layer2.rect_.h = SCREEN_HEIGHT;

    layer3.rect_.w = SCREEN_WIDTH;
    layer3.rect_.h = SCREEN_HEIGHT;
}
void close()
{
	layer1.Free();
  layer2.Free();
  layer3.Free();
	SDL_DestroyRenderer(g_screen);
	g_screen = NULL;
	SDL_DestroyWindow(g_window);
	g_window=NULL;
	IMG_Quit();
	SDL_Quit();
}
 int main(int argc, char* argv[]) {
    if (InitData() == false)
        return -1;
    p_player.LoadImg("img/r.png", g_screen);
    p_player.set_clips();
    GameMap game_map;
    game_map.LoadMap("map/map01.dat");
    game_map.LoadTiles(g_screen);

    LoadAndStretchLayers(g_screen, layer1, layer2, layer3, SCREEN_WIDTH, SCREEN_HEIGHT);

    bool is_quit = false;
    Uint32 frameStart;
    int frameTime;

    while (!is_quit) {
        frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&g_event) != 0) {
            if (g_event.type == SDL_QUIT) {
                is_quit = true;
            }
            p_player.HandleInputAction(g_event, g_screen);
        }

        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);

        layer1.Render(g_screen);
        layer2.Render(g_screen);
        layer3.Render(g_screen);

        game_map.DrawMap(g_screen);
        Map map_data = game_map.getMap();
    
        
        p_player.SetMapXY(map_data.start_x_,map_data.start_y_);
        p_player.DoPlayer(map_data);
        p_player.Show(g_screen);
        p_player.HandleBullet(g_screen);
        
        SDL_RenderPresent(g_screen);
        game_map.SetMap(map_data);
        
        
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < SCREEN_TICKS_PER_FRAME) {
            SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTime);
        }
    }

    close();
    return 0;
}
