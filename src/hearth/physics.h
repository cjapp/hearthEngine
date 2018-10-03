/**
 * @file physics.h
 * @brief Physics class declaration file for the Hearth Engine
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-12-27
 * @edited Wed 11 Jul 2018 11:38:08 AM PDT
 */
#ifndef PHYSICS_H
#define PHYSICS_H 

namespace Hearth
{

  class Physics
  {
    public:
      Physics(){}
      ~Physics(){}

      static Physics Instance()
      {
        static Physics instance;
        return instance;
      }
      

  };

}//end Hearth


#endif /* PHYSICS_H */
