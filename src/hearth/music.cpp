/**
 * @file music.cpp
 * @brief Music class definition file for the hearth engine. Wrapper for the
 *        SDL_mixer music class for simpler functionality.
 * @author Colby Japp
 * @version 0.0.1
 * @date 2019-01-10
 * @edited 2019-01-10
 */

#include "music.h"
#include "error.hpp"

#include<iostream>

namespace Hearth
{


  Music::Music():
    _audio(NULL)
  {

  }


  Music::~Music()
  {
    //if _audio points to an Mix_Music, deallocate it
    if(_audio != NULL)
    {
      Mix_FreeMusic(_audio); 
      _audio = NULL;
    }
  }

  bool Music::loadMusic(const std::string& file)
  {
    _audio = Mix_LoadMUS(file.c_str());
    if(_audio == NULL)
    {
      //TODO: Provide better error message info for debugging
      Error::printMessage("   Error: Failed to load the music file."); 
      return false;
    }
    return true;
  }
}
