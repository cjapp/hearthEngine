/**
* @file menu.cpp
* @brief Menu class function definition file for the space defense game
* @author cjapp
* @version 1.0.0
* @date 2017-12-10
* @edited 2017-12-10
*/

#include "menu.h"
#include "hearth/color.hpp"
#include "hearth/application.hpp"

#include<sstream>
#include<iostream>

using namespace std;

int Menu::scores[SCORECOUNT] = {0,0,0,0,0,0,0,0,0,0};
bool Menu::boardUpdate = false;

Menu::Menu():
  State("Menu")
{

}


Menu::~Menu()
{

}

void Menu::init()
{
  Color col(255,255,255,255);

  gAdd(&m_title);
  m_title.initSprite("title", 400, 200);
  m_title.setPosition(50,50);
  m_title.setName("Title");

  uAdd(&m_start);
  m_start.initSprite("start_button",200,100);
  m_start.setPosition(275,350);
  m_start.setName("start");
  m_start.setAction(start);

  uAdd(&m_quit);
  m_quit.initSprite("quit_button",200,100);
  m_quit.setPosition(275, 500);
  m_quit.setName("quit");
  m_quit.setAction(quit);


  int x = (Window::Instance().Width()/5 * 3);
  int y = (Window::Instance().Height()/4);


  for(int i = 0; i < SCORECOUNT; i++)
  {
    scores[i] = 0;
    UIText* score = &(scoresText[i]);
    uAdd(score);

    //set the Text ui
    score->setFont("DEFAULT");
    score->setSize(28);
    score->setColor(col);
    //set the position of the score
    score->setPosition(x, y + (i*30));
  }

  boardUpdate = true;
}

void Menu::update()
{

  if(boardUpdate == true)
    updateScoreBoard();

}

void Menu::clear()
{

}

/**
* @brief update the score with the newscore global
*
* @param sc the score to pass in and update
*/
void Menu::updateScore(int sc)
{
  int i = 0;
  if(sc > scores[SCORECOUNT])
  {
    boardUpdate = true;

    //search for spot on table
    for(i = SCORECOUNT - 2; i >= 0; i--)
    {
      if(sc < scores[i])
      {
        scores[i+1] = sc;
        return;
      }
      else
      scores[i + 1] = scores[i];
    }
    scores[0] = sc;
 }
}


/**
* @brief updates the score board uiTextboxes with the
*        contents stored in the score array
*/
void Menu::updateScoreBoard()
{
  //update the score text ui
  for(int i = 0; i < SCORECOUNT; i++)
  {
    UIText* score = &(scoresText[i]);

    //push entries onto string
    stringstream text;
    text << "Score" << i << " : " << scores[i];
    score->setText((text.str()).c_str());
  }

  boardUpdate = false;
}

/**
* @brief function that stars the game (pressing start button)
*/
void Menu::start()
{
  cout << "Starting game" << endl; 
  Application::Instance().switchState(1);
}

void Menu::quit()
{
  cout << "Ending game" << endl;
  Application::endGame();
}
