#include "sprite.hpp"
#include "error.hpp"
#include "color.hpp"
#include "resourceManager.hpp"
#include "render.hpp"

#include<cstddef>
#include<iostream>

namespace Hearth
{

  Sprite::Sprite():
    m_visible(false),
    m_texture(nullptr),
    m_clip(nullptr),
    m_color(ColorEnum::MISSING)
  {
    //m_clip = new SDL_Rect();
    //setClip(0,0,0,0);
  }

  Sprite::~Sprite()
  {
    m_texture = nullptr;
    //delete m_clip;
    m_visible = false;
  }


  /**
   * @brief set whether the visibility of the
   *
   * @param visibility
   */
  void Sprite::setVisible(bool visibility)
  {
    m_visible = visibility;
  }


  /**
   * @brief Function to set the clip on spritesheet using SDL Rect
   *
   * @param clip the SDL rect to set the clip with
   */
  void Sprite::setClip(SDL_Rect* clip)
  {
    m_clip = clip;
  }


  /**
   * @brief Function to set the clip on the spritesheet using primitives
   *
   * @param x the x offset on the texture
   * @param y the y offset on the texture
   * @param w the w of the clip on the texture
   * @param h the h of the clip on the texture
   */
  void Sprite::setClip( int x,  int y,  int w,  int h)
  {
    m_clip->x = x;
    m_clip->y = y;
    m_clip->w = w;
    m_clip->h = h;
  }


  /**
   * @brief Set the dimensions of the sprite
   *
   * @param w width function parameter
   * @param h height dimension parameter
   */
  void Sprite::setDim(int w, int h)
  {
    m_height = h;
    m_width = w;
  }


  /**
   * @brief Set the sprites color with this function
   *
   * @param c Color to set the sprite to
   */
  void Sprite::setColor(Color c)
  {
    m_color = c;
  }


  /**
   * @brief Set the texture of the sprite
   *
   * @param name The name of the texture in the resourcemanager
   */
  void Sprite::setTexture(const std::string& name)
  {
    m_texture = nullptr;
    m_texture = ResourceManager::getTexture(name);

    if(m_texture == nullptr)
      Error::printMessage("Failed to set sprite to name: " + name + "");

    return;
  }


  /**
   * @brief Function that draws the sprite using SDL
   *
   * @param trans the transform of the gameobject 
   *        the sprite is being rendered for
   * @param cam the camera that applies the offset if 
   *        need be(should only be applied to worldObjects)
   */
  void Sprite::draw(const Transform& trans, const Camera* cam)
  {
    if(m_visible) /*if visible, draw sprite on screen*/
    {
      //convert floats to ints to work with the SDL renderer
      int x      = (int)(trans.m_position.x + 0.5); 
      int y      = (int)(trans.m_position.y + 0.5); 
      double deg = (double)trans.m_rotation;

      //apply the cameras transform to the current position
      if(cam != nullptr)
      {
        x += int(cam->offsetX());
        y += int(cam->offsetY());
      }

      //calculate pivot location in world space using transform pivot offset
      SDL_Point pivot;
      pivot.x      = (int)(trans.m_pivot.x + 0.5); 
      pivot.y      = (int)(trans.m_pivot.y + 0.5); 

      if(m_texture != nullptr)
      {
        SDL_Rect renderQuad = {x,y, m_width, m_height};
        SDL_RenderCopyEx(Render::Instance()->getRenderer(), m_texture->getTexture(), m_clip, &renderQuad, deg, &pivot, SDL_FLIP_NONE);
      }
      else/*If the sprite is missing, use pink rect*/
      {
        SDL_Rect fillRect = {x,y, m_width, m_height};
        SDL_SetRenderDrawColor(Render::Instance()->getRenderer(), m_color.r, m_color.g, m_color.b, m_color.a);
        SDL_RenderFillRect(Render::Instance()->getRenderer(), &fillRect);
      }
    }
  }

}//end Hearth
