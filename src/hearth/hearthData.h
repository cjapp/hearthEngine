/**
 * @file hearthData.h
 * @brief data file containing defined data struct 
 *       definitions for the entirity of the project
 * @author Colby Japp
 * @version 1.0.0
 * @date 2018-02-19
 * @edited 2018-02-19
 */
#ifndef HEARTHDATA_H
#define HEARTHDATA_H 

#include <cstdint>
#include <SDL2/SDL.h>
#include <cmath>

#ifndef PI
  #define PI 3.14159265
#endif

#define I64 int64_t
#define U64 uint64_t
#define I32 int32_t
#define U32 uint32_t
#define I16 int16_t
#define U16 uint16_t
#define F32 float

namespace Hearth
{

  struct Vector2
  {
    float x,y;

    Vector2(float xp = 0.0f, float yp = 0.0f):
      x(xp),y(yp)
    {
    }

    void set(float xp, float yp)
    {
      x = xp;
      y = yp;
    }

    Vector2& operator=(const Vector2& pos) 
    {
      x = pos.x;
      y = pos.y;
      return *this;
    }

    bool operator==(const Vector2& pos)
    { return (x == pos.x && y == pos.y);}

    bool operator!=(const Vector2& pos)
    { return (x != pos.x || y != pos.y);}

    static float distance(const Vector2& v1, const Vector2& v2)
    {
     float x = v2.x - v1.x; 
     float y = v2.y - v1.y;
     return sqrt((x*x) + (y*y));
    }

  };

  struct Rectangle
  {
    F32 x,y,w,h;

    Rectangle()
    {
      x = 0.0;
      y = 0.0;
      w = 0.0;
      h = 0.0;
    }

    Rectangle(F32 px, F32 py, F32 pw, F32 ph)
    {
      x = px;
      y = py;
      w = pw;
      h = ph;
    }

    //copy cstr
    Rectangle(const Rectangle& m)
    {
      x = m.x;
      y = m.y;
      w = m.w;
      h = m.h;
    }

  };

}//end Hearth

#endif /* HEARTHDATA_H */
