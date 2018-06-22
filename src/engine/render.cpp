/**
 * @file render.cpp
 * @brief Render class function definition file
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-09-28
 * @edited 2017-09-28
*/

#include"render.hpp"
#include"error.hpp"
#include"gameObject.hpp"

namespace Hearth
{
  Render* Render::m_instance;

  Render::Render()
  {

  }

  Render::~Render()
  {
  }


  Render* Render::Instance()
  {
    if(m_instance == nullptr)
    {
      m_instance = new Render();
    }

    return m_instance;
  }


  /**
   * @brief Function that initializes the renderer
   *
   * @param win the window the renderer uses
   *
   * @return whether the renderer was successfully initialized
   */
  bool Render::init()
  {
    Error::printMessage("--Initializing Renderer");

    //initialize the SDL_Renderer
    if(m_renderer == nullptr && Window::Instance()->getSDLWindow() == nullptr)
      Error::fatalError("Error:Failed to init Renderer, Window or renderer nonexistant");

    m_renderer = SDL_CreateRenderer(Window::Instance()->getSDLWindow(), -1, SDL_RENDERER_ACCELERATED);
    if(m_renderer == nullptr)
    {
      printf("SDL failed to create renderer. SDL ERROR: %s\n", SDL_GetError());
      return false;
    }
    else
    {
      //Initialize PNG loading 
      int imgFlags = IMG_INIT_PNG;
      if( !( IMG_Init( imgFlags ) & imgFlags ) ) 
      { 
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false; 
      }

      //Initialize SDL_ttf 
      if( TTF_Init() == -1 ) 
      { 
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() ); 
        return false; 
      } 
    }

    Error::printMessage("--Finished Initializing Renderer");
  }

  /**
   * @brief Function that is used to unitialize the renderer
   */
  void Render::uninit()
  {
    if(m_renderer != nullptr)
      SDL_DestroyRenderer(m_renderer);

    TTF_Quit();
    IMG_Quit();/*Initialized IMG in this class, uninitialize as well*/

    if(m_instance != nullptr)
      delete m_instance;
  }

}//end Hearth
