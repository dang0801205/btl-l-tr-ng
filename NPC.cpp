#include "NPC.h"
#include "Baseobject.h"
NPC::NPC()
{
   width_frame_ = 0;
   height_frame_ = 0;
   x_val_ = 0.0;
   y_val_ = 0.0;
   x_pos_ = 0.0;
   y_pos_ = 0.0;
   on_ground_ = 0;
   think_time_ = 0;
   frame = 0;
}

NPC::~NPC() {
}

bool NPC::LoadImg(std::string path, SDL_Renderer* screen) {
    bool ret = BaseObject::LoadImg(path, screen);
    if (ret) {
        width_frame_ = rect_.w;
        height_frame_ = rect_.h;
    }
    return ret;
}
void NPC::Doplayer(Map& map_data) {
	if(think_time_ == 0){
    x_val_ = 0;
    y_val_ += 0.8;
    if(input_type.left_ == 1)
		{
			x_val_ -= PLAYER_SPEED;
		}
		else if(input_type.right_ == 1)
		{
			x_val_ += PLAYER_SPEED;
		}
		if(input_type.jump_ == 1)
		{
			if(on_ground_  == true)
			{
				y_val_ = - JUMP_VAL;
			}
			on_ground_ = false;
			input_type.jump_ = 0;
		}


		CheckToMap(map_data);
		//CenterEntityOnMap(map_data);

		
	}
	if(think_time_ > 0){
		think_time_ -- ;
	InitPlayer();
		}
	}

void NPC::InitPlayer()
{
	x_val_ = 0;
	y_val_ = 0;
	if(x_pos_ > 256)
	{
		x_pos_ -= 256;
	}
	else{
		x_pos_ = 0;
		y_pos_ =0;
		think_time_ = 0;
		input_type.left_ = 0;
	}
}
void NPC::Show(SDL_Renderer* des) {
    if (think_time_ == 0) {
        rect_.x = x_pos_ - map_x_; 
        rect_.y = y_pos_ - map_y_; 

        SDL_Rect rendQuad = {rect_.x, rect_.y, 64, 64};
        SDL_RenderCopy(des, p_object_, nullptr, &rendQuad); 
    }
}
void NPC::CheckToMap(Map& gMap)
{
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;

	int height_min = height_frame_;
	x1 = (x_pos_ + x_val_)/TILE_SIZE;
	x2 = (x_pos_ + x_val_ + width_frame_-1)/TILE_SIZE;

	y1 = (y_pos_)/TILE_SIZE;
	y2 = (y_pos_ + height_min - 1)/TILE_SIZE;

	if(x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
	{
		if(x_val_ >0)
		{   int val1 =gMap.tile[y1][x2];
		    int val2 = gMap.tile[y2][x2];
			
			if(val1!= BLANK_TILE && val1!= BLANK_TILE|| val2 != BLANK_TILE && val2 != BLANK_TILE)
			{
				x_pos_ = x2 * TILE_SIZE;
				x_pos_ -= width_frame_ + 1;
				x_val_ = 0;
			}
			

		}
		else if(x_val_ < 0)
		{    int val1 = gMap.tile[y1][x1];
		    int val2 = gMap.tile[y2][x2];
			
			if(val1 != BLANK_TILE &&val1 != BLANK_TILE|| val2 != BLANK_TILE && val2 != BLANK_TILE)
			{
				x_pos_ = (x1 + 1) * TILE_SIZE;
				x_val_ = 0;
			}
			

		}


	}
	int width_min = width_frame_ ;
	x1 = (x_pos_)/TILE_SIZE;
	x2 = (x_pos_ + width_min)/TILE_SIZE;

	y1 = (y_pos_ + y_val_)/TILE_SIZE;
	y2 = (y_pos_ + y_val_ + height_frame_ -1)/TILE_SIZE;


	if(x1 >=0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
	{
		if(y_val_ > 0 )
		{   int val1 = gMap.tile[y2][x1];
	 	    int val2 = gMap.tile[y2][x2];
			
           if(val1 != BLANK_TILE && val1 != BLANK_TILE|| val2 != BLANK_TILE && val2 != BLANK_TILE)
			{
				y_pos_ = y2*TILE_SIZE;
				y_pos_ -= (height_frame_ + 1);
				y_val_ = 0;
				on_ground_ = true;
			}
			
			

		}
		else if(y_val_ < 0)
		{   int val1 = gMap.tile[y1][x1];
		    int val2 = gMap.tile[y1][x2];
		   
			if(val1!= BLANK_TILE && val1 != 6|| val2 != BLANK_TILE && val2 != 6)
			{
				y_pos_ = (y1 + 1)* TILE_SIZE;
				y_val_ = 0; 
			}

		
		}

	}

	x_pos_ += x_val_;
	y_pos_ += y_val_;
	if(x_pos_ < 0)
	{
		x_pos_ = 0;
	}
	else if(x_pos_ + width_frame_ > gMap.max_x_)
	{
		x_pos_ = gMap.max_x_ - width_frame_ - 1;
	}
	if(y_pos_ > gMap.max_y_)
	{
		think_time_ = 60;
	}

}