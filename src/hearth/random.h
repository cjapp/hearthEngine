/**
 * @file random.h
 * @brief The Random class header file for the Hearth Engine.
 * @author Colby J
 * @version 0.0.1
 * @date 2019-12-01
 * @edited 2019-12-01
 */
#ifndef RANDOM_H
#define RANDOM_H 

namespace Hearth
{

  class Random
  {
    private:
      static bool m_seeded;

    public:
      Random();
      ~Random();

      static void seed(const int s);

      static int random();
      static int random(int min, int max);

  };

}//end Hearth

#endif /* RANDOM_H */
