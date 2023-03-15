/**
 * @file random.cpp
 * @brief The Random class definition file for the hearth engine.
 * @author Colby J
 * @version 0.0.1
 * @date 2019-12-01
 * @edited 2019-12-01
 */

#include "random.h"

#include<cstdlib>//srand() and rand()
#include<time.h>//time()
#include<iostream>//std::cerr and std::endl

namespace Hearth
{
  //Determines whether or not the random singleton has been seeded
  bool Random::m_seeded = false;


  /**
   * @brief Random class constructor, is usually never needed to be called
   */
  Random::Random()
  {
    if(!m_seeded) 
      seed(time(NULL));
  }

  /**
   * @brief Random class deconstructor, is usually never needed to be called
   */
  Random::~Random()
  {

  }

  /**
   * @brief Function that seeds the random number generator
   *
   * @param s the seed to use for the random number generator
   */
  void Random::seed(const int s)
  {
    std::cerr << "Seeding the random number generator..." << std::endl;
    srand(s);
    m_seeded = true;
  }

  /**
   * @brief function that will return a random int
   *
   * @return a random int value
   */
  int Random::random() 
  {
    if(!m_seeded)
      seed(time(NULL));

    return rand();
  }

  /**
   * @brief This function will generate a random int within the range provided
   *
   * @param min the minimum possible value the generator can generate
   * @param max the maximum possible value the generator can generate
   *
   * @return a random number within range provided in function call
   */
  int Random::random(int min, int max)
  {
    //if min and max are the same return max
    if (min == max)
    { 
        return max;
    }
 
    if(min > max)
    {
      std::cerr << "ERROR: Random::random()- Minimum is greater than maximum value." << std::endl;
      return 0;
    }

    return random()%(max + 1 - min) + min;
  }


}//end Hearth
