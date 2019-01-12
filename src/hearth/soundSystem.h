/**
 * @file soundSystem.h
 * @brief Soundsystem header file for the hearth game engine. Will act as the hub for 
 *        everything sound related in the engine. Currently acts as a wrapper for
 *        SDL_mixer functions
 * @author Colby JAPP
 * @version 1.0.0
 * @date 2018-10-03
 * @edited 2018-10-03
 */

#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H 

#include "music.h"

#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include<string>

namespace Hearth
{
  class SoundSystem
  {
    private:

      void _init();
      void _uninit();

      static Music* _music;
      static bool _playing;

    public:

      static SoundSystem& Instance()
      {
        static SoundSystem instance;
        return instance;
      }

      //music functions
      static void setMusic(const std::string& name);
      static void playMusic();
      static void pauseMusic();
      static void stopMusic();

    protected:
      friend class Application;
      static void init(){Instance()._init();}
      static void uninit(){Instance()._uninit();}

  };

}//end Hearth

#endif /* SOUNDSYSTEM_H */
