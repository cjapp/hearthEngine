/**
 * @file gameObject.hpp
 * @brief GameObject class header file
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-09-22
 * @edited 2017-09-22
 */

#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP 

#include "hObject.h"
#include "ui.h"
#include "sprite.hpp"
#include "color.hpp"
#include "collider.h"

#include<string>

namespace Hearth
{

  class State;

  class GameObject : public HObject
  {
    public:
      GameObject();
      GameObject(std::string name, float x, float y);
      ~GameObject();

      virtual void draw();
      virtual void update();
      virtual void init();
      virtual void reset();

      void initSprite(int width, int height, Color c);
      void initSprite(const std::string& txtName, int width, int height);

      void setCollider();
      void setCollider(int h,int w);

      bool isSolid() const;
      void setSolid(bool s);

      void _init(State* s);

      Sprite* getSprite() { return m_sprite;}

      int getHeight(){return m_height;}
      int getWidth(){return m_width;}

      Collider* getCollider(){return m_collider;}

    protected:
      GameObject* goFindName(std::string obj_name);
      UI*         uiFindName(std::string obj_name);
      GameObject* goFindTag(std::string tag);
      UI*         uiFindTag(std::string tag);

      void Destroy(GameObject* obj);

      GameObject* checkCollisionTag(std::string obj_tag);
      GameObject* checkCollisionName(std::string obj_name);

      int m_depth;

      int m_height;
      int m_width;

      Sprite* m_sprite;
      Collider* m_collider;
  };

} // end Hearth

#endif /* GAMEOBJECT_HPP */
