/**
 * @file render.hpp
 * @brief Render class declaration header file
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-09-28
 * @edited 2017-09-28
 */


#ifndef RENDER_HPP
#define RENDER_HPP 

#include "window.hpp"
#include "resourceManager.hpp"
#include "gameObject.hpp"

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>


namespace Hearth
{

  class Render
  {
    private:
      static Render* m_instance;

      SDL_Renderer* m_renderer;

      Render();
      ~Render();

    public:

      static Render* Instance();

      bool init();
      void uninit();

      SDL_Renderer* getRenderer(){return m_renderer;}
  };

}//end Hearth

#endif /* RENDER_HPP */
