/**
 * @file collisionHandler.h
 * @brief Collision handler class declaration file for the collision
 *    system for the physics engine.
 * @author Colby Japp
 * @version 1.0.0
 * @date 2018-01-15
 * @edited 2018-01-15
 */

#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H 

#include "gameObject.hpp"

#include<string>
#include<vector>

namespace Hearth{

  class CollisionHandler
  {
    private:
      //static object colliders remain same location in world
      std::vector<GameObject*> m_static;    
      //dynamic objects are able to move in the world
      std::vector<GameObject*> m_dynamic;

      bool checkCollision(GameObject* one, GameObject* two);

    public:
      CollisionHandler();
      ~CollisionHandler();

      void initialize(std::vector<GameObject*> objs);
      void uninitialize();

      //add objects to the data structures
      void addObject(GameObject* obj);

      //eventually need to return multiple gameobjects
      GameObject* checkCollisions(GameObject* obj);
      GameObject* checkCollisionsTag(GameObject* obj, std::string& tag);
      GameObject* checkCollisionsName(GameObject* obj, std::string& name);

  };

}

#endif /* COLLISIONHANDLER_H */
