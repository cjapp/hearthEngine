#ifndef ANIMATOR_H
#define ANIMATOR_H 

#include "sprite.hpp"

#include<map>
#include<string>

class Animator
{
  private:
    std::map<std::string, Animation> _animations
    Animation* _currentAnimation;

    bool _playing;
    bool _pause;

    Sprite* _sprite;
  public:
    Animator();
    ~Animator();

    bool play(std::string &name);//play the named animation
    void play();//resume the animation, or play first animation
    void pause();
    void stop();

};


#endif /* ANIMATOR_H */
