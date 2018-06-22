/**
* @file player.h
* @brief Player class header file for the space defense game
* @author cjapp
* @version 1.0.0
* @date 2017-12-10
* @edited 2017-12-10
*/
#ifndef PLAYER_H
#define PLAYER_H 

#include "engine/gameObject.hpp"
#include "projectile.h"

using namespace Hearth;

class Player : public GameObject
{
  public:
    Player();
    ~Player();

    void init();
    void update();
    void clear();

    int current;
    Projectile* ammo;
};

#endif /* PLAYER_H */
