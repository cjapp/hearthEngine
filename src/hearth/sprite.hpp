/**
 * @file sprite.hpp
 * @brief 
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-09-07
 * @edited 2017-09-07
 */

#ifndef SPRITE_H
#define SPRITE_H


#include"color.hpp"
#include"hTexture.h"
#include"transform.h"
#include"camera.h"

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<string>

namespace Hearth
{

  class Sprite
  {
    public:
      Sprite();
      ~Sprite();

      void init();
      void draw(const Transform& t, const Camera* c); 
      void setVisible(bool visibility);
      void setTexture(const std::string& name);
      void setClip(SDL_Rect* clip);
      void setClip(int x,int y,int w,int h);
      void setDim(int w, int h);
      void setColor(Color c);

      HTexture* getTexture(){return m_texture;}

    private:

      HTexture* m_texture;
      SDL_Rect* m_clip;

      int m_width;
      int m_height;

      Color m_color;
      

      /*Rendering private variables*/
      bool m_visible;
  };

}//end Hearth

#endif /* SPRITE_H */
