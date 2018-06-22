/**
 * @file state.hpp
 * @brief State class header file 
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-09-22
 * @edited 2017-09-22
 */

#ifndef STATE_HPP
#define STATE_HPP 

#include<vector>
#include<string>

#include "gameObject.hpp"
#include "collisionHandler.h"
#include "camera.h"
#include "input.hpp"
#include "render.hpp"

#define HEARTH_DEPTH_COUNT 10


namespace Hearth
{

  class UI;
  class Application;

  class State
  {
    protected:

      //level dimensions
      unsigned int m_width;
      unsigned int m_height;
      CollisionHandler m_collisionHandler;

      std::string m_name;

      Camera m_camera;

      std::vector<GameObject*> m_gameObjects;
      std::vector<UI*> m_ui;
      unsigned int m_objs;

      Application* m_app;

      bool m_isInitialized;

      virtual void clear();
      virtual void init() = 0;    

    public:
      State();
      State(std::string name, int w = 100, int h = 100);
      ~State();

      //Run a particular input type
      virtual void draw();
      virtual void update();

      void _processInput();
      void _init();
      void _clear();

      bool isInitialized(){return m_isInitialized;};
      std::string& getName(){return m_name;}
      CollisionHandler& getCollisionHandler(){return m_collisionHandler;}

      Camera& getCamera(){return m_camera;}

      //Functions for managing the vector object
      void gDestroy(GameObject* obj);
      GameObject* gAdd(GameObject* obj);

      void uDestroy(UI* obj);
      UI* uAdd(UI* obj);

      UI* nameUIFind(std::string& objName);
      GameObject* nameGOFind(std::string& objName);

      UI* tagUIFind(std::string& tag);
      GameObject* tagGOFind(std::string& tag);

      GameObject* checkCollisions(GameObject* obj);
      GameObject* checkCollisionsTag(GameObject* obj, std::string& tag);
      GameObject* checkCollisionsName(GameObject* obj, std::string& name);

      void setApplication(Application* ap){m_app = ap;}
      void endGame();

  };

}//end Hearth

#endif /* STATE_HPP */
