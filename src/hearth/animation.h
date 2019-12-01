#ifndef ANIMATION_H
#define ANIMATION_H 

#include "hTexture.h"

#include<vector>

struct SpriteSheet
{
  HTexture* _sheet;//should have its own dimensions in pixels
  unsigned int _width;//in terms of frames
  unsigned int _height; //in terms of frames
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

    int getSpeed(){return _speed};
    void setSpeed(int spd){_speed = spd}
};


#endif /* ANIMATION_H */
