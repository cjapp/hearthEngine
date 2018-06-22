#ifndef TEST_H
#define TEST_H 

#include "engine/state.hpp"

#include "ball.h"

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
};


#endif /* TEST_H */
