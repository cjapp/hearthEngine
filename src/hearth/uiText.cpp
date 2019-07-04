#include "uiText.h"
#include "resourceManager.hpp"

#include<stdio.h>

namespace Hearth
{

  UIText::UIText():
    m_font(nullptr),
    m_size(8)
  {
    setText(" ");
  }

  UIText::UIText(int x, int y, std::string text):
    UI(x,y),
    m_font(nullptr),
    m_size(28)
  {
    free();
    setText(text.c_str());
  }

  UIText::~UIText()
  {
    m_font = nullptr;
  }

  void UIText::setFont(std::string fontName)
  {
    Font* prev = m_font;

    //set font to ResourceManager::getFont(fontName);
    m_font = ResourceManager::getFont(fontName);
    if(m_font == nullptr)
    {
      //error occurred, font was not set to fontNAME
      printf("Couldn't find the font <%s>.",fontName.c_str());

      //set font to backup
      m_font = prev;
      return;
    }

    //update the texture with new font;
    _update();
  }

  void UIText::setText(const char* txt)
  {
    m_text = std::string(txt);

    //update box with new information
    _update();
  }

  void UIText::draw()
  {
    m_texture.render(m_transform.m_position.x, m_transform.m_position.y /*clip == NULL*/);
  }

  void UIText::update()
  {

  }

  void UIText::init()
  {

  }

  void UIText::free()
  {
    m_texture.free();
  }

  void UIText::_update()
  {
    update();

    if(m_font != nullptr)
      m_texture.loadFromFont(*this);
  } 

}//end Hearth
