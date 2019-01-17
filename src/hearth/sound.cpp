/**
 * @file sound.cpp
 * @brief Sound object definition file for the hearth game engine.
 *        Acts a wrapper around the SDL_Sound functionality.
 * @author Colby Japp
 * @version 1.0.0
 * @date 2018-10-03
 * @edited 2018-10-03
 */

#include "sound.h"
#include "error.hpp"

namespace Hearth
{

  Sound::Sound():
    _audio(NULL)
  {

  } 


  Sound::~Sound()
  {
    if(_audio != NULL)
    {
      Mix_FreeChunk(_audio);
      _audio = NULL;
    }
  }


  bool Sound::loadSound(const std::string& filePath)
  {
    _audio = Mix_LoadWAV(filePath.c_str());
    if(_audio == NULL)
    {
      Error::printMessage("Error: Failed to load audio file."); 
      return false;
    } 
    return true;
  }


}//end Hearth
