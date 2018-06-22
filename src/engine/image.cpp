/**
* @file image.cpp
* @brief Image class definition file for the hearth engine
* @author Colby Japp
* @version 0.0.1
* @date 2018-04-25
* @edited 2018-04-25
*/

#include "image.h"

namespace Hearth
{
  Image::Image():
    UI(0,0),
    m_color(0,0,255,255),
    m_width(200),
    m_height(100)
  {
    m_sprite = new Sprite();
  }

  Image::Image(int x, int y, int h, int w):
    UI(x,y),
    m_color(0,0,255,255),
    m_width(200),
    m_height(100)
  {
    m_sprite = new Sprite();
  }


  Image::~Image()
  {
    delete m_sprite;
  }


  void Image::draw()
  {
    m_sprite->draw(m_transform,nullptr);
  }


  void Image::update()
  {

  }


  void Image::init()
  {

  }

  /**
   * @brief function that initializes the sprite of the button
   *
   * @param width the width of the sprite of the button
   * @param height the height of the button of the sprite
   * @param c the color of the button 
   */
  void Image::initSprite(int width, int height, Color c)
  {
    if(m_sprite != nullptr)
      delete m_sprite;

    m_sprite = new Sprite();
    m_sprite->setDim(width,height);

    m_sprite->setColor(c);
    m_sprite->setVisible(true);

    m_width = width;
    m_height = height;

  }


  /**
   * @brief function that intializes the sprite of the button with a given texture
   *
   * @param txtName the name of the texture to find in the resourcemanager
   * @param width the width of the sprite for the button
   * @param height the height of the sprite for the button
   */
  void Image::initSprite(std::string text, int width, int height)
  {
    if(m_sprite != nullptr)
      delete m_sprite;

    m_sprite = new Sprite();
    m_sprite->setTexture(text);
    m_sprite->setDim(width,height);
    m_sprite->setVisible(true);

    m_width = width;
    m_height = height;

  }


}//end Hearth
