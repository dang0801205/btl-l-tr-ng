
#include "CommonFunc.h"
#include "Baseobject.h" 
bool SDLCommonFunc::CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2) {
  int leftA = object1.x;
  int rightA = object1.x + object1.w;
  int topA = object1.y;
  int bottomA = object1.y + object1.h;

  int leftB = object2.x;
  int rightB = object2.x + object2.w;
  int topB = object2.y;
  int bottomB = object2.y + object2.h;

  
  if (leftA <= leftB && rightA >= leftB && topA < bottomB && bottomA > topB) {
    return true;
  }


  if (topA == topB && rightA == rightB && bottomA == bottomB) {
    return true;
  }

  return false;
}
