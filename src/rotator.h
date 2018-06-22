#ifndef ROTATOR_H
#define ROTATOR_H 

#include "engine/gameObject.hpp"

using namespace Hearth;

class Rotator : public GameObject
{
  public:
    Rotator();
    ~Rotator();
    

    void init();
    void update();

  private:
    bool right;
    float degree; 

};


#endif /* ROTATOR_H */
