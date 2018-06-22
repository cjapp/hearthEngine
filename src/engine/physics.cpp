/**
 * @file physics.cpp
 * @brief Physics class definition file for the Hearth Engine
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-12-27
 * @edited 2017-12-27
 */

#include "physics.h"

namespace Hearth
{
  Physics* Physics::m_instance = nullptr;
  int Physics::m_instanceCount = 0;

  Physics::Physics()
  {
    //instantiate Physics singleton if it hasn't been created
    m_instanceCount++;
    Instance();
  }

  Physics::~Physics()
  {
    //decrement instance count variable
    m_instanceCount--;

    //if no instances remain remove the instance variable
    if(m_instanceCount == 0)
      free();
  }

  Physics* Physics::Instance()
  {
    if(m_instance == nullptr) 
      m_instance = new Physics(); 
    return m_instance;
  }

  void Physics::free()
  {
    if(m_instance != nullptr)
      delete m_instance;

    m_instanceCount == 0;
  }


}//end Hearth


