/**
 * @file sound.h
 * @brief Sound class declaration file for the hearth game engine.
 *        It is a wrapper that surrounds the SDL_Mixer functions.
 * @author Colby Japp
 * @version 1.0.0
 * @date 2018-10-05
 * @edited 2018-10-05
 */
#ifndef SOUND_H
#define SOUND_H 

#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include<string>

namespace Hearth
{  
  class Sound
  {
    private:
      Mix_Chunk*  _audio;

    public:
      Sound();
      ~Sound();

      bool loadSound(const std::string& filePath);
      Mix_Chunk* getAudio(){return _audio;}

  };

}//end Hearth

#endif /* SOUND_H */
