/**
 * @file window.cpp
 * @brief 
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-09-23
 * @edited 2017-09-23
 */

#include "window.hpp"
#include "render.hpp"
#include "error.hpp"

namespace Hearth
{

  /**
   * @brief function that initializes the window with the given name
   *
   * @param name name for the window
   */
  void Window::_init(const std::string& name)
  {

    if(m_window != nullptr)
    {
      Error::printMessage("Error: Attempting to initialize a new window. Window has already been initialized");
      return;
    }

    //initialize the window here 
    Error::printMessage("---Initializing Window...");
    m_name = name;
    m_width = 800;
    m_height = 600;

    m_window = SDL_CreateWindow(m_name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN);

    if(m_window == nullptr)
    {
      Error::fatalError("SDL Window failed to be created!");
    }

    m_colorClear.set(255,255,255,255);

    Error::printMessage("---Initialized Window.");
  }


  /**
   * @brief function that uninitializes the window
   */
  void Window::_uninit()
  {
    if(m_window != nullptr)
      SDL_DestroyWindow(m_window);

    m_name = "";
    m_width = 0;
    m_height = 0;
  }


  /**
   * @brief clears the window and preps to draw onto it again
   */
  void Window::_clear()
  {
    SDL_SetRenderDrawColor(Render::Instance()->getRenderer(), m_colorClear.r, m_colorClear.g, m_colorClear.b, m_colorClear.a);
    SDL_RenderClear(Render::Instance()->getRenderer());
  }


  /**
   * @brief Renders the shapes stored in the renderer to the window
   */
  void Window::_render()
  {
    SDL_RenderPresent(Render::Instance()->getRenderer());
  }


  /**
   * @brief function that sets the dimensions of the window
   *
   * @param width the width dimensions of the window
   * @param height the height dimensions of the window
   */
  void Window::setDimensions(int width, int height)
  {
    m_width = width;
    m_height = height;

    SDL_SetWindowSize(m_window, m_width, m_height);
  }


  /**
   * @brief function that sets the dimensions of the window to full screen
   */
  void Window::setFullScreen()
  {
    SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN);
    SDL_GetWindowSize(m_window, &m_width, &m_height);
  }


  /**
   * @brief function that sets the dimenstions of the window to the full screen of the desktop
   */
  void Window::setFullScreenDesktop()
  {
    SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_GetWindowSize(m_window, &m_width, &m_height);
  }

}//end Hearth

