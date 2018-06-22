/**
* @file font.h
* @brief Font class declaration file for the Hearth engine
* @author Colby Japp
* @version 0.0.1
* @date 2018-04-25
* @edited 2018-04-25
*/
#ifndef FONT_H
#define FONT_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>

#include<string>
#include<map>

namespace Hearth
{

  class Font
  {
    private:
      std::string m_filePath;
      std::map<int, TTF_Font*> m_fontSizes;

    public:
      Font();
      Font(std::string& fontPath);
      ~Font();

      TTF_Font* getFont(unsigned int size);

      bool loadText(const std::string& textPath);
      void free();

  };


}//end Hearth

#endif /* FONT_H */
