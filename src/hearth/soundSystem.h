/**
 * @file soundSystem.h
 * @brief Soundsystem header file for the hearth game engine
 * @author Colby JAPP
 * @version 1.0.0
 * @date 2018-10-03
 * @edited 2018-10-03
 */
#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H 

#include "sound.h"

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

    public:

      static SoundSystem& Instance()
      {
        static SoundSystem instance;
        return instance;
      }


    protected:
      friend class Application;
      static void init(){Instance()._init();}
      static void uninit(){Instance()._uninit();}
  };

}//end Hearth

#endif /* SOUNDSYSTEM_H */
