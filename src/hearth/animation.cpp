#include "animation.h"


Animation::Animation():
  _sheet(nullptr)
{
  _frames.clear();
}


Animation::~Animation()
{
  //empty the vector of frames
  if(!(_frames.empty()))
  {
    while(!_frames.empty())
    {
      delete _frames.front();
      _frames.erase(myvector.begin());
    }
  }


}

void setSheet(HTexture* sheet)
{
  if(sheet != nullptr)
    _sheet = sheet;
  else
    //print an error msg
}


void addFrame(unsigned int index)
{
  //make some interesting calculations,involving calculating the dimensions of the frames
  
}

