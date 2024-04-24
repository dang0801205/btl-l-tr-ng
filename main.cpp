#include "Baseobject.h"
#include "CommonFunc.h"
#include "game_map.h"
#include "ImpTimer.h"
#include "MainObject.h"
#include "BulletObject.h"
#include "Threats.h"
#include "NPC.h"
#include "TextObject.h"
#include "Windows.h"

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

//Mix_Chunk *music = NULL;
Uint32 frameStart;
int frameTime;
BaseObject layer1, layer2, layer3;
TTF_Font* font_time = NULL;
TTF_Font* font_menu = NULL;
MainObject p_player;
NPC npc;
BaseObject menu1;
bool InitData()
{
	bool success = true;
	int ret = SDL_Init(SDL_INIT_EVERYTHING);
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
    if(TTF_Init() == -1)
    {
        success = false;
    }
    font_time = TTF_OpenFont("font//times new roman bold italic.ttf", 30);
    if(font_time == NULL) 
    {
        success = false;
    }
   /* Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    music = Mix_LoadWAV("mixer/play.wav");
    if(music == NULL)
    {
        success = false;
    }*/
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

std::vector<Threats*> MakeThreatsList()
{   
    std::vector<Threats*> list_threats;
    
    Threats* threats_object = new Threats[20];
    Threats* moving_threats = new Threats[20];
    for(int i = 0; i < 20; i++)
    {
        Threats* p_threats = (moving_threats + i);
        if(p_threats != NULL)
        {
            p_threats->LoadImg("img//threats_left.png",g_screen);
            p_threats->set_clips();
            p_threats->set_type_move(Threats::MOVE_IN_SPACE_THREAT);
            p_threats->set_input_left(1);
            p_threats->set_x_pos(500+ i*500);
            p_threats->set_y_pos(200);

            int pos1 = p_threats->get_x_pos() - 50;
            int pos2 = p_threats->get_x_pos() + 50;
            p_threats->SetAnimationPos(pos1,pos2);         
            list_threats.push_back(p_threats);
        }
    } 
    for (int i = 0; i < 20; i++)
    {
        Threats* p_threats = (threats_object + i);
        if (p_threats != NULL)
        {
            p_threats->LoadImg("img//threat1.png", g_screen);
            p_threats->set_clips();
            p_threats->set_x_pos(700 + i * 500);
            p_threats->set_y_pos(250);
            p_threats->set_type_move(Threats::STATIC_THREAT);
            p_threats->set_input_left(0); 

            BulletObject* p_bullet = new BulletObject();
            p_threats->InitBullet(p_bullet,g_screen);
            list_threats.push_back(p_threats);
        }
    }
    return list_threats;
}

int main(int argc, char* argv[]) {
    if (InitData() == false)
        return -1;
       
    p_player.LoadImg("img/r.png", g_screen);
    p_player.set_clips();
    GameMap game_map;
    game_map.LoadMap("map/map01.dat");
    game_map.LoadTiles(g_screen);
    menu1.LoadImg("img/wizard0.png",g_screen);
    std::vector<Threats*>threats_list = MakeThreatsList();
    LoadAndStretchLayers(g_screen, layer1, layer2, layer3, SCREEN_WIDTH, SCREEN_HEIGHT);
    TextObject mark_game;
    mark_game.SetColor(TextObject::WHITE_TEXT);
    UINT mark_value = 0;
    TextObject money_game;
    money_game.SetColor(TextObject::WHITE_TEXT);
    TextObject menu_game;
    menu_game.SetColor(TextObject::BLACK_TEXT);
    bool is_quit = true;
    bool playMusic = 0;
    Uint32 frameStart;
    int frameTime;
    int conversation = 0;
    int num_die = 0;
    bool menu = true;
    std::string strmenu = "Press to start";
    
    while(menu)
    {
        while(SDL_PollEvent(&g_event) != 0)
        {
            if (g_event.type == SDL_QUIT) {
                is_quit = true;
                menu = false;
            }
            if(g_event.type == SDL_MOUSEBUTTONDOWN)
            {
                menu = false;
                is_quit = false;
            }

        }
        menu1.Render(g_screen, NULL);
         menu_game.SetText(strmenu);
         menu_game.LoadFromRenderText(font_time,g_screen);
         menu_game.RenderText(g_screen,SCREEN_WIDTH*0.5 - 50, SCREEN_HEIGHT* 0.5-50);
        SDL_RenderPresent(g_screen);
    }

    while (!is_quit) {
        frameStart = SDL_GetTicks();
       /* if(playMusic==0){
            Mix_PlayChannel(-1,music,-1);
            playMusic = 1;
        }*/
        while (SDL_PollEvent(&g_event) != 0) {
            if (g_event.type == SDL_QUIT) {
                is_quit = true;
            }
            p_player.HandleInputAction(g_event, g_screen);
            if(g_event.type == SDL_KEYDOWN){
                if(g_event.key.keysym.sym == SDLK_k){
                    conversation += 1;
                    if(conversation == 8){
                        conversation = 0;
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);

        layer1.Render(g_screen);
        layer2.Render(g_screen);
        layer3.Render(g_screen);

        game_map.DrawMap(g_screen);
        Map map_data = game_map.getMap();
    
         npc.LoadImg( "img/Idle9.png",g_screen);
        
         npc.CheckToMap(map_data);
         npc.set_x_pos(0);
         npc.set_y_pos(329);
       
        p_player.SetMapXY(map_data.start_x_,map_data.start_y_);
        p_player.DoPlayer(map_data);
        p_player.Show(g_screen);
        p_player.HandleBullet(g_screen);
        
      
        game_map.SetMap(map_data);
        
       for(int i = 0;i < threats_list.size();i++)
       {
        Threats* p_threat = threats_list.at(i);
        if(p_threat != NULL)
        {
            p_threat->SetMapXY(map_data.start_x_,map_data.start_y_);
            p_threat->ImpMoveType(g_screen);
            p_threat->Doplayer(map_data);
            p_threat->MakeBullet(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
            p_threat->Show(g_screen);
            
         SDL_Rect rect_player = p_player.getRectFrame();
				std::vector<BulletObject*> tBullet_list = p_threat -> get_bullet_list();
				bool bCol1 = false;
			
				for(int j=0;j<tBullet_list.size();j++)
				{
					BulletObject* pt_bullet = tBullet_list.at(j);
					if(pt_bullet)
					{
						bCol1 = SDLCommonFunc::CheckCollision(pt_bullet->GetRect(), rect_player);
						if(bCol1)
						{ 
                        p_player.RemoveBullet(j);
                        break;

						
					//std::cout << pt_bullet->get_x_val() << " " << pt_bullet -> get_y_val();
						}

					}

				}
                
				SDL_Rect rect_threat = p_threat -> getRectFrame();
				bool bCol2 = SDLCommonFunc::CheckCollision(rect_threat,rect_player);
				if(bCol2
                ||bCol1
                )
				{
					if(num_die++ <= 51)
					{   
						p_player.SetRect(0,0);
						p_player.set_comeback_time(5);
                       
						continue;
					}
					else
					{
						if(MessageBox(NULL,"GAME OVER" ,"INFO",MB_OK | MB_ICONSTOP) == IDOK)
						{
							p_threat -> Free();
							close();
							SDL_Quit();
							return 0;
						}

					}

				}
          
       } 
       }
    std::vector<BulletObject*> bullet_arr = p_player.get_bullet_list();
		for(int r = 0;r < bullet_arr.size();r++)
		{
			BulletObject* p_bullet = bullet_arr.at(r);
			if(p_bullet != NULL)
			{
				for(int t = 0;t < threats_list.size();t++)
				{
					Threats* obj_threats = threats_list.at(t);
					if(obj_threats != NULL)
					{
						SDL_Rect tRect;
						tRect.x = obj_threats -> GetRect().x;
						tRect.y = obj_threats -> GetRect().y;
						tRect.w = obj_threats -> get_width_frame();
						tRect.h = obj_threats -> get_height_frame();

						SDL_Rect bRect = p_bullet->GetRect();

						bool bCol = SDLCommonFunc::CheckCollision(bRect,tRect);
						if(bCol)
						{   mark_value++;
							p_player.RemoveBullet(r);
							obj_threats -> Free();
							threats_list.erase(threats_list.begin() + t);
						}

					}

				}

			}

		}

       std::vector<std::string> npc_dialogues = {
    "press k to interact",
    "How are you doing?",
    "Nice weather today!",
    "your treasure has been stealed",
    "And you the great wizard have to travel to the North and defeat all monster to retain it!",
    "Use arrow in the keyboard to move",
    "And use left mouse click to shoot powerful bullet",
    "Good luck with your journey wizard"
    // Thêm các lời nói khác tại đây...
};
 

 
   std::string random_dialogue = npc_dialogues[conversation];
		TextObject dialouge_text;
		dialouge_text.SetText(random_dialogue);
    
		dialouge_text.LoadFromRenderText(font_time, g_screen);
		if(p_player.Instruction())
        {dialouge_text.RenderText(g_screen, 100, 100);
        } 
        else{
            conversation = 0;
            }// Vị trí (100, 100)

         npc.SetMapXY(map_data.start_x_,map_data.start_y_);
         npc.Show(g_screen);
         std::string var_mark = std::to_string(mark_value);
         std::string strMark("Mark: ");
         strMark += var_mark;

         mark_game.SetText(strMark);
         mark_game.LoadFromRenderText(font_time,g_screen);
         mark_game.RenderText(g_screen,SCREEN_WIDTH*0.5 - 50, 15);

         int money_count = p_player.GetMoneyCount();
         std::string money_str = std::to_string(money_count);

         money_game.SetText(money_str);
         money_game.LoadFromRenderText(font_time,g_screen);
         money_game.RenderText(g_screen,SCREEN_WIDTH*0.5 - 250, 15);

         SDL_RenderPresent(g_screen);
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < SCREEN_TICKS_PER_FRAME) {
            SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTime);
        }
    }
    close();
    return 0;
}

