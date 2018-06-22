/**
 * @file image.h
 * @brief Image class declaration file for the hearth engine
 * @author Colby Japp
 * @version 0.0.1
 * @date 2018-04-25
 * @edited 2018-04-25
 */
#ifndef IMAGE_H
#define IMAGE_H 

#include "ui.h"
#include "sprite.hpp"
#include "color.hpp"

#include<string>

namespace Hearth
{

  class Image : public UI
  {
    public:
      Image();
      Image(int x,int y,int w,int h);
      ~Image();

      virtual void draw();
      virtual void update();
      virtual void init();

      void initSprite(int width, int height, Color c);
      void initSprite(std::string text, int width, int height);


    protected:
      Color m_color;

      Sprite* m_sprite; 
      int m_height;
      int m_width; 
  };
}

#endif /* IMAGE_H */
