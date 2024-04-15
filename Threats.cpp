#include "Threats.h"
#include "MainObject.h"
#include "Baseobject.h"

Threats::Threats()
{
   width_frame_ = 0;
   height_frame_ = 0;
   x_val_ = 0.0;
   y_val_ = 0.0;
   x_pos_ = 0.0;
   y_pos_ = 0.0;
   on_ground_ = 0;
   come_back_time_ = 0;
   frame = 0;
   
   ani_a_ = 0;
   ani_b_ = 0;
   input_type.left_ = 1;
   type_move = STATIC_THREAT;
}

Threats::~Threats()
{	

}
bool Threats::LoadImg(std::string path,SDL_Renderer* screen)
{
	bool ret = BaseObject::LoadImg(path,screen);
	if(ret)
	{
		width_frame_ = rect_.w/7;
		height_frame_ = rect_.h;
	}
	return ret;
}
void Threats::set_clips()
{
	 if (width_frame_ > 0 && height_frame_ > 0) {
        for (int i = 0; i < 7; ++i) {
            frame_clip[i].x = i * width_frame_;
            frame_clip[i].y = 0;
            frame_clip[i].w = width_frame_;
            frame_clip[i].h = height_frame_;
        }
    }
}
void Threats::Show(SDL_Renderer* des)
{ 
  if(come_back_time_ == 0)
  {
	rect_.x = x_pos_ - map_x_;
	rect_.y = y_pos_ - map_y_;
	frame++;
	if(frame >= 7)
	{
		frame = 0;
	}
	SDL_Rect* currentClip = &frame_clip[frame];
	SDL_Rect rendQuad = {rect_.x,rect_.y,width_frame_,height_frame_};
	SDL_RenderCopy(des, p_object_, currentClip, &rendQuad);
   }
}
void Threats::Doplayer(Map& gMap)
{
	if (come_back_time_ == 0)
	{
		x_val_ = 0;
		y_val_ += GRAVITY_SPEED;
		if(y_val_ >= MAX_FALL_SPEED)
		{
			y_val_ = MAX_FALL_SPEED;
		}
		if(input_type.left_ == 1)
		{
       x_val_ -= 3;
		}
		else if(input_type.right_ == 1)
       {
		x_val_ += 3;
	   }
		CheckToMap(gMap);
	}
	else if(come_back_time_ > 0){
		come_back_time_--;
		if(come_back_time_ == 0)
		{
			InitThreats();	
		}
	}
}
void Threats::InitThreats()
{
	x_val_ = 0;
			y_val_ = 0;
			if(x_pos_ > 256)
			{
				x_pos_ -= 256;
				ani_a_ -= 256;
				ani_b_ -= 256;
			}
			else
			{
				x_pos_ = 0;
			}
			x_pos_	= 0;
			come_back_time_ = 0;
			input_type.left_ == 1;
}
void Threats::CheckToMap(Map& gMap)
{
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;

	int height_min = height_frame_ < TILE_SIZE ? height_frame_ : TILE_SIZE;
	x1 = (x_pos_ + x_val_)/TILE_SIZE;
	x2 = (x_pos_ + x_val_ + width_frame_-10)/TILE_SIZE;

	y1 = (y_pos_)/TILE_SIZE;
	y2 = (y_pos_ + height_min - 1)/TILE_SIZE;

	if(x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 << MAX_MAP_Y)
	{
		if(x_val_ >0)
		{   int val1 =gMap.tile[y1][x2];
		    int val2 = gMap.tile[y2][x2];
			
			if(val1!= BLANK_TILE && val1!= 6|| val2 != BLANK_TILE && val2 != 6)
			{
				x_pos_ = x2*TILE_SIZE;
				x_pos_ -= width_frame_ + 1;
				x_val_ = 0;
			}
			

		}
		else if(x_val_ < 0)
		{    int val1 = gMap.tile[y1][x1];
		    int val2 = gMap.tile[y2][x2];
			
			if(val1 != BLANK_TILE &&val1 != 6|| val2 != BLANK_TILE && val2 != 6)
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
		{   int val1 = gMap.tile[y2][x1];
	 	    int val2 = gMap.tile[y2][x2];
			
           if(val1 != BLANK_TILE && val1 != 6|| val2 != BLANK_TILE && val2 != 6)
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
		come_back_time_ = 60;
	}

}
void Threats::ImpMoveType(SDL_Renderer* screen)
{
	if(type_move == STATIC_THREAT)
	{

	}
	else
	{
		if(on_ground_ == true)
		{  
		 if(x_pos_ > ani_b_){
			input_type.left_ = 1;
			input_type.right_ = 0;
			LoadImg("img//threats_right.png",screen);
		   }  
		else if(x_pos_ < ani_a_)
		   {
			  input_type.left_ = 0;
			  input_type.right_ = 1;
			  LoadImg("img//threats_left.png",screen);
		   }
	

		}
		else
		{
			if(input_type.left_ == 1)
			{
				LoadImg("img//threats_left.png",screen);	
			}
		}
	}
	
}
void Threats::InitBullet(BulletObject* p_bullet,SDL_Renderer* screen)
{
	if(p_bullet != NULL)
	{
		 p_bullet -> set_bullet_type(BulletObject::THREAT_BULLET);
		 p_bullet ->  LoadImgBullet(screen);
		
		
			p_bullet -> set_is_move(true);
			p_bullet -> set_bullet_dir(BulletObject::DIR_LEFT);
			p_bullet -> SetRect(rect_.x + 10, rect_.y +5);
			p_bullet -> set_x_val(15);

		bullet_list_.push_back(p_bullet);
	}

}

void Threats::MakeBullet(SDL_Renderer* screen, const int& x_limit, const int& y_limit)
{
	for (int i = 0; i < bullet_list_.size(); i++)
	{
		BulletObject* p_bullet = bullet_list_.at(i);
		if(p_bullet != NULL)
		{
			if(p_bullet -> get_is_move())
			{
				int bullet_distance = rect_.x - p_bullet->GetRect().x;
				if(bullet_distance <300)
				{
					p_bullet -> HandleMove(x_limit,y_limit);
					p_bullet -> Render(screen);
				}else
				{
					p_bullet -> set_is_move(false);
				}

				
				
			}
			else
			{
				p_bullet -> set_is_move(true);
				p_bullet -> SetRect(rect_.x + 10, rect_.y +10);
			}
		}

		
	}
}


void Threats::RemoveBullet(const int& index)
{
	int size = bullet_list_.size();
	if(size > 0 && index < size) 
	{
		BulletObject* p_bullet = bullet_list_.at(index);
		bullet_list_.erase(bullet_list_.begin() + index); 

		if(p_bullet)
		{
			delete p_bullet;
			p_bullet = NULL;
		}


	}

}
