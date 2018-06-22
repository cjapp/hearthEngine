#ifndef HTEXTURE_H
#define HTEXTURE_H 

#include "color.hpp"

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<string>

namespace Hearth
{

  class UIText;

  class HTexture
  {
    public:
      HTexture(); 
      ~HTexture(); 

      bool load(int w, int h, Color c);
      bool loadFromFile(const std::string& filepath);
      bool loadFromFont(UIText& text);
      void free();
      void render(int x, int y, SDL_Rect* clip = NULL);

      void setHeight(int h){m_height = h;}
      void setWidth(int w){m_width = w;}
      void setColor(Color c){m_color = c;}

      int getWidth() const{return m_width;}
      int getHeight() const{return m_height;}
      SDL_Texture* getTexture() {return m_texture;}

    private:
      int m_width;
      int m_height;

      SDL_Texture* m_texture;
      Color m_color;
  };

}//end namespace Hearth

#endif /* HTEXTURE_H */
