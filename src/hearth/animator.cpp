#include "animator.h"

Animator::Animator()
{

}

Animator::~Animator()
{

}


bool Animator::play(std::string &name)
{

  //search animations for the specified animation

  //set current animation to the found animation and set playing to true

  //if the animation doesnt exist output the error with name of
  //  missing animation

  return false;
}

bool Animator::play()
{
  if(_currentAnimation != nullptr)
  {
    _playing = true;
    return true;
  } 
  else if()
  {
    //print error msg regarding current animation not set, using default animation

    //set current animation to the first animation in animations
    
    //set playing to true
    
    return true;
  }
  else
  {
    //print error msg saying no animations exist in this animator
    return false
  }
}


void Animator::pause()
{
  _playing = false;
}


void Animator::stop()
{
  _playing = false;
  _currentAnimation = nullptr;

}
