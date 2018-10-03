/**
* @file menu.h
* @brief Menu class declaration file for the space defense game
* @author cjapp
* @version 1.0.0
* @date 2017-12-10
* @edited 2017-12-10
*/
#ifndef MENU_H
#define MENU_H 

#include "hearth/state.hpp"
#include "hearth/button.h"
#include "hearth/uiText.h"

#include<string>
#include<utility>
#include<vector>

using namespace Hearth;
using namespace std;

#define SCORECOUNT 10


class Menu : public State
{
  public:
    Menu();
    ~Menu();

    void init();
    void update();
    void clear();

    void updateScoreBoard();
    static void updateScore( int score);
    static void start();
    static void quit();

    //UI Elements
    GameObject m_title;
    Button m_start;
    Button m_quit; 

    //scores
    static int scores[SCORECOUNT];
    UIText scoresText[SCORECOUNT];
    
    static bool boardUpdate;
};

#endif /* MENU_H */
