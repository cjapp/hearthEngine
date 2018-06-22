#include "ui.h"
#include "state.hpp"

namespace Hearth
{

  UI::UI():
    HObject()
  {

  }

  UI::UI(float x, float y)
  {
    setPosition(x,y);
  }

  UI::~UI()
  {

  }


  void UI::_init(State* s)
  {
    m_state = s; 
    init();
  }

  void UI::free()
  {

  }

}//end Hearth
