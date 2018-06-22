/**
* @file camera.h
* @brief Camera object declaration file for the hearth engine
* @author Colby Japp
* @version 0.0.1
* @date 2018-04-25
* @edited 2018-04-25
*/
#ifndef CAMERA_H
#define CAMERA_H 

#include "hObject.h"
#include "window.hpp"

namespace Hearth
{

  class Camera : public HObject
  {
    private:
     //window variables for ease of math operations
     float m_winW;
     float m_winH; 

    public:
      Camera();
      ~Camera();

      void init(float x, float y);
      void deinit();

      //math for rendering
      float offsetX()const{return m_winW - m_transform.m_position.x;}
      float offsetY()const{return m_winH - m_transform.m_position.y;}

      void windowResized();
  };

}//end namespace Hearth

#endif /* CAMERA_H */
