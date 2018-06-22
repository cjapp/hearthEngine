/**
* @file projectile.h
* @brief Projectile class header file for the space defense game
* @author cjapp
* @version 1.0.0
* @date 2017-12-10
* @edited 2017-12-10
*/
#ifndef PROJECTILE_H
#define PROJECTILE_H 

#include "engine/gameObject.hpp"
#include "engine/hObject.h"

using namespace Hearth;
using namespace std;

struct Position
{
  float x;
  float y;

  Position():x(0.0f),y(0.0f){}
};


class Projectile : public GameObject
{
  public:
    Projectile();
    ~Projectile();

    void init();
    void update(); 
    void clear();

    void fire(float x, float y);
    void reload();

    //direction the objects are travelling in update
    float speed;
    float dirx;
    float diry;
    Position targetPos;
    bool fired;
};

#endif /* PROJECTILE_H */
