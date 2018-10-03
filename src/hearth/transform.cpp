/**
* @file transform.cpp
* @brief the transform class definition file for the hearth engine
* @author Colby Japp
* @version 0.0.1
* @date 2018-05-21
* @edited 2018-05-21
*/
#include "transform.h"

namespace Hearth
{

  Transform::Transform(float xp,float yp, float rot):
    m_position(xp,yp),
    m_pivot(0.0f,0.0f),
    m_rotation(rot)
  {
  }

  Vector2& Transform::getPosition()
  {
    return m_position;
  }

  void Transform::setPosition(float x, float y)
  {
    m_position.set(x,y);
  }

  void Transform::setPosition(Vector2& pos)
  {
    m_position = pos;
  }

  Vector2& Transform::getPivot()
  {
    return m_pivot;
  }

  void Transform::setPivot(float x, float y)
  {
    m_pivot.x = x;
    m_pivot.y = y;
  }

  float Transform::getRotation()
  {
    return m_rotation;
  }

  void Transform::setRotation(float rot)
  {
    m_rotation = rot;
  }

  void Transform::translate(float fx, float fy)
  {
    m_position.x += fx;
    m_position.y += fy;
  }

  void Transform::rotate(float deg)
  {
    m_rotation += deg;
    
    if(m_rotation < 0)
      m_rotation += 360;

    if(m_rotation > 360)
      m_rotation -= 360;
  }

}//end Hearth

