#ifndef GAME_HPP
#define GAME_HPP 

#include "engine/state.hpp"
#include "engine/uiText.h"

using namespace Hearth;

class Game : public State
{
 public: 
    Game();
    ~Game();

   void init();
   void update();
   void clear();

   UIText m_time; 

};


#endif /* GAME_HPP */
