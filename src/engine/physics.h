/**
 * @file physics.h
 * @brief Physics class declaration file for the Hearth Engine
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-12-27
 * @edited 2017-12-27
 */
#ifndef PHYSICS_H
#define PHYSICS_H 

namespace Hearth
{

  class Physics
  {
    private:
      static Physics* m_instance;
      static int m_instanceCount; 

    public:
      Physics();
      ~Physics();
      
      void free();

      static Physics* Instance();
  };

}//end Hearth


#endif /* PHYSICS_H */
