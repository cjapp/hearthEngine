/**
 * @file hTime.h
 * @brief The time class declaration file for the hearth game engine
 * @author Colby Japp
 * @version 0.0.1
 * @date 2018-05-11
 * @edited 2018-05-11
 */
#ifndef HTIME_H
#define HTIME_H

#define FRAMES_PER_SECOND 60

#include<SDL2/SDL.h>

namespace Hearth
{

  class Time
  {
    private:
      static unsigned int m_deltaTime;
      static unsigned int m_lastTime;
      static unsigned int m_currentTime;

      static unsigned int frameCount;
      static int m_fps;

    public:
      Time();
      ~Time();

      static float deltaTime(){return (float)m_deltaTime/1000.0f;}
      static float time(){return (float)SDL_GetTicks()/1000.0f;}
      static unsigned int timeRaw(){return SDL_GetTicks();}

      static unsigned int frameTime(){return SDL_GetTicks() - m_currentTime;}

      static void captureTime();
  };


  class Alarm
  {
    private:
      float m_timeStart;
      float m_timeDuration;

      bool m_on;
    public:
      Alarm();

      void setDuration(float duration);
      void start();
      const bool check();

  };

}// end Hearth

#endif /* HTIME_H */
