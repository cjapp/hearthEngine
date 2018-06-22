/**
 * @file state.cpp
 * @brief 
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-09-23
 * @edited 2017-09-23
 */

#include "application.hpp"
#include "hObject.h"
#include "ui.h"
#include "state.hpp"
#include "error.hpp"
#include <iostream>

namespace Hearth
{

  State::State():
    m_width(10),
    m_height(10),
    m_name("NULL"),
    m_isInitialized(false),
    m_objs(0)
  {
  }


  State::State(std::string name, int w /*100*/, int h/*100*/):
    m_width(w),
    m_height(h),
    m_name(name),
    m_isInitialized(false),
    m_objs(0)
  {
  }


  State::~State()
  {
  }


  /**
   * @brief function for drawing the elements(gameobjects and ui) to the screen
   */
  void State::draw()
  {
    //draw GameObjects first
    for(unsigned int i = 0; i < m_gameObjects.size(); i++)
      m_gameObjects[i]->draw();

    for(unsigned int i = 0; i < m_ui.size(); i++)
      m_ui[i]->draw();
  }


  /**
   * @brief function that needs to be overriden by the inheriting state
   */
  void State::update()
  {

  }


  /**
   * @brief function that adds a gameobject to the state to interact with
   *
   * @param obj obj to pass to the state class
   *
   * @return returns a pointer to the game object
   */
  GameObject* State::gAdd(GameObject* obj)
  {
    if(obj != nullptr)
    {
      obj->setState(this);
      m_gameObjects.push_back(obj);

      //add object to collisionhandler
      m_collisionHandler.addObject(obj);

      m_objs++;
      obj->setID(m_objs);
    }
    return obj;
  }


  /**
   * @brief function that destroys the specified gameobject by the pointer
   *
   * @param obj the obj pointer pointing to the object to destroy
   */
  void State::gDestroy(GameObject* obj)
  {
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
      if(m_gameObjects[i]->getID() == obj->getID())
      {
        m_gameObjects.erase(m_gameObjects.begin() + i);
        break; 
      }
    }
    return;
  }


  /**
   * @brief function for adding a ui element to the state
   *
   * @param obj the ui object pointer to add to the state
   *
   * @return a UI pointer to the object passed
   */
  UI* State::uAdd(UI* obj)
  {
    if(obj != nullptr)
    {
      obj->setState(this);
      m_ui.push_back(obj);
      m_objs++;
      obj->setID(m_objs);
    }

    return obj;
  }


  /**
   * @brief function for removing the ui element from the state
   *
   * @param obj ui object pointer to element that needs to be removed
   */
  void State::uDestroy(UI* obj)
  {
    for(int i = 0; i < m_ui.size(); i++)
    {
      if(m_ui[i]->getID() == obj->getID())
      {
        m_ui.erase(m_ui.begin() + i);
        break; 
      }
      //failed to delete object
    }
    return;
  }



  /**
   * @brief state's process input for calling all the objects personal 
   *   update function
   */
  void State::_processInput()
  {

    update();

    //iterate through the entirity of the ui
    unsigned it = 0;
    while(it < m_ui.size())
    {
      m_ui.at(it)->update();
      it++;
    }

    //iterate through the entirity of the m_gameObjects
    it = 0;
    while(it < m_gameObjects.size())
    {
      m_gameObjects.at(it)->update();
      it++;
    }

  }


  /**
   * @brief clears the state of what it needs to, objects, etc
   */
  void State::_clear()
  {
    printf("---Removing state %s...\n", m_name.c_str());
    if(m_isInitialized)
    {

      clear();

      printf("----Objects being cleared = %d\n",m_objs);

      m_isInitialized = false;
      m_objs = 0;

      m_collisionHandler.uninitialize();
      m_gameObjects.clear();
      m_ui.clear();
    }
  }


  /**
   * @brief initializes the state of
   */
  void State::_init()
  {
    Error::printMessage("--Initializing " + m_name + "...");
    m_camera.init(0.0f,0.0f);
    init();

    //initialize the ui elements
    for(int i = 0; i < m_ui.size(); i++)
    {
      m_ui[i]->_init(this);
    }

    //initialize the game objects
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
      m_gameObjects[i]->_init(this);
    }

    m_isInitialized = true;
  }


  /**
   * @brief function that needs to be overriden and is called from the _clear
   */
  void State::clear()
  {

  }


  UI* State::nameUIFind(std::string& objName)
  {
    for(unsigned int i = 0; i < m_ui.size(); i++)
    {
      if(m_ui[i]->getName() == objName)
      {
        printf("Found gameObject <%s>\n",objName.c_str());  
        return m_ui[i];
      }
    }

    printf("Failed to find object with name %s\n",objName.c_str());
    return nullptr;
  }


  UI* State::tagUIFind(std::string& objTag)
  {
    for(unsigned int i = 0; i < m_ui.size(); i++)
    {
      if(m_ui[i]->getTag() == objTag)
      {
        return m_ui[i];
      }
    }

    printf("Failed to find UI with tag %s\n", objTag.c_str());
    return nullptr;
  }

  GameObject* State::nameGOFind(std::string& objName)
  {
    for(unsigned int i = 0; i < m_gameObjects.size(); i++)
    {
      if(m_gameObjects[i]->getName() == objName)
      {
        return m_gameObjects[i];
      }
    }

    printf("Failed to find Gameobject with name %s\n",objName.c_str());
    return nullptr;
  }

  GameObject* State::tagGOFind(std::string& objTag)
  {
    for(unsigned int i = 0; i < m_gameObjects.size(); i++)
    {
      if(m_gameObjects[i]->getTag() == objTag)
      {
        return m_gameObjects[i];
      }
    }

    printf("Failed to find Gameobject with tag %s\n",objTag.c_str());
    return nullptr;
  }

  /**
   * @brief Iterate through all game objects and check for collisions
   *
   * @param obj gameObject to check for collisions
   *
   * @return pointer to the other colliding gameobject
   */
  GameObject* State::checkCollisions(GameObject* obj)
  {
    return m_collisionHandler.checkCollisions(obj);
  }


  /**
   * @brief Iterate through game objects of with a particular tag and check 
   *        for collisions
   *
   * @param obj gameObject to check for collisions
   * @param tag tag to check for
   *
   * @return pointer to the other colliding gameobject
   */
  GameObject* State::checkCollisionsTag(GameObject* obj, std::string& tag)
  {
    return m_collisionHandler.checkCollisionsTag(obj,tag);
  }


  /**
   * @brief Iterate through game objects of with a particular name and check 
   *        for collisions
   *
   * @param obj gameObject to check for collisions
   * @param name name to check for
   *
   * @return pointer to the other colliding gameobject
   */
  GameObject* State::checkCollisionsName(GameObject* obj, std::string& name)
  {
    return m_collisionHandler.checkCollisionsName(obj,name);
  }


  /**
   * @brief helper function for calling the app endgame function
   */
  void State::endGame()
  {

    if(m_app != nullptr)
      m_app->endGame();
  }

}//end Hearth



