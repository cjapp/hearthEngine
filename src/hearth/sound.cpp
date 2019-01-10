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
#include <iostream>

namespace Hearth
{

  Sound::Sound()
  {
    m_wavLength = nullptr;
    m_wavBuffer = nullptr;
  }


  Sound::~Sound()
  {
    remove();
  }


  bool Sound::load(std::string filepath, bool loop)
  {
    if(SDL_LoadWAV(filepath.c_str(), &m_spec, &m_buffer, &m_length) == NULL)
    {
      std::cout << "Failed to load the filename: " << filepath << std::endl;
      return false;
    } 

    std::cout << "Successfully loaded <" << filepath << "> sound." << std::endl;

    m_loop = loop;

    return true;
  }


  void Sound::remove()
  {
    if(m_wavBuffer != nullptr)
      SDL_FreeWAV(m_wavBuffer);
  }


  void SoundSystem::audioCallback(void* userData, Uint8* stream, int streamLength)
  {
    AudioData* audio = (AudioData*)userData;

    if(audio->length == 0)
      return;

    Uint32 length = (Uint32)streamLength;
    length = (length > audio->length ? audio->length : length);
    SDL_memcpy(stream,audio->position,length);
    audio->position += length;
    audio->length -= length;
  }


  void Sound::play()
  {
   //TODO: Code to play sound, get SDL_Sound device, pause sound, wait for the sound to play 
   
  }

  void Sound::pause()
  {
    //TODO: Need to add functionality to this
  }



}//end Hearth
