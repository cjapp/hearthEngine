/**
 * @file soundSystem.cpp
 * @brief SoundSystem declaration file for the hearth game engine
 * @author Colby JAPP
 * @version 1.0.0
 * @date 2018-10-03
 * @edited 2018-10-03
 */

#include "soundSystem.h"
#include "error.hpp"

#include<iostream>

namespace Hearth
{

  Music* SoundSystem::_music = NULL;
  bool SoundSystem::_playing = false;

  void SoundSystem::_init()
  {
    Error::printMessage("---Initializing Sound...");

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
      std::cout <<  "    Error: Failed to initialize audio!" << std::endl;
    }

    Error::printMessage("---Initialized Sound...");
  }

  void SoundSystem::_uninit()
  {
    _music = NULL;
    _playing = false;

    Mix_Quit();
  }

  void SoundSystem::setMusic(const std::string& name)
  {
    _music = ResourceManager::getMusic(name);

    if(_music == nullptr)
    {
      Error::printMessage("   SoundSystem::Error: Failed to set Music.");
    }

  }

  void SoundSystem::playMusic()
  {
    if(_music != nullptr && Mix_PlayingMusic() == 0)
    {
      Mix_PlayMusic(_music->getAudio(), -1); 
      _playing = true;
    }
    else
    {
      Mix_ResumeMusic();
    }
  }


  void SoundSystem::pauseMusic()
  {
    if(_music != nullptr)
    {
      Mix_PauseMusic();
    }
  }

  void SoundSystem::stopMusic()
  {
    if(_music != nullptr)
    {
      Mix_HaltMusic();
    }
  }

}
