/**
 * @file application.cpp
 * @brief Application function file with 
 *        application class definitions
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-08-31
 * @edited Thu 26 Apr 2018 03:06:30 PM PDT
 */


#include "application.hpp"
#include "error.hpp"
#include "color.hpp"
#include "hTexture.h"
#include "font.h"
#include "hTime.h"
#include "random.h"
#include "soundSystem.h"

#include<time.h>
#include<string>
#include<vector>

namespace Hearth
{

  Application::Application():
    m_appName(""),
    m_width(0),
    m_height(0)
  {
    m_init = false;
    m_running = true;
    m_currentState = nullptr;
  }


  /**
   * @brief the main game loop where the game renders, gets input, updates, etc
   */
  void Application::mainLoop()
  {
    if(m_currentState == nullptr)
      return;

    int count = 0;

    while(m_running)
    {

      Time::captureTime();

      //TODO: Handle this in a load level function possibly
      if(!(m_currentState->isInitialized()))
        m_currentState->_init();

      //process input handles the current window functionality and m_input
      getInput();

      //process input made previously and apply to current state
      m_currentState->_processInput(); 

      //resetPressed keys after initial press is registered
      m_input.resetPress();

      draw();

      //frame rate handling
      if( Time::frameTime() < (1000 / FRAMES_PER_SECOND))
      {
        SDL_Delay( (1000/FRAMES_PER_SECOND) - Time::frameTime() );
      }
    }  
  }


  /**
   * @brief function that initializes the application
   *
   * @param name sets the name of the application
   * @param width sets the width of the window
   * @param height sets the height of the window
   */
  void Application::initialize(const char* name, int width, int height)
  {
    Error::printMessage("--Initializing Core Systems...");

    std::string strname(name);
    Instance().m_appName = strname;
    Instance().m_width = width;
    Instance().m_height = height;

    if(SDL_Init(SDL_INIT_VIDEO) > 0)
    {
      //failed to init SDL 
    } 

    Random::seed(time(NULL));
    Window::init(strname);
    Window::Instance().setDimensions(width, height);
    Render::Instance()->init();
    SoundSystem::init();

    Instance().m_input.init(); 

    Instance().m_init = true;
    Error::printMessage("--Initializing Core Systems complete.");
  }


  /**
   * @brief function that uninitializes the game when it ends
   */
  void Application::unInitialize()
  {
    Error::printMessage("--Uninitializing Core Systems...");

    Instance().m_currentState = nullptr;

    //clear the state stack
    for(int i = Instance().m_states.size()-1; i >= 0; i--)
    {
      Instance().m_states[i]->_clear();
    }
    Instance().m_states.clear();

    ResourceManager::clear();

    Render::Instance()->uninit();/*IMG_QUIT, TTF_QUIT */
    Window::uninit();
    SoundSystem::uninit();

    SDL_Quit();
    Error::printMessage("--Uninitialized Core Systems...");
  }

  
  /**
   * @brief gets input via SDL_event manager and processes it for 
   *        the input manager
   */
  void Application::getInput()
  {
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
      switch(event.type)
      {
        case SDL_QUIT:
          endGame();
          break;
        default:
          m_input.handleInput(event);
          break;
      }
    }
  }


  /**
   * @brief renders the scene
   */
  void Application::draw()
  {
    //clear screen to prepare for drawing
    Window::clear();

    //draw the state/scene
    if(m_currentState != nullptr)
      m_currentState->draw();

    //render the screen
    Window::render();

  }


  /**
   * @brief add a state to the application state stack
   *
   * @param s the state pointer to add to the state stack
   */
  void Application::AddState(State* s)
  {
    if(s != nullptr)
    {
      m_states.push_back(s);

      if(m_currentState == nullptr)
        m_currentState = s;
    }
  }


  /**
   * @brief switches the state of the application to the specified index
   *
   * @param i the specified index
   *
   * @return  true if switching the state succeeded or not
   */
  bool Application::switchState(int i)
  {
    if(i >= 0 && i < m_states.size())
    {
      m_currentState = m_states[i];
      return true;
    }

    return false;
  } 



  /**
   * @brief function that switches the state by name
   *
   * @param name the name of the state you wish to switch to
   *
   * @return true if switching state succeeded
   */
  bool Application::switchState(char* name )
  {
    std::string strName(name);

    for(int i = 0; i < m_states.size(); i++)
    {
      if(m_states[i]->getName() == strName)
      {
        return switchState(i);
      }
    }
    return false;
  }

}//end Hearth
