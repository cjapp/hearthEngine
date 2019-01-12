/**
 * @file music.h
 * @brief Music class definition file for the hearth engine. Wrapper for
 *        the SDL_mixer music class for simpler functionality.
 * @author Colby Japp
 * @version 0.0.1
 * @date 2019-01-10
 * @edited 2019-01-10
 */

#ifndef MUSIC_H
#define MUSIC_H 

#include<SDL2/SDL_mixer.h>//SelfExplanatory
#include<string>

namespace Hearth
{

  class Music
  {
    private:
      Mix_Music* _audio;

    public:
      Music();
      ~Music();

      bool loadMusic(const std::string& file);
      Mix_Music* getAudio(){return _audio;}
  };

}
#endif /* MUSIC_H */
