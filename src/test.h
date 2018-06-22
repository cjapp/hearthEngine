#ifndef TEST_H
#define TEST_H 

#include "engine/state.hpp"

#include "ball.h"
#include "rotator.h"

using namespace Hearth;

class Test : public State
{
  public:
    Test();
    ~Test();

    void init();
    void update();

    GameObject walls[4];
    Ball ball;
    Rotator rot;
};


#endif /* TEST_H */
