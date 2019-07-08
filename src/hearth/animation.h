#ifndef ANIMATION_H
#define ANIMATION_H 

#include "hTexture.h"

#include<vector>

struct SpriteSheet
{
  HTexture* _sheet;
  unsigned int _width;
  unsigned int _height;
};

class Animation
{
  private:
    std::vector<SDL_Rect*> _frames;
    SpriteSheet* _sheet;

  public:
    Animation();
    ~Animation();

    void setSheet(HTexture* sheet);
    void addFrame(unsigned int index);

    unsigned int frameCount(){return _frames.size();}
};


#endif /* ANIMATION_H */
