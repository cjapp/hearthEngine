/**
* @file spaceDef.cpp
* @brief space defense class function file for the space defense game
* @author cjapp
* @version 1.0.0
* @date 2017-12-10
* @edited 2017-12-10
*/

#include "spaceDef.h"
#include "engine/color.hpp"
#include <cstdlib>
#include <ctime>


int score = 0;

SpaceDefense::SpaceDefense():
Application("Space Defense", 1260, 700)
{

}

SpaceDefense::~SpaceDefense()
{

}

void SpaceDefense::initialize()
{

  //load the textures into the game using the resourcemanager
  ResourceManager::loadTexture("Textures/spcDef_title.png","title");
  ResourceManager::loadTexture("Textures/spcDef_quit.png","quit_button");
  ResourceManager::loadTexture("Textures/spcDef_start.png","start_button");
  ResourceManager::loadTexture("Textures/enemy.png","enemy");
  ResourceManager::loadTexture("Textures/turret.png","turret");

  //load the fonts into the game using the resourceManager
  ResourceManager::loadFont("Fonts/Digitalt.ttf", "DEFAULT");

  //set the background color of the window
  Color c(0,0,0,255);
  Window::setColor(c);

  //initialize the levels
  AddState(&m_main);
  AddState(&m_level);

  //set current state to main
  switchState(0);

}

void SpaceDefense::deinitialize()
{

}



/**
* @brief Custom function to call before the state is switched to
*        update the scoreboard depending on the score of the previous game.
*
* @param score to use during the menu's update score function
*/
void SpaceDefense::setScore(int score)
{
  m_main.updateScore(score);
}
