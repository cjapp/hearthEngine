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
    

};

}//end Hearth

#endif /* RANDOM_H */
