#ifndef HOBJECT_H
#define HOBJECT_H

#include "transform.h"
#include<string>

namespace Hearth
{

  class State;

  class HObject
  {
    private:
      unsigned int m_id; 

    protected:
      std::string m_name;
      State* m_state;
      std::string m_tag;

      Transform m_transform;
     
    public:
      //constructors and deconstructors for the class
      HObject();
      HObject(std::string name,float x,float y);
      ~HObject();

      //functions that are not get,sets,or comps
      void translate(float x, float y);
      void moveTowards(float x, float y, float speed);

      //function dealing with the name of the object
      void setName(std::string name){m_name = name;}
      std::string& getName(){return m_name;}

      //functions dealing with the tag of the object
      void setTag(std::string tag){m_tag = tag;}
      std::string& getTag(){return m_tag;}

      //functions dealing with the id of the object
      unsigned int getID(){return m_id;}
      void setID(unsigned int id){m_id = id;}

      //functions dealing with the objects state
      void setState(State* state){m_state = state;}
      State* getState(){return m_state;}

      //functions dealing with the transform class
      Transform& getTransform(){return m_transform;}
      void setPosition(float x,float y){m_transform.setPosition(x,y);}
      Vector2& getPosition(){return m_transform.getPosition();}

      //comparison operators for the class
      bool operator==(const HObject& obj)const{return m_id == obj.m_id;}
      bool operator!=(const HObject& obj)const{return m_id != obj.m_id;}
      bool operator>=(const HObject& obj)const{return m_id >= obj.m_id;}
      bool operator<=(const HObject& obj)const{return m_id <= obj.m_id;}
      bool operator>(const HObject& obj)const{return m_id > obj.m_id;}
      bool operator<(const HObject& obj)const{return m_id < obj.m_id;}
  };

}//end Hearth

#endif /* HOBJECT_H */
