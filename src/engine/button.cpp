/**
 * @file button.cpp
 * @brief Button class function definitions
 * @author cjapp
 * @version 1.0.0
 * @date 2017-12-03
 * @edited Wed 25 Apr 2018 11:20:29 AM PDT
 */

#include "button.h"
#include "input.hpp"

namespace Hearth
{

  Button::Button():
    Image(),
    m_colorChange(255,127,255,255),
    m_hoverOver(false),
    m_pressed(false),
    m_connected(false)
  {

  }


  Button::Button(int x, int y, int h, int w):
    Image(x,y,h,w),
    m_colorChange(255,127,255,255),
    m_hoverOver(false),
    m_pressed(false),
    m_connected(false)
  {

  }


  Button::~Button()
  {
    setAction();
  }


  /**
   * @brief button initialization function that can be overrided
   */
  void Button::init()
  {

  }


  /**
   * @brief function that draws the button on the screen
   */
  void Button::draw()
  {
    m_sprite->draw(m_transform,nullptr);
  }


  /**
   * @brief function that checks to see if any of the conditions are met
   */
  void Button::update()
  {
    m_pressed = false;
    m_hoverOver = false;

    _hoverOver(Input::mouseX(), Input::mouseY());
    if(m_hoverOver && Input::mouseLPress())
    {
      m_pressed = true;
      _doAction();
    }
  }


  /**
   * @brief sets the action of the button to a function
   *
   * @param ac the button action function(pointer for a void function)
   */
  void Button::setAction(Button_Action ac)
  {
    m_action = ac;

    if(m_action != nullptr)
      m_connected = true; 
    else
      m_connected = false; 
  }

  /*******************************
   *
   * Protected Functions
   *
   ********************************/


  /**
   * @brief function for the action
   */
  void Button::_doAction()
  {
    if(m_connected)
      m_action();
  }


  /**
   * @brief function that checks to see if the mouse is hovering over the button
   *
   * @param x is the x location of the mouse on the screen
   * @param y is the y location of the mouse on the screen
   */
  void Button::_hoverOver(int x, int y)
  {
    if(x > m_transform.m_position.x && x < (m_transform.m_position.x + m_width))
    {
      if(y > m_transform.m_position.y && y < (m_transform.m_position.y + m_height))
        m_hoverOver = true;
    }
  }


}//end Hearth

