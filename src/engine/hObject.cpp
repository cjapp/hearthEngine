/**
 * @file hObject.cpp
 * @brief hObject class definition file for the hearth game engine
 * @author Colby Japp
 * @version 0.0.1
 * @date 2018-04-25
 * @edited 2018-04-25
 */
#include "hObject.h"
#include <cmath>/*sqrt(float) */

namespace Hearth
{


  HObject::HObject():
    m_id(0),
    m_transform(0.0f,0.0f),
    m_state(nullptr)
  {
    m_name = "";
    m_tag = "";
  }


  HObject::HObject(std::string name,float x, float y):
    m_name(name),
    m_transform(x,y),
    m_id(0),
    m_state(nullptr)
  {
    m_tag = "";
  }


  HObject::~HObject()
  {
    m_state = nullptr;
    m_id = 0;
    m_name = "";
    m_tag = "";
  }


  /**
   * @brief hObject translate function that uses the transform's translate function
   *
   * @param fx the amount of the directional translate in the x axis
   * @param fy the amount of the directional translate in the y axis
   */
  void HObject::translate(float fx, float fy)
  {
    //TODO include rigidbody/collider logic here to determine to move or not 
    m_transform.translate(fx,fy);
  }


  /**
   * @brief hObject move towards function towards an x and y
   *
   * @param dirx the x coordinate of the final direction
   * @param diry the y coordinate of the final direction
   * @param speed the speed of the object to move
   */
  void HObject::moveTowards(float dirx, float diry, float speed)
  {
    float r = sqrt(dirx*dirx + diry*diry);
    translate(dirx*speed/r, diry*speed/r); 
  }

}//end Hearth
