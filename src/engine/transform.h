#ifndef TRANSFORM_H
#define TRANSFORM_H 

#include "hearthData.h"

namespace Hearth
{

  /**
   * @brief Position
   */
  struct Transform
  {
    public:

      Vector2 m_position;
      Vector2 m_pivot;
      float m_rotation;

      Transform(float xp,float yp, float rot = 0.0);

      Vector2& getPosition();
      void setPosition(float x, float y);
      void setPosition(Vector2& pos);

      Vector2& getPivot();
      void setPivot(float x, float y);

      float getRotation();
      void setRotation(float rot);
      
      void translate(float fx, float fy);

      void rotate(float deg);
  };


}//end Hearth

#endif /* TRANSFORM_H */
