/**
 * @file animation.h
 * @brief Animation class declaration file for the hearth engine.
 *        Animations are a collection of clips(snippets) of a texture
 *        that are then used in place of an objects sprite
 *        (if the animation for the object is set).
 * @author Colby Japp
 * @version 0.0.1
 * @date 2019-03-20
 * @edited 2019-03-20
 */
#ifndef ANIMATION_H
#define ANIMATION_H 

#include<vector>
#include<SDL2/SDL.h>
#include "hTexture.h"

namespace Hearth
{

  class Animation
  {
    private:
      std::vector<SDL_Rect> _frames;//frame array of the sprites for animation
      HTexture* _spriteSheet; //the sprite sheet that contains the frames for the animation
      unsigned int _currentFrame;// the current frame index (used for when continuing/loading a state)

      unsigned int _speed; //the length of time between frames of the animation

    public:
      Animation();
      ~Animation();

      void initialize(const HTexture* sheet);
      void update();

      void createFrame(const SDL_Rect&);

      unsigned int getFrameCount(){return _frames.size();}
      unsigned int getCurrentFrame(){return _currentFrame;}

      void setSpeed(int speed){_speed = speed;}
      int getSpeed(){return _speed;}
  };

}
#endif /* ANIMATION_H */
