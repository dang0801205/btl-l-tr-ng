#ifndef THREATS_H_
#define THREATS_H_
#include "CommonFunc.h"
#include "Baseobject.h"
#include "BulletObject.h"
#define THREAT_FRAME_NUM 8
#define THREAT_GRAVITY_SPEED 0
#define THREAT_MAX_FALL_SPEED 10
class Threats : public BaseObject
{
public:
  Threats();
  ~Threats();
  enum TypeMove
  {
    STATIC_THREAT = 0,
    MOVE_IN_SPACE_THREAT = 1
  };
  void set_x_val(const float& xVal){x_val_ = xVal;}
  void set_y_val(const float& yVal) {y_val_= yVal; }

  void set_x_pos(const float& xp){x_pos_ = xp;}
  void set_y_pos(const float &yp){y_pos_ = yp;}

  float get_x_pos() const {return x_pos_;}
  float get_y_pos() const {return y_pos_;}
  void SetMapXY(const int& mp_x,const int&mp_y)
  {
    map_x_ = mp_x;
    map_y_ = mp_y;
  }
  void set_clips();
  bool LoadImg(std::string path,SDL_Renderer* screen);
  void Show(SDL_Renderer* des);
  int get_width_frame() const{return width_frame_;}
  int get_height_frame() const{return height_frame_;}
  void Doplayer(Map& gMap);
  void CheckToMap(Map &gMap);  
  void InitThreats();

  void set_type_move(const int& typeMove){type_move = typeMove;}
  void SetAnimationPos(const int& pos_a, const int& pos_b){ ani_a_ = pos_a,ani_b_ = pos_b;}
  void set_input_left(const int& ipleft) {input_type.left_ = ipleft;};
  void ImpMoveType(SDL_Renderer* screen);


  protected:
  int map_x_;
  int map_y_;
  float  x_val_;
  float y_val_;
  float x_pos_;
  float y_pos_;
 SDL_Rect frame_clip[7];
  bool on_ground_;
  int come_back_time_; 
  int width_frame_;
  int height_frame_;
  int frame;

  int type_move;
  int ani_a_;
  int ani_b_;
  Input input_type;


};


#endif