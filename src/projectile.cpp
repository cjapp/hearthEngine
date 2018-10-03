/**
* @file projectile.cpp
* @brief Projectile class function definitiion file for the space defense game
* @author cjapp
* @version 1.0.0
* @date 2017-12-10
* @edited 2017-12-10
*/
#include "projectile.h"
#include "hearth/color.hpp"
#include "hearth/window.hpp"
#include "hearth/hTime.h"

#include<iostream>
#include<cstdlib>

using namespace Hearth;


Projectile::Projectile():
  GameObject("Projectile",0.0,0.0),
  dirx(0),
  diry(0),
  fired(false)
{

}


Projectile::~Projectile()
{

}


void Projectile::init()
{
  Color white(255,255,255,255);
  initSprite(10,10,white);
  m_collider->setDimensions(10,10);
  setTag("projectile");

  speed = 50;
  reload();
}


void Projectile::update()
{
  if(fired)
  {
    if( m_transform.m_position.x > -10.0f && m_transform.m_position.x < Window::Instance().Width() && m_transform.m_position.y > -10.0f && m_transform.m_position.y < Window::Instance().Height())
    {
      moveTowards(dirx, diry, speed * Time::deltaTime() * 10);
    }
    else
    {
      reload();
    }
  }
}


void Projectile::clear()
{
  speed = 0.0;
  reload();
}


/**
* @brief Fires the projectile in the direction provided as parameters
*
* @param dx the x coordinate of to fire towards
* @param dy the y coordinate to fire towards
*/
void Projectile::fire(float dx, float dy)
{
  setPosition(Window::Instance().Width()/2,Window::Instance().Height() - 50);

   dirx = dx - m_transform.m_position.x;
   diry = dy - m_transform.m_position.y;

  fired = true;
}


/**
* @brief function that returns the projectile to its starting location
*        and stops its motion
*/
void Projectile::reload()
{
  setPosition(Window::Instance().Width()/2,Window::Instance().Height() + 100);
  dirx = 0.0;
  diry = 0.0;

  fired = false;
}



