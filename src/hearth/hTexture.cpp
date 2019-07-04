#include "hTexture.h"
#include "uiText.h"
#include "render.hpp"

#include <stdio.h>

namespace Hearth
{

  HTexture::HTexture():m_width(0), m_height(0), m_texture(nullptr), m_color(0,0,0,255)
  {
  }


  HTexture::~HTexture()
  {
    free();
  }


/**
* @brief function that loads the texture with the given width, height and color
*
* @param width the native width of the texture
* @param height the native height of the texture
* @param c the color of the texture
*
* @return whether loading the texture worked or not, true for working, false if it failed
*/
  bool HTexture::load(int width, int height, Color c)
  {
    free(); 

    m_width = width;
    m_height = height;
    m_color = c;

    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = SDL_CreateRGBSurface(0, m_width, m_height, 32, m_color.r, m_color.g, m_color.b, m_color.a);

    if(loadedSurface == nullptr)
    {
      printf("HTexture::load() : Failed to load a surface when loading of %dx%d\n",width,height);
    }
    else
    {
      newTexture = SDL_CreateTextureFromSurface(Render::Instance()->getRenderer(), loadedSurface);

      if(newTexture == nullptr)
      {
        printf("HTexture::load() : new texture failed to be created with dimensions %dx%d\n",width,height);
      }
      else
      {
        m_width = loadedSurface->w;
        m_height = loadedSurface->h;
      }
      SDL_FreeSurface(loadedSurface);
    }
    m_texture = newTexture;
    return m_texture != nullptr;
  }


/**
* @brief function that loads a texture from a file
*
* @param filepath the filepath of the texture
*
* @return true if loading succeeded, false if it failed
*/
  bool HTexture::loadFromFile(const std::string& filepath)
  {
    free();

    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(filepath.c_str());

    if(loadedSurface == nullptr)
    {
      //error occurred
    }
    else
    {

      SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0x00, 0xFF));
      newTexture = SDL_CreateTextureFromSurface(Render::Instance()->getRenderer(), loadedSurface);
      if(newTexture == nullptr)
      {
        //error occurred 
      }
      else
      {
        m_width = loadedSurface->w;
        m_height = loadedSurface->h;
      }
      SDL_FreeSurface(loadedSurface);
    }

    m_texture = newTexture;
    return m_texture != nullptr;
  }


/**
* @brief function that loads a texture from a uiText object
*
* @param text the uiText object to get the information from
*
* @return true if it succeeded and false if it failed
*/
  bool HTexture::loadFromFont(UIText& text)
  {

    if(text.getFont() == nullptr)
    {
      printf("Font to use is nonexistant, update font failed.");
      return false;
    }

    free();
    Color c = text.getColor();
    SDL_Color sc = {c.r,c.g,c.b,c.a};

    SDL_Surface* textSurface = TTF_RenderText_Solid( text.getFont()->getFont(text.getSize()), text.getText().c_str(), sc ); 
    if( textSurface == nullptr ) 
    { 
      printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    } 
    else 
    { 
      m_texture = SDL_CreateTextureFromSurface(Render::Instance()->getRenderer(), textSurface ); 
      if( m_texture == nullptr ) 
      { 
        printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() ); 
      } 
      else 
      { 
        m_width = textSurface->w;
        m_height = textSurface->h;
      } 
      SDL_FreeSurface( textSurface ); 
    } 

    //Return success 
    return m_texture != NULL;  
  }


/**
* @brief frees the texture of the information it previously held
*/
  void HTexture::free()
  {
    if(m_texture != nullptr)
    {
      SDL_DestroyTexture(m_texture);
      m_texture = nullptr;
      m_width = 0;
      m_height = 0;
    }
  }


/**
* @brief renders the texture to the screen at the given screen coordinates
*
* @param x the x screen coordinate
* @param y the y screen coordinate
* @param clip the clip, if specified, of the spritesheet to render 
*/
  void HTexture::render(int x, int y, SDL_Rect* clip /*NULL*/)
  {
    SDL_Rect renderQuad = {x,y,m_width,m_height};

    if(clip != NULL)
    {
      renderQuad.w = clip->w;
      renderQuad.h = clip->h;
    }

    SDL_RenderCopy(Render::Instance()->getRenderer(), m_texture, clip, &renderQuad);
  }

}//end namespace Hearth
