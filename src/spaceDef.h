/**
* @file spaceDef.h
* @brief Space Defense class header file for the space defense game
* @author cjapp
* @version 1.0.0
* @date 2017-12-10
* @edited 2017-12-10
*/
#ifndef SPACEDEF_H
#define SPACEDEF_H 

#include "engine/application.hpp"
#include "menu.h"
#include "game.h"

#include <vector>

using namespace Hearth;
using namespace std;

class SpaceDefense : public Application
{
  public:
    SpaceDefense();
    ~SpaceDefense();

    void initialize();
    void deinitialize();
    
    void setScore(int);
   
    Menu m_main;
    Game m_level; 
};


#endif /* SPACEDEF_H */
