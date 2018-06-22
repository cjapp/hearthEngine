#include "test.h"

#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iostream>

using namespace Hearth;
using namespace std;

Test::Test():
  State("test")
{

}


Test::~Test()
{

}

void Test::init()
{
  //walls[4], ball

  Color grey(125,125,125,255);
  for(int i = 0; i < 4; i++)
  {
    gAdd(&(walls[i]));
    stringstream st;
    st << "Wall" << i;
    walls[i].setName(st.str());
    st.str("");
  }

  walls[0].initSprite(Window::Instance()->Width(),20,grey);
  walls[0].setPosition(0,0); 
  walls[1].initSprite(Window::Instance()->Width(),20,grey);
  walls[1].setPosition(0,Window::Instance()->Height() - 20); 
  walls[2].initSprite(20,Window::Instance()->Height(),grey);
  walls[2].setPosition(0,0); 
  walls[3].initSprite(20,Window::Instance()->Height(),grey);
  walls[3].setPosition(Window::Instance()->Width()-20,0); 

  gAdd(&ball);
  ball.init();
}


void Test::update()
{
  if(Input::keyPress(INPUT::ESC_KEY))
  {
    endGame();
  }
}
