#ifndef ANIMATOR_H
#define ANIMATOR_H 

#include "sprite.hpp"

#include<map>
#include<string>

namespace Hearth
{

  class Animator: public Sprite
  {
    private:
      std::map<std::string, Animation> _animations;
      Animation* _currentAnimation;

      bool _playing;

    public:
      Animator();
      ~Animator();

      //Inherited Functions
      void init();
      void update();
      void deinit();
      void draw(const Transform& t, const Camera* c);

      //Animator specific functions 
      bool play(std::string &name);//play the named animation
      bool play();//resume the animation, or play first animation
      void pause();
      void stop();

      bool addAnimation(std::string& name, Animation& animation);
      bool removeAnimation(std::string& name);

      void getCurrentFrame();
  };

}//End Hearth

#endif /* ANIMATOR_H */
