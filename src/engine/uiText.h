#ifndef UITEXT_H
#define UITEXT_H 

#include "font.h"
#include "ui.h"
#include "color.hpp"
#include "hTexture.h"

namespace Hearth
{

  class UIText : public UI
  {
    private:
      void _update();
      Font* m_font;
      unsigned int m_size;

      Color m_color;
      HTexture m_texture;

      std::string m_text;

    public:
      UIText();
      UIText(int x, int y, std::string text);
      ~UIText();

      void draw();
      void update();
      void init();

      void free();

      void setText(const char* s); 
      std::string& getText(){return m_text;}

      void setColor(Color c){m_color = c;}
      Color getColor(){return m_color;}

      void setSize(unsigned int size){m_size = size;}
      unsigned int getSize(){return m_size;}

      void setFont(std::string fontName); 
      Font* getFont(){return m_font;} 

  };

}//end Hearth

#endif /* UITEXT_H */
