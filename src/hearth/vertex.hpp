/**
 * @file vertex.hpp
 * @brief Vertex header file that contains sprite vertex information
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-10-02
 * @edited 2017-10-02
 */
#ifndef VERTEX_HPP
#define VERTEX_HPP 

#include<GL/glew.h>
#include "color.hpp"//contains Color struct

namespace Hearth
{

  struct Position
  {
    float x;
    float y;
  };

  struct UV
  {
    float u;
    float v;
  };

  struct Vertex
  {
    Position  pos;
    Color     color;
    UV        uv;
  
    void setPosition(float x, float y)
    {
      pos.x = x;
      pos.y = y;
    }

    void setColor(ColorEnum col)
    {
      color.cToVC(col);
    }

    void setColor(char r, char g, char b, char a = 255)
    {
      color.set(r,g,b);
      color.a = a;
    }

    void setUV(float u, float v)
    {
      uv.u = u;
      uv.v = v;
    }

  };

}
#endif /* VERTEX_HPP */
