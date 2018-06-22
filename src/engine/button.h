/**
 * @file button.h
 * @brief Button class for the hearth engine
 * @author cjapp
 * @version 1.0.0
 * @date 2017-12-02
 * @edited Wed 25 Apr 2018 11:20:12 AM PDT
 */

#ifndef BUTTON_H
#define BUTTON_H 

#include "image.h"
#include "sprite.hpp"
#include "color.hpp"

#include <string>

namespace Hearth
{
  typedef void (*Button_Action)(void);

  class Button : public Image
  {
    public:
      Button();
      Button(int x, int y, int h, int w);
      ~Button();

      void init();
      void draw();
      void update();

      void setAction(Button_Action ac = nullptr);

      bool pressed(){return m_pressed;}
      bool hovered(){return m_hoverOver;}

    protected:
      Color m_colorChange; 
      bool m_hoverOver;
      bool m_pressed;


      Button_Action m_action;
      bool m_connected;

      /*Protected Functions*/
      void _doAction();
      void _hoverOver(int x,int y);

  };

}//end Hearth

#endif /* BUTTON_H */
