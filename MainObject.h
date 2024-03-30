#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H

#include <vector>
#include "CommonFunc.h"
#include "BaseObject.h"
#include "game_map.h"
#include "ImpTimer.h"
#include "BulletObject.h"
#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 8
#define JUMP_VAL 18
class MainObject : public BaseObject {
public:
    MainObject();
    ~MainObject();

    enum WalkType {
        WALK_RIGHT = 0,
        WALK_LEFT = 1
    };

    virtual bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen); 
    void set_clips(); 

    void DoPlayer(Map& map_data); 
    void CheckToMap(Map& map_data);
    void SetMapXY(const int map_x,const int map_y) {map_x_ = map_x ; map_y_ = map_y;};
    void CenterEntityOnMap(Map& map_data);
 
   void set_bullet_list(std::vector<BulletObject*> bullet_list)
	{
		p_bullet_list_ = bullet_list;
	}
	std::vector<BulletObject*> get_bullet_list() const {return p_bullet_list_;}
    void HandleBullet(SDL_Renderer* des);

	void RemoveBullet(const int& index);
    SDL_Rect getRectFrame();
	int get_frame_width() const {return width_frame_;}
	int get_frame_height() const {return height_frame_;}
	
	std::vector<BulletObject*> p_bullet_list_;
    float x_val_;  
    float y_val_;

    float x_pos_;
    float y_pos_;

    int width_frame_;
    int height_frame_;

    SDL_Rect frame_clip_[9];
    Input input_type;
    int frame_;
    int status_;
    bool on_ground;
    
    int map_x_;
    int map_y_;

   

    int come_back_time;
    
};

#endif