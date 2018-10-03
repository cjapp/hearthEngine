/**
* @file enemy.cpp
* @brief Enemy class function definition file for the space defense game
* @author cjapp
* @version 1.0.0
* @date 2017-12-10
* @edited 2017-12-10
*/

#include "enemy.h"
#include "game.h"
#include "projectile.h"
#include "hearth/window.hpp"
#include "hearth/hTime.h"
#include "hearth/random.h"

#include <iostream>

using namespace Hearth;

Enemy::Enemy():
  GameObject("Enemy",0,0)
{

}


Enemy::~Enemy()
{

}



void Enemy::init()
{
  initSprite("enemy",200,100);
  m_collider->setDimensions(200,100);
  setTag("enemy");
  speed = 20;
  score = 10;
  moving = false;

  deaths = 0;

  ground = goFindName("ground");

  //set position to placeholder
  setPosition(Window::Instance().Width()/2, -200);
}


void Enemy::update()
{
  if(moving)
  {
    //check for collision against projectiles
    Projectile* tmp = dynamic_cast<Projectile*>(checkCollisionTag("projectile"));
    if(tmp != nullptr)
    {
      //destroy bullet "move back to start"
      tmp->reload();

      //get score reference and increment the score
      Game* st = dynamic_cast<Game*>(m_state);

      //highly unlikely
      if(st != nullptr)
        st->incrementScore(score);

      deaths++;
      if((deaths % 4) == 0)
        improve(5,5);

      moving = false;
      //return to start location
      startMoving();
    }

    //translate downward
    translate(0,speed * Time::deltaTime() * 5);

    //check for collisions with ground, end game if detected
    if(checkCollisionName("ground") != nullptr)
    {
      moving = false;
      startMoving();

      std::cout << "Collided with ground" << std::endl;
      Game* st = dynamic_cast<Game*>(m_state);
      if(st != nullptr)
        st->endGame();
      else
        std::cout << "Failed to convert m_state to Game*" << std::endl;
    }

  }
}


void Enemy::clear()
{
  speed = 0.0f;
  setPosition(Window::Instance().Width()/2, -200);
  moving = false;
  deaths = 0;

  score = 0;

}

/**
* @brief start moving begins the enemies movement downward at a random x position on the screen
*/
void Enemy::startMoving()
{
  if(!moving)
  {
    //select random location to start moving
    float x = (float) (Random::random() % (Window::Instance().Width()-200));

    setPosition(x, -200);

    moving = true;
  }
}

/**
* @brief Function that improves the enemy (increases speed and score)
*
* @param sp speed to increase the original by
* @param sc score to increase the original by
*/
void Enemy::improve(float sp, int sc)
{
  speed += sp;
  score += sc;
}
