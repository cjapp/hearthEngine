/**
 * @file collisionHandler.cpp
 * @brief Collision handler class definition file for the collision
 *   system for the physics engine for the Hearth game engine;
 * @author Colby Japp
 * @version 1.0.0
 * @date 2018-01-15
 * @edited 2018-01-15
 */

#include "collisionHandler.h"
#include "error.hpp"

namespace Hearth
{

  CollisionHandler::CollisionHandler()
  {

  }


  CollisionHandler::~CollisionHandler()
  {

  }


  void CollisionHandler::initialize(std::vector<GameObject*> m_objects)
  {
    //go through the objects of the state and add 
    //  them to respective data structures
    for(int i = 0; i < m_objects.size(); i++)
    {
      addObject(m_objects[i]);
    }
  }


  void CollisionHandler::uninitialize()
  {
    //empty both of the object pointer arrays
    m_static.empty();
    m_dynamic.empty();
  }


  /**
   * @brief adds object to collision handler data structs
   *
   * @param obj obj to add to the data structs
   */
  void CollisionHandler::addObject(GameObject* obj)
  {
    Collider* tmp = obj->getCollider();
    if(tmp != nullptr)
    { 
      if(tmp->isSolid())
        m_static.push_back(obj);
      else
        m_dynamic.push_back(obj);
    }
  }


  /**
   * @brief check for collisions with the specified object
   *
   * @param obj the pointer to the object that is being checked for
   *
   * @return an object the collider hit
   */
  GameObject* CollisionHandler::checkCollisions(GameObject* obj)
  {
    //iterate through the static objects
    for(int i = 0; i < m_static.size(); i++)
    {
        if(checkCollision(obj, m_static[i]))
          return m_static[i];
    }

    //iterate through the dynamic objects
    for(int i = 0; i < m_dynamic.size(); i++)
    {
        if(checkCollision(obj, m_dynamic[i]))
          return m_dynamic[i];
    }

    return nullptr;
  }


  /**
   * @brief function that checks for collisions with the specified name
   *   with the provided object
   *
   * @param obj the object that is being checked for
   * @param tag the specified tag to check for colliding with
   *
   * @return an object pointer that matches the criteria
   */
  GameObject* CollisionHandler::checkCollisionsTag(GameObject* obj, std::string& tag)
  {
    //iterate through the static objects
    for(int i = 0; i < m_static.size(); i++)
    {
      if(m_static[i]->getTag() == tag)
      {
        if(checkCollision(obj, m_static[i]))
          return m_static[i];
      }

    }

    //iterate through the dynamic objects
    for(int i = 0; i < m_dynamic.size(); i++)
    {
      if(m_dynamic[i]->getTag() == tag)
      {
        if(checkCollision(obj, m_dynamic[i]))
          return m_dynamic[i];
      }

    }

    return nullptr;
  }


  /**
   * @brief function that checks for collisions with the specified name
   *   with the provided object
   *
   * @param obj the object that is being checked for
   * @param name the specified name to check for colliding with
   *
   * @return an object pointer that matches the criteria
   */
  GameObject* CollisionHandler::checkCollisionsName(GameObject* obj, std::string& name)
  {
    //iterate through the static objects
    for(int i = 0; i < m_static.size(); i++)
    {
      if(m_static[i]->getName() == name)
      {
        if(checkCollision(obj, m_static[i]))
          return m_static[i];
      }

    }

    //iterate through the dynamic objects
    for(int i = 0; i < m_dynamic.size(); i++)
    {
      if(m_dynamic[i]->getName() == name)
      {
        if(checkCollision(obj, m_dynamic[i]))
          return m_dynamic[i];
      }

    }

    return nullptr;
  }


/**
* @brief function that checks to see if there was a collision between the two objects
*
* @param A the fist of the two objects to check between
* @param B the second of the two objects to check between
*
* @return  true if a collision has occured between the two objects
*/
  bool CollisionHandler::checkCollision(GameObject* A, GameObject* B)
  {
    if(A == nullptr || B == nullptr)
    {
      Error::printMessage("Event::checkCollision() Error: Passed in a null pointer to check collision");
      return false;
    }

    //TODO: This is messy and there is a chance this will fail if one of the
    // objects is missing a collider
    return A->getCollider()->checkCollision(B->getCollider());
  }
}

