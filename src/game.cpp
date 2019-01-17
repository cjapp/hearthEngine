/**
* @file game.cpp
* @brief Game class function file for the space defense game
* @author cjapp
* @version 1.0.0
* @date 2017-12-10
* @edited 2017-12-10
*/

#include "game.h"
#include "menu.h"
#include "hearth/application.hpp"
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iostream>

using namespace std;

Game::Game():
  State("game")
{

}

Game::~Game()
{

}

void Game::init()
{

  gAdd(&player);
  m_camera.init(((float)Window::Instance().Width()/2.0f),((float)Window::Instance().Height()/2.0f));

  gAdd(&ground);
  ground.setName("ground");
  Color white(255,255,255,255);
  ground.initSprite(Window::Instance().Width(),20,white);
  ground.getCollider()->setDimensions(Window::Instance().Width(),20);
  ground.setPosition(0,Window::Instance().Height() - 20);

  scoreCount = 0;

  uAdd(&score);
  score.setFont("DEFAULT");
  score.setSize(32);
  score.setColor(white);
  score.setPosition(10, 10);
  incrementScore(0);

  uAdd(&mtime);
  mtime.setFont("DEFAULT");
  mtime.setSize(24);
  mtime.setColor(white);
  mtime.setPosition(Window::Instance().Width() - 50,10);

  for(int i = 0; i < 100; i++)
  {
    gAdd(&(barrel[i]));
    stringstream st;
    st << "Projectile" << i;
    barrel[i].setName(st.str());
    st.str("");
  }

  gAdd(&(enemy1));

  gAdd(&(enemy2));

  enemyAlarm.setDuration(60.0f);
  enemyAlarm.start();
}


void Game::update()
{
  enemy1.startMoving();

  if(enemyAlarm.check())
  {
    enemy2.startMoving();
  }


  if((Time::timeRaw()%1000) == 0)
  {
    float time = Time::deltaTime();
    std::ostringstream ss;
    ss << time;
    std::string s(ss.str());

    mtime.setText(s.c_str());
  }
}


void Game::clear()
{
  for(int i = 0; i < 100; i++)
  {
    barrel[i].clear();
  }
 
  enemy1.clear();
  enemy2.clear(); 
}


/**
* @brief function that increments the score by a certain amount
*
* @param count the amount to increase the score by
*/
void Game::incrementScore(int count)
{
  scoreCount += count;
  stringstream st;
  st << "Score: " << scoreCount;

  score.setText(st.str().c_str());
}


/**
* @brief function that ends the game when an enemy lands on the ground
*/
void Game::endGame()
{
  _clear();

  //edit the score of global variable
  Menu::updateScore(scoreCount);
  SoundSystem::playMusic();
  Application::Instance().switchState(0);
}


