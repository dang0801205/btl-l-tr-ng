#ifndef THREATS_H_
#define THREATS_H_
#include "CommonFunc.h"
#include "Baseobject.h"
class Threats : public BaseObject
{
public:
  Threats();
  ~Threats();

  void set_x_val(const float& xVal){x_val_ = xVal;}
  void set_y_val(const float& yVal) {y_val_= yVal; }

  void set_x_pos(const float& xp){x_pos_ = xp;}
  void set_y_pos(const float &yp){y_pos_ = yp;}

  float get_x_pos() const {return x_pos_;}
  float get_y_pos() const {return y_pos_;}
protected:
  int map_x_;
  int map_y_;
  float  x_val_;
  float y_val_;
  float x_pos_;
  float y_pos_;
 SDL_Rect frame_clip[8];
  bool on_ground_;
  int come_back_time_; 
  int width_frame_;
  int height_frame_;
  int frame;
};


#endif