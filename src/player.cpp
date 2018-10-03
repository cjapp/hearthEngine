/**
* @file player.cpp
* @brief Player class function definition file for the space defense game
* @author cjapp
* @version 1.0.0
* @date 2017-12-10
* @edited 2017-12-10
*/
#include "player.h"
#include "game.h"

#include "hearth/window.hpp"
#include "hearth/input.hpp"

#include <sstream>

using namespace std;

Player::Player():
  GameObject("Player",0.0,0.0),
  current(0)
{

}

Player::~Player()
{

}

void Player::init()
{
  Color white(255,255,255,255);
  initSprite("turret",200,100);
  current = 0;

  setPosition(Window::Instance().Width()/2 - 100,Window::Instance().Height() - 120);

}


void Player::update()
{
  //if the lmouse button is pressed, fire a projectile in that direction
  if(Input::mouseLPress())
  {
    stringstream st;
    st << "Projectile" << current;
    ammo = dynamic_cast<Projectile*>(goFindName(st.str()));
    if(ammo != nullptr)
    {
      ammo->fire((float)Input::mouseX(),(float) Input::mouseY());
      if(++current == 100)
        current = 0;
    }
  }

  if(Input::keyPress(INPUT::Button::ESC_KEY))
  {
    dynamic_cast<Game*>(m_state)->endGame();
  }
}


void Player::clear()
{

}
