
#include "game.hpp"
#include "engine/time.h"
#include <sstream>

using namespace Hearth;

Game::Game():
  State("Game",800,800),
  m_time(400,400,"DEFAULT")
{

}


Game::~Game()
{

}


void Game::init()
{
  uAdd(&m_time);
  Color white(ColorEnum::RED);
  m_time.setFont("DEFAULT");
  m_time.setColor(white);
  m_time.setSize(24);

}


void Game::update()
{
  //get time and convert to a string
  float time = (float)Time::deltaTime()/1000.0f;
  std::ostringstream ss;
  ss << time;
  std::string s(ss.str());

  m_time.setText(s.c_str());

  Uint32 timeout = SDL_GetTicks() + 100;
  while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
    /* ... do work until timeout has elapsed */
  }


}


void Game::clear()
{

}


