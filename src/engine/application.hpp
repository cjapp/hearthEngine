/**
 * @file application.hpp
 * @brief Application class declaration file for the hearth engine
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-08-31
 * @edited Thu 26 Apr 2018 03:05:53 PM PDT
 */
#ifndef APPLICATION_HPP
#define APPLICATION_HPP 


#include "resourceManager.hpp"
#include "physics.h"
#include "state.hpp"
#include "input.hpp"
#include "window.hpp"
#include "render.hpp"

#include<SDL2/SDL.h> /*SDL dependencies for creating a window, input, etc*/
#include<string>
#include<stack>

#define HEARTH_WINDOW_WIDTH 860
#define HEARTH_WINDOW_HEIGHT 640

namespace Hearth
{

  class Application
  {
    private:
      std::string m_appName;
      int m_height;
      int m_width;
      
      /*Denotes what the current state of game is*/
      bool m_init;
      bool m_running;
      State* m_currentState; 
      std::vector<State*> m_states; 

      /*Even though these are singletons, 
        just need to initialize them somewhere*/
      ResourceManager m_resourceManager;
      Input m_input;

    public:
      Application();

      static Application& Instance()
      {
        static Application instance;
        return instance;
      }

      static void endGame(){Instance().m_running = false;}

      void mainLoop();

      static void initialize(const char* name, int width, int height);
      void getInput();     
      void draw();        
      static void unInitialize();

      //functions to handle states of game
      State* getCurrentState(){return m_currentState;}
      void AddState(State* s);
      bool switchState(int stateIndex);
      bool switchState(char* name);

      Application(Application const&) = delete;
      void operator=(Application const&) = delete;

  };

}//end Hearth

#endif /* APPLICATION_HPP */
