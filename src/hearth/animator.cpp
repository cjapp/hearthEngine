#include "animator.h"

namespace Hearth
{

  Animator::Animator():
    _currentAnimation(nullptr),
    _playing(false),
    _sprite(nullptr)
  {
    _animations.clear();
  }


  Animator::~Animator()
  {

  }


  /**
   * @brief function that plays and sets the current animation,
   *        to the specified animation
   *
   * @param name the name of the animation to play, it must be 
   *        spelled exactly as it is stored in the animation 
   *        map
   *
   * @return true if it suceeded in playing the animation,
   *         false if it failed (like the animation doesnt exist)
   */
  bool Animator::play(std::string &name)
  {
    for(std::map<std::string,Animation>::iterator it = _animations.begin(); it != _animations.end();it++)
    {
      //search animations for the specified animation
      if(it->first == name)
      {
        //set current animation to the found animation and set playing to true
        _currentAnimation = &(it->second);
        _playing = true;
      }
    }

    //if the animation doesnt exist output the error with name of
    //  missing animation

    return false;
  }



  /**
   * @brief function that plays/resumes an animation. If there isnt
   *        a current animation, play the first animation in the map
   *
   * @return true if an animation can be played, false
   *         if no animation exists
   */
  bool Animator::play()
  {
    if(_currentAnimation != nullptr)
    {
      _playing = true;
      return true;
    } 
    else if(_animations.size() > 0)//if animations exist, use the first
    {
      //TODO: print error msg regarding current animation not set, using default animation

      //set current animation to the first animation in animations
      _currentAnimation = &(_animations.begin()->second);

      //set playing to true
      _playing = true;

      return true;
    }
    else
    {
      //TODO: print error msg saying no animations exist in this animator
      return false
    }
  }


  /**
   * @brief function that pauses the animation that currently playing
   */
  void Animator::pause()
  {
    _playing = false;
  }


  /**
   * @brief function that stops the current animation, animation no 
   *        longer plays
   */
  void Animator::stop()
  {
    _playing = false;
    _currentAnimation = nullptr;

  }


  /**
   * @brief function that adds an animation to colllection of animations
   *        (_animations) in the animator
   *
   * @param name the name of the animation to use as a key in the map
   * @param animation the animation itself
   *
   * @return true if the animation was added, false if it failed
   */
  bool addAnimation(std::string& name, Animation& animation)
  {

    std::map<std::string, Animation>::iterator it;
    it = _animations.find(name);

    if(it != _animations.end())
    {
      //TODO: Print error msg, animation by that name already exists
      return false;
    }

    _animations[name] = animation;
    return true;
  }


  /**
   * @brief function that removes the specified animation from the
   *        collection of animations 
   *
   * @param name name of the animation to remove from the animator
   *
   * @return true if the animation exists and was removed, false if it failed
   */
  bool removeAnimation(std::string& name)
  {
    std::map<std::string, Animation>::iterator it;
    it = _animations.find(name);

    if(it != _animations.end())
    {
      _animations.erase(it);
      return true;
    }

    //TODO: Print error msg, failed to delete the nonexistant animation NAME
    return false;

  }

}//End Hearth

