/**
 * @file font.cpp
 * @brief the font class definition file for the Hearth engine
 * @author Colby Japp
 * @version 0.0.1
 * @date 2018-04-25
 * @edited 2018-04-25
 */

#include "font.h"
#include<stdio.h>

namespace Hearth
{

  Font::Font()
  {

  }

  Font::Font(std::string& fontPath):
    m_filePath(fontPath)
  {
    loadText(m_filePath);
  }

  Font::~Font()
  {
    free();
  }


  /**
   * @brief function for loading the ttf file using the textpath specified
   *
   * @param textpath the path to the ttf file in the project
   *
   * @return true if the load text succeeded, returns an error if it failed
   */
  bool Font::loadText(const std::string& textpath)
  {

    m_filePath = textpath; 

    if(getFont(28) == nullptr)
    {
      printf("Failed to load %s! SDL_ttf Error: %s\n",textpath.c_str(), TTF_GetError());
      return false;
    }
    return true;
  }


  /**
   * @brief function for getting the specified font of the specified size
   *
   * @param size the size of the font you want returned
   *
   * @return  the font of the size specified
   */
  TTF_Font* Font::getFont(unsigned int size)
  {

    //iterator for iterating through the fonts
    std::map<int, TTF_Font*>::iterator it;
    it = m_fontSizes.find(size);

    //if the iterator reaches end without finding the font-size, 
    //create the missing font-size and return it
    if (it == m_fontSizes.end())
    {
      TTF_Font* font = nullptr; 
      font = TTF_OpenFont(m_filePath.c_str(), size);

      if(font != nullptr)
        m_fontSizes.insert(std::pair<int, TTF_Font*>(size, font));

      return font;
    }

    //should've found the font size here
    return it->second;
  }


  /**
   * @brief clears the font and frees it from usage and memory
   */
  void Font::free()
  {
    //clear font map
    std::map<int, TTF_Font*>::iterator font_it = m_fontSizes.begin();
    while(font_it != m_fontSizes.end())
    {
      TTF_CloseFont(font_it->second);
      font_it++;
    }
    //clear the font map first elements 
    m_fontSizes.clear();
  }

}//end Hearth

