
#include "engine/application.hpp"
#include "engine/color.hpp"
#include "engine/window.hpp"

#include"test.h"

using namespace Hearth;

int main()
{
  Application t;

  t.initialize("Test", 1000, 650); 
  ResourceManager::loadTexture("Textures/face.png","smile");
 
  Color c(0,0,0,255); 
  Window::Instance()->setColor(c);
  Window::Instance()->setFullScreenDesktop();

  Test ts;
  t.AddState(&ts);

  t.mainLoop();

  t.unInitialize();

  return 0;
}

