#include "rotator.h"

#include "engine/window.hpp"
#include "engine/hTime.h"

using namespace Hearth;

Rotator::Rotator()
{

}


Rotator::~Rotator()
{

}


void Rotator::init()
{
  initSprite("smile",40,40);
  setPosition(Window::Instance()->Width()/2, Window::Instance()->Height() * (3/4));
  m_transform.setPivot(float(m_width)/2.0f,float(m_height));
  degree = 15;
  right = false;
}


void Rotator::update()
{
  m_transform.rotate(degree * Time::deltaTime());
}
