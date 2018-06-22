/**
* @file enemy.h
* @brief Enemy class header file for the space defense game
* @author cjapp
* @version 1.0.0
* @date 2017-12-10
* @edited 2017-12-10
*/
#ifndef ENEMY_H
#define ENEMY_H 

#include "engine/gameObject.hpp"

using namespace Hearth;

class Enemy : public GameObject
{
  public:
    Enemy();
  ~Enemy();
 
  void init();
  void update();
  void clear();

  void improve(float sp, int sc);
  void startMoving();

  float speed; 
  bool moving;
  int score;
  int deaths;

  GameObject* ground;
 
};


#endif /* ENEMY_H */
