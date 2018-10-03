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
      static Window& Instance()
      {
        static Window instance;
        return instance;
      }


      int Width()const{return m_width;}
      int Height()const{return m_height;}
      SDL_Window* getSDLWindow(){return m_window;}

      Color getColor(){return m_colorClear;}
      void setColor(Color c){m_colorClear = c;}

      void setDimensions(int width, int height);
      void setFullScreen();
      void setFullScreenDesktop();

    protected:
      friend class Application;
      static void init(const std::string& name){Instance()._init(name);}
      static void uninit(){Instance()._uninit();}
      static void clear(){Instance()._clear();}
      static void render(){Instance()._render();}

    private:
      Window(){}
      ~Window(){}

      /*Window variables for the application*/
      SDL_Window* m_window;
      std::string m_name;

      int m_width;
      int m_height;

      Color m_colorClear;

      void _init(const std::string&);
      void _uninit();
      void _clear();
      void _render();
  };

}//end Hearth

#endif /* WINDOW_HPP */
