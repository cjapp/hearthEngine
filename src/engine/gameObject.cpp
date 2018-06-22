/**
 * @file gameObject.cpp
 * @brief game object definition file for the Hearth engine
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-09-22
 * @edited 2017-09-22
 */

#include "gameObject.hpp"
#include "state.hpp"
#include "ui.h"
#include "application.hpp"
#include "resourceManager.hpp"
#include "camera.h"
#include <cstdio>

namespace Hearth
{


  GameObject::GameObject():
    HObject(), 
    m_depth(0),
    m_height(0),
    m_width(0)
  {
    m_sprite = new Sprite();
    m_collider = new Collider(this);
  }


  GameObject::GameObject(std::string name, float x = 0.0f, float y = 0.0f):
    HObject(name,x,y), 
    m_height(0),
    m_width(0)
  {  
    m_sprite = new Sprite();
    m_collider = new Collider(this);
  }


  GameObject::~GameObject()
  {
    delete m_sprite;
    delete m_collider; 
    m_state = nullptr;
  }


  /**
   * @brief initialize the sprite with
   *
   * @param width the width of the sprite
   * @param height the height of the sprite
   * @param c the color of the sprite
   */
  void GameObject::initSprite(int width, int height, Color c)
  {
    if(m_sprite != nullptr)
      delete m_sprite;

    m_sprite = new Sprite();
    m_sprite->setDim(width,height);

    Color cl;
    m_sprite->setColor(c);
    m_sprite->setVisible(true);

    m_width = width;
    m_height = height;
    m_transform.setPivot(float(width)/2.0f,float(height)/2.0f);
  }

  /**
   * @brief function to the initialize the sprite with a specific texture
   *
   * @param txtName the name of the texture to lookup in the resource manager
   * @param width the width of the sprite
   * @param height the height of the sprite
   */
  void GameObject::initSprite(const std::string& txtName, int width, int height)
  {
    if(m_sprite != nullptr)
      delete m_sprite;

    m_sprite = new Sprite();
    m_sprite->setTexture(txtName);
    m_sprite->setDim(width,height);
    m_sprite->setVisible(true);

    m_width = width;
    m_height = height;
    m_transform.setPivot(float(width)/2.0f,float(height)/2.0f);
  }


  /**
   * @brief function used to draw the object
   */
  void GameObject::draw()
  {   
    if(m_state == nullptr)
    {
      return;
    }

    m_sprite->draw(m_transform, &(m_state->getCamera()));
  }


  /**
   * @brief function that can be overriden to initialize the gameobject
   */
  void GameObject::init()
  {

  }


  /**
   * @brief function that can be overriden to update the gameobject every frame
   */
  void GameObject::update()
  {

  }


  /**
   * @brief function that can be overriden to reset the gameobject
   */
  void GameObject::reset()
  {

  }


  /**
   * @brief function that finds the ui element with the specified name
   *
   * @param obj_name the name of the object to look for
   *
   * @return  a pointer to the ui element if found, else returns a nullptr
   */
  UI* GameObject::uiFindName(std::string obj_name)
  {
    if(m_state != nullptr)
      return m_state->nameUIFind(obj_name);

    return nullptr;
  }


  /**
   * @brief function that finds the game object with the specified name
   *
   * @param obj_name the name of the object to look for
   *
   * @return  a pointer to the game object to find, else returns nullptr
   */
  GameObject* GameObject::goFindName(std::string obj_name)
  {
    if(m_state != nullptr)
      return m_state->nameGOFind(obj_name);

    return nullptr;
  }


  /**
   * @brief function that finds the ui element with a given tag
   *
   * @param obj_tag the tag of the ui element to look for
   *
   * @return a pointer to the ui object to find, else returns nullptr
   */
  UI* GameObject::uiFindTag(std::string obj_tag)
  {
    if(m_state != nullptr)
      return m_state->tagUIFind(obj_tag);

    return nullptr;
  }


  /**
   * @brief function that finds the game object with the given tag
   *
   * @param obj_tag the tag of the game object to look for
   *
   * @return  a pointer to ui object to find, else returns nullptr
   */
  GameObject* GameObject::goFindTag(std::string obj_tag)
  {
    if(m_state != nullptr)
      return m_state->tagGOFind(obj_tag);

    return nullptr;
  }


  /**
   * @brief function that removes the gameobject from the state
   *
   * @param obj pointer of the object to remove from the state
   */
  void GameObject::Destroy(GameObject* obj)
  {
    if(m_state != nullptr)
      m_state->gDestroy(obj);
  }


  /**
   * @brief helper function that initializes the function and calls the overriden initializer
   *
   * @param s the state that includes the game object
   */
  void GameObject::_init(State* s)
  {
    //add this object to the scene/state
    m_state = s;
    init();
  }


  /**
   * @brief function that checks to see if this gameObject collided with the gameObject specified
   *
   * @param name name of the object to check for
   *
   * @return the pointer to the game object, returns nullptr if was not found
   */
  GameObject* GameObject::checkCollisionName(std::string name)
  {
    if(m_state != nullptr)
      return m_state->checkCollisionsName(this,name);

    return nullptr;

  }


  /**
   * @brief function that checks to see if this gameObject collided with the gameObject specified
   *
   * @param name name of the object to check for
   *
   * @return the pointer to the game object, returns nullptr if was not found
   */
  GameObject* GameObject::checkCollisionTag(std::string tag)
  {
    if(m_state != nullptr)
      return m_state->checkCollisionsTag(this,tag);

    return nullptr;

  }


  /**
   * @brief function that creates a new collider if one hasnt been created
   */
  void GameObject::setCollider()
  {
    if(m_collider != nullptr)
    {
      //shouldnt set collider if it already exists
      return;
    }

    m_collider = new Collider(this);

  }


  /**
   * @brief function that creates a new collider with a height and width
   *
   * @param h the height of the collider
   * @param w the width of the collider
   */
  void GameObject::setCollider(int h,int w)
  {
    if(m_collider == nullptr)
      m_collider = new Collider(this);

    m_collider->setDimensions(w,h);
  }


  /**
   * @brief function that returns if the object is solid or not
   *
   * @return  if the object is a solid or not
   */
  bool GameObject::isSolid() const
  {
    if(m_collider != nullptr)
      return m_collider->isSolid();

    return false;
  }


  /**
   * @brief function that sets the object as solid or not
   *
   * @param s boolean variable to set if the game object is solid or not, true for solid
   */
  void GameObject::setSolid(bool s)
  {
    if(m_collider != nullptr)
      m_collider->setSolid(s);
  }

}//end Hearth
