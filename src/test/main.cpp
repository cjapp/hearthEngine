
#include "engine/application.hpp"
#include "game.hpp"

using namespace Hearth;

int main()
{
  Application m_app;
  m_app.initialize("Test",800,600);

  ResourceManager::loadFont("Fonts/Digitalt.ttf","DEFAULT");
  Color col(0,0,0,255);
  Window::Instance()->setColor(col);

  Game game;

  m_app.AddState(&game);

  m_app.mainLoop();

  m_app.unInitialize();

  return 0;
}


