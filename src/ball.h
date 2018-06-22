#ifndef BALL_H
#define BALL_H 

#include "engine/gameObject.hpp"

using namespace Hearth;


class Ball : public GameObject
{
  public:
    Ball();
    ~Ball();

    void init();
    void update();

   private:
     int dirx;
     int diry;
};


#endif /* BALL_H */
