#include "random.h"

#include<cstdlib>
#include<time.h>
#include<iostream>

namespace Hearth
{
  bool Random::m_seeded = false;


  Random::Random()
  {
    if(!m_seeded) 
      seed(time(NULL));
  }

  Random::~Random()
  {

  }

  void Random::seed(const int s)
  {
    std::cerr << "Seeding the random number generator..." << std::endl;
    srand(s);
    m_seeded = true;
  }

  int Random::random() 
  {
    if(!m_seeded)
      seed(time(NULL));

    return rand();
  }


}//end Hearth
