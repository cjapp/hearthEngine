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
  Mix_Quit();
}


