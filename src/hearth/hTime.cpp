/**
 * @file time.cpp
 * @brief The time class definition file for the hearth game engine
 * @author Colby Japp
 * @version 0.0.1
 * @date 2018-05-11
 * @edited 2018-05-11
 */

#include "hTime.h"

namespace Hearth
{

  unsigned int Time::m_deltaTime = 0;
  unsigned int Time::m_lastTime = 0;
  unsigned int Time::m_currentTime = 0;

  unsigned int Time::frameCount = 0;
  int Time::m_fps = 0;

  Time::Time()
  {

  }

  Time::~Time()
  {

  }


  void Time::captureTime()
  {
    m_currentTime = SDL_GetTicks();

    //if game ran to point of overflow
    if(m_currentTime < m_lastTime)
      m_lastTime = m_currentTime;

    m_deltaTime = m_currentTime - m_lastTime;

    m_lastTime = m_currentTime;

  }


  Alarm::Alarm(): 
    m_timeStart(0.0f),m_timeDuration(0.0f),m_on(false)
  {
  }

  void Alarm::setDuration(float duration)
  {
    m_timeDuration = duration;
  }

  void Alarm::start()
  { 
    m_timeStart = Time::time();
    m_on = false;
  }

  const bool Alarm::check()
  {
    if(m_on == false)
    {
      m_on = (m_timeStart + m_timeDuration) <= Time::time();
      return m_on;
    }

    return false;
  }

}//end Hearth
