/**
 * @file camera.cpp
 * @brief Camera class definition file for the Hearth Engine
 * @author Colby Japp
 * @version 0.0.1
 * @date 2018-04-25
 * @edited 2018-04-25
 */
#include "camera.h"

namespace Hearth
{

  Camera::Camera():
    HObject(),
    m_winW(0.0f),
    m_winH(0.0f)
  {

  }

  Camera::~Camera()
  {

  }


  /**
   * @brief camera initializer function called in its state initialization function
   *
   * @param x the x world coordinate the object is located
   * @param y the y world coordinate the object is located
   */
  void Camera::init(float x, float y)
  {
    m_transform.m_position.x = x;
    m_transform.m_position.y = y;

    //apply so camera is center of screen
    windowResized();
  }


  /**
   * @brief camera deinitializer if there is no need for the camera any more
   */
  void Camera::deinit()
  {
    m_winW = 0.0f;
    m_winH = 0.0f;
  }


  /**
   * @brief function that recenters the camera when the window is resized
   */
  void Camera::windowResized()
  {
    m_winW = float (Window::Instance()->Width()/2.0f);
    m_winH = float (Window::Instance()->Height()/2.0f);
  }
}
