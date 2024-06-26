#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H
#include <vector>
#include "CommonFunc.h"
#include "BaseObject.h"
#include "game_map.h"
#include "ImpTimer.h"
#include "BulletObject.h"
#define GRAVITY_SPEED 1
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 10
#define JUMP_VAL 20
class MainObject : public BaseObject {
public:
    MainObject();
    ~MainObject();

    enum WalkType {
        WALK_RIGHT = 0,
        WALK_LEFT = 1
    };
    bool Instruction();
    virtual bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen); 
    void set_clips(); 

    void DoPlayer(Map& map_data); 
    void CheckToMap(Map& map_data);
    void SetMapXY(const int map_x,const int map_y) {map_x_ = map_x ; map_y_ = map_y;};
    void CenterEntityOnMap(Map& map_data);
    SDL_Rect getRectFrame();
 
   void set_bullet_list(std::vector<BulletObject*> bullet_list)
	{
		p_bullet_list_ = bullet_list;
	}
	std::vector<BulletObject*> get_bullet_list() const {return p_bullet_list_;}
    void HandleBullet(SDL_Renderer* des);

	void RemoveBullet(const int& index);
   
	int get_frame_width() const {return width_frame_;}
	int get_frame_height() const {return height_frame_;}
    void IncreaseMoney();


    void set_comeback_time(const int& cb_time) {come_back_time = cb_time;}
    int GetMoneyCount() const {return money_count;}

  
private:
	std::vector<BulletObject*> p_bullet_list_;
    int money_count;
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