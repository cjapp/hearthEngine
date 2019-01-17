/**
 * @file main.cpp
 * @brief Main function for the space defense game
 * @author cjapp
 * @version 1.0.0
 * @date 2017-12-10
 * @edited 2017-12-10
 */

#include "hearth/application.hpp"
#include "menu.h"
#include "game.h"
#include "hearth/color.hpp"

Menu g_main;
Game g_level;

using namespace Hearth;

int main()
{
  Application::initialize("Space Defense", 800, 600);

  //load the textures into the game using the resourcemanager
  ResourceManager::loadTexture("Textures/spcDef_title.png","title");
  ResourceManager::loadTexture("Textures/spcDef_quit.png","quit_button");
  ResourceManager::loadTexture("Textures/spcDef_start.png","start_button");
  ResourceManager::loadTexture("Textures/enemy.png","enemy");
  ResourceManager::loadTexture("Textures/turret.png","turret");

  //load music file into game
  ResourceManager::loadMusic("Sound/music.wav","theme");

  //load the fonts into the game using the resourceManager
  ResourceManager::loadFont("Fonts/Digitalt.ttf", "DEFAULT");

  //set the background color of the window
  Color col(0,0,0,255);
  Window::Instance().setColor(col);
  Window::Instance().setFullScreenDesktop();


  //initialize the levels
  Application::Instance().AddState(&g_main);
  Application::Instance().AddState(&g_level);

  //set current state to main
  Application::Instance().switchState(0);

  Application::Instance().mainLoop();

  Application::unInitialize();

  return 0; 
}


