/**
 * @file window.hpp
 * @brief 
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-09-23
 * @edited 2017-09-23
 */
#ifndef WINDOW_HPP
#define WINDOW_HPP 

#include "color.hpp"

#include<SDL2/SDL.h>
#include<string>

namespace Hearth
{

  class Window
  {
    public:
      static Window* Instance();

      void init(const std::string&);
      void uninit();
      void clear();
      void render();

      int Width(){return m_width;}
      int Height(){return m_height;}
      SDL_Window* getSDLWindow(){return m_window;}

      Color getColor(){return m_colorClear;}
      void setColor(Color c){m_colorClear = c;}

      void setDimensions(int width, int height);
      void setFullScreen();
      void setFullScreenDesktop();


    private:
      Window();
      ~Window();

      static Window* m_instance;

      /*Window variables for the application*/
      SDL_Window* m_window;
      std::string m_name;

      int m_width;
      int m_height;

      Color m_colorClear;
  };

}//end Hearth

#endif /* WINDOW_HPP */
