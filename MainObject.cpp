#include "MainObject.h"
#include "CommonFunc.h"
#include "Baseobject.h"

MainObject::MainObject() {
    frame_ = 0;
    x_pos_ = 0;
    y_pos_ = 0;
    x_val_ = 0;
    y_val_ = 0;
    width_frame_ = 0;
    height_frame_ = 0;
    status_ = -1;
    input_type.left_ = 0;
    input_type.right_ = 0;
    input_type.down_ = 0;
    input_type.jump_ = 0;
    input_type.up_ = 0;
    on_ground = false;
	map_x_ = 0;
	map_y_ = 0;
	
	come_back_time = 0;
    
}


MainObject::~MainObject() {}

bool MainObject::LoadImg(std::string path, SDL_Renderer* screen) {
    bool ret = BaseObject::LoadImg(path, screen);

    if (ret == true) {
        SDL_Rect r;
        get_rect(r);
        width_frame_ = r.w / 8;
        height_frame_ = r.h/1.2;
    }

    return ret;
}

void MainObject::set_clips() {
    if (width_frame_ > 0 && height_frame_ > 0) {
        for (int i = 0; i < 8; ++i) {
            frame_clip_[i].x = i * width_frame_;
            frame_clip_[i].y = 0;
            frame_clip_[i].w = width_frame_;
            frame_clip_[i].h = height_frame_;
        }
    }
}

void MainObject::Show(SDL_Renderer* des) {
    std::string imagePath = (status_ == WALK_LEFT) ? "img/run_left.png" : "img/fixed_right.png";
    LoadImg(imagePath, des);

    if (input_type.left_ || input_type.right_) {
        ++frame_;
    } else {
        frame_ = 0;
    }

    frame_ = (frame_ >= 8) ? 0 : frame_;

    SDL_Rect r;
    get_rect(r);
    r.x = x_pos_ - map_x_;
    r.y = y_pos_ - map_y_;

    SDL_Rect* current_clip = &frame_clip_[frame_];
    SDL_Rect renderQuad = {r.x, r.y, width_frame_, height_frame_};
    SDL_RenderCopy(des, p_object_, current_clip, &renderQuad);
}

void MainObject::HandleInputAction(SDL_Event events, SDL_Renderer* screen) {
    if (events.type == SDL_KEYDOWN) {
        switch (events.key.keysym.sym) {
            case SDLK_RIGHT:
                status_ = WALK_RIGHT;
                input_type.right_ = 1;
                input_type.left_ = 0;
                break;
            case SDLK_LEFT:
                status_ = WALK_LEFT;
                input_type.left_ = 1;
                input_type.right_ = 0;
                break;
        }
    } else if (events.type == SDL_KEYUP) {
        switch (events.key.keysym.sym) {
            case SDLK_RIGHT:
                input_type.right_ = 0;
                break;
            case SDLK_LEFT:
                input_type.left_ = 0;
                break;
        }
    }
	if(events.type == SDL_KEYDOWN) {
    if(events.key.keysym.sym == SDLK_UP) {
        input_type.jump_ = 1;
    }
}

}

void MainObject::DoPlayer(Map& map_data) {
	if(come_back_time == 0){
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
			if(on_ground  == true)
			{
				y_val_ = - JUMP_VAL;
			}
			on_ground = false;
			input_type.jump_ = 0;
		}


		CheckToMap(map_data);
		CenterEntityOnMap(map_data);
	}
	if(come_back_time > 0){
		come_back_time -- ;
		if(come_back_time == 0)
		{if(y_pos_ > 256)
		{
			x_pos_ -= 256;
			y_pos_ -= 256;
		}
		else{
			x_pos_ = 0;
		}
			y_pos_ = 0;
			x_val_ = 0;
			y_val_ = 0;
		}
	}
}
   void MainObject::CenterEntityOnMap(Map& map_data)
{
	map_data.start_x_ = x_pos_ - (SCREEN_WIDTH/2);
	if(map_data.start_x_ < 0 )
	{
		map_data.start_x_ = 0;
	}
	else if(map_data.start_x_ + SCREEN_WIDTH >= map_data.max_x_)
	{
		map_data.start_x_ = map_data.max_x_ - SCREEN_WIDTH;
	}

	map_data.start_y_ = y_pos_ - (SCREEN_HEIGHT/2);
	if(map_data.start_y_ < 0 )
	{
		map_data.start_y_ = 0;
	}
	else if(map_data.start_y_ = SCREEN_HEIGHT >= map_data.max_y_)
	{
		map_data.start_y_ = map_data.max_y_ - SCREEN_HEIGHT;
	}



}
     void MainObject::CheckToMap(Map& map_data)
{
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;

	int height_min = height_frame_ < TILE_SIZE ? height_frame_ : TILE_SIZE;
	x1 = (x_pos_ + x_val_)/TILE_SIZE;
	x2 = (x_pos_ + x_val_ + width_frame_-1)/TILE_SIZE;

	y1 = (y_pos_)/TILE_SIZE;
	y2 = (y_pos_ + height_min - 1)/TILE_SIZE;

	if(x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 << MAX_MAP_Y)
	{
		if(x_val_ >0)
		{
			if(map_data.tile[y1][y2] != BLANK_TILE || map_data.tile[y2][x2] != BLANK_TILE )
			{
				x_pos_ = x2*TILE_SIZE;
				x_pos_ -= width_frame_ + 1;
				x_val_ = 0;
			}

		}
		else if(x_val_ < 0)
		{
			if(map_data.tile[y1][x1] != BLANK_TILE || map_data.tile[y2][x1] != BLANK_TILE)
			{
				x_pos_ = (x1+1) * TILE_SIZE;
				x_val_ = 0;
			}

		}


	}
	int width_min = width_frame_ < TILE_SIZE ? width_frame_ : TILE_SIZE;
	x1 = (x_pos_)/TILE_SIZE;
	x2 = (x_pos_ + width_min)/TILE_SIZE;

	y1 = (y_pos_ + y_val_)/TILE_SIZE;
	y2 = (y_pos_ + y_val_ + height_frame_ -1)/TILE_SIZE;


	if(x1 >=0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
	{
		if(y_val_ > 0 )
		{
			if(map_data.tile[y2][x1] != BLANK_TILE || map_data.tile[y2][x2] != BLANK_TILE)
			{
				y_pos_ = y2*TILE_SIZE;
				y_pos_ -= (height_frame_ + 1);
				y_val_ = 0;
				on_ground = true;
			}

		}
		else if(y_val_ < 0)
		{
			if(map_data.tile[y1][x1] != BLANK_TILE || map_data.tile[y1][x2] != BLANK_TILE)
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
	else if(x_pos_ + width_frame_ > map_data.max_x_)
	{
		x_pos_ = map_data.max_x_ - width_frame_ - 1;
	}
	if(y_pos_ > map_data.max_y_)
	{
		come_back_time = 60;
	}
}