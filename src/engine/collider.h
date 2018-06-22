/**
* @file collider.h
* @brief Collider header file class
* @author Colby Japp
* @version 1.0.0
* @date 2017-12-25
* @edited Wed 25 Apr 2018 11:21:01 AM PDT
*/
#ifndef COLLIDER_H
#define COLLIDER_H 

#include "hObject.h"
#include "transform.h"

namespace Hearth
{

  class Collider 
  {
    private:
      int m_width, m_height;

      Transform* m_transform;
  
      bool m_solid;

    public:
      Collider(HObject* obj);
      ~Collider();

      //upon creation, transform should point to something
      Transform* getTransform(){return m_transform;}

      bool isSolid() const {return m_solid;}
      void setSolid(bool s){m_solid = s;}

      void setDimensions(int w, int h);

      void setHeight(int h){m_height = h;}
      void setWidth(int w){m_width = w;}
      int getHeight()const {return m_height;}
      int getWidth() const {return m_width;}

      bool checkCollision(const Collider* c);
      bool aabbCheck(const Collider* c);
      bool seperateAxisCheck(const Collider* c);
  };

}//end Hearth

#endif /* COLLIDER_H */
