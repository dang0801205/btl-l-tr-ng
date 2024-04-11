#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include "CommonFunc.h"
class BaseObject
{   
       
    public:
     BaseObject();
    ~BaseObject();
    void SetRect(const int& x, const int& y){rect_.x = x, rect_.y = y;}
    SDL_Rect GetRect() const {return rect_;}
    SDL_Texture* GetObject() const {return p_object_;}
    virtual bool LoadImg(std::string path,SDL_Renderer* screen);
    void Render(SDL_Renderer* des,const SDL_Rect* clip = NULL);
    void get_rect(SDL_Rect &r) {
        r.w=rect_.w;
        r.h=rect_.h;
        r.x=rect_.x;
        r.y=rect_.y;
    };
    void Free();
   
     SDL_Texture* p_object_;
     SDL_Rect rect_;
};



#endif
