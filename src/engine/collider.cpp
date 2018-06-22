/**
 * @file collider.cpp
 * @brief Collider function definition file
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-12-25
 * @edited Wed 25 Apr 2018 11:20:47 AM PDT
 */

#include "collider.h"

namespace Hearth
{

  Collider::Collider(HObject* obj):
    m_width(),
    m_height(),
    m_transform(&(obj->getTransform()))
  {

  }

  Collider::~Collider()
  {
    m_transform = nullptr;
  }


  /**
   * @brief sets the dimensions in pixels of the collider
   *
   * @param w the width in pixels
   * @param h the height in pixels
   */
  void Collider::setDimensions(int w, int h)
  {
    setWidth(w);
    setHeight(h);
  }


  /**
   * @brief function that determines if a collision was 
   *        detected by either collider
   *
   * @param c the other collider to check for
   *
   * @return true if the colliders collided
   */
  bool Collider::checkCollision(const Collider* c)
  {
    return aabbCheck(c);
  }


  /**
   * @brief function that determines if a collision was 
   *        detected by either collider
   *
   * @param c the other collider to detect
   *
   * @return true if a collision occurred between the two
   */
  bool Collider::aabbCheck(const Collider* c)
  {
    //TODO change this to work for another
    if(c == nullptr && m_transform == nullptr && c->m_transform == nullptr)
      return false;

    //check collision for rectangle colliders

    int leftA,leftB;
    int rightA,rightB;
    int topA, topB;
    int botA, botB;

    Vector2 tA = m_transform->getPosition();
    Vector2 tB = c->m_transform->getPosition();

    //calculate side values for BB A
    leftA = tA.x;
    rightA = leftA + m_width; 
    botA = tA.y;
    topA = botA + m_height;

    //calculate side values  for BB B
    leftB = tB.x;
    rightB = leftB + c->getWidth(); 
    botB = tB.y;
    topB = botB + c->getHeight();

    if( botA >= topB ) { return false; } 
    if( topA <= botB ) { return false; } 
    if( rightA <= leftB ) { return false; } 
    if( leftA >= rightB ) { return false; } 

    //If none of the sides from A are outside B 
    return true;
  }


  /**
   * @brief function that checks for a collision between 
   *        two colliders using the seperate axis theorem
   *
   * @param c the other collider to use to check for
   *
   * @return true if the colliders collided, false otherwise
   */
  bool Collider::seperateAxisCheck(const Collider* c)
  {
    if(c != nullptr)
      return false;
  }

}//end Hearth


