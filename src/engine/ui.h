/**
 * @file ui.h
 * @brief UI base class for the Hearth engine
 * @author cjapp
 * @version 1.0.0
 * @date 2017-12-02
 * @edited 2017-12-02
 */

#ifndef UI_H
#define UI_H 

#include "hObject.h"

#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>

namespace Hearth
{

  class State;

  class UI : public HObject
  {
    public:
      UI();
      UI(float x, float y);
      ~UI();

      virtual void draw() = 0;
      virtual void update() = 0; 
      virtual void init() = 0;

      virtual void free();
      void _init(State* s);
  };

}//end Hearth

#endif /* UI_H */
