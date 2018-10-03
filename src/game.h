/**
* @file game.h
* @brief Game class header file for the space defense game
* @author cjapp
* @version 1.0.0
* @date 2017-12-10
* @edited 2017-12-10
*/
#ifndef GAME_H
#define GAME_H 

#include "hearth/state.hpp"
#include "hearth/uiText.h"
#include "hearth/hTime.h"
#include "projectile.h"
#include "player.h"
#include "enemy.h"


using namespace Hearth;

class Game : public State
{
  public:
    Game();
    ~Game();

    void init();
    void update();
    void clear();

    void incrementScore(int);
    void endGame();

    Player player;
    GameObject ground;
    int scoreCount;

    Projectile barrel[100];
    Enemy     enemy1;
    Enemy     enemy2;
    UIText     score;

    UIText    mtime;

    Alarm enemyAlarm;
};

#endif /* GAME_H */
