	#include "BulletObject.h"
	#include "Baseobject.h"
	#include "MainObject.h"
	BulletObject::BulletObject()
{  
	x_val_ = 0;
	y_val_ = 0;
	is_move_ = false;
    bullet_type_ =MAIN_BULLET;

}


BulletObject::~BulletObject()
{

}
void BulletObject::LoadImgBullet(SDL_Renderer* des)
{
    if(bullet_type_ == MAIN_BULLET){
        LoadImg("img/bullet.png",des);
    }
    else
    {
        LoadImg("img/bullet.png",des);
    }
}


void BulletObject::HandleMove(const int& x_border, const int& y_border)
{
    if (bullet_dir_ == DIR_RIGHT)
    {
        rect_.x += 10;
       
        if (rect_.x > x_border)
        {
            is_move_ = false;
        }
    }
    else if (bullet_dir_ == DIR_LEFT)
    {
        rect_.x -= 10;
        if (rect_.x < 0)
        {
            is_move_ = false;
        }
    }
}

	


	



