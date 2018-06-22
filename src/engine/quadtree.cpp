/**
 * @file quadtree.cpp
 * @brief Quadtree spacial data structure using code borrowed from
 *    steven lambert tutorial on the subject and converted into c++:
 *    https://gamedevelopment.tutsplus.com/tutorials/quick-tip-use-quadtrees-to-detect-likely-collisions-in-2d-space--gamedev-374
 * @author Colby Japp
 * @version 1.0.0
 * @date 2018-02-19
 * @edited 2018-02-19
 */

#include "quadtree.h"


namespace Hearth
{

  Quadtree::Quadtree(int pLevel, Rectangle pBounds)
  {
    level = pLevel;
    bounds = pBounds;

    for(int i =0; i < MAX_NODES; i++)
      nodes[i] = nullptr;
  } 


  Quadtree::~Quadtree()
  {
    objects.clear();
    for(int i = 0; i < MAX_NODES; i++)
    {
      if(nodes[i] != nullptr)
        delete nodes[i];
    }
  }


  void Quadtree::clear()
  {
    objects.clear();
    for(int i = 0; i < MAX_NODES; i++)
    {
      if(nodes[i] != nullptr)
      {
        nodes[i]->clear();
        delete nodes[i];
      }
    }
  } 


  void Quadtree::insert(Rectangle* pRect)
  {
    if(nodes[0] != nullptr)
    {
      int index = getIndex(pRect);

      if(index != -1)
      {
        nodes[index]->insert(pRect);
        return;
      }
    }

    objects.push_back(pRect);

    if(objects.size() > MAX_OBJECTS && level < MAX_LEVELS)
    {

      if(nodes[0] == nullptr)
        split();

      int i = 0;
      while(i < objects.size())
      {
        int index = getIndex(objects[i]);
        if(index != -1)
        {
          nodes[index]->insert(objects[i]);
          objects.erase(objects.begin() + i);
        }
        else
          i++;
      }

    }
  }


  void Quadtree::split()
  {
    int subWidth = (int)(bounds.w / 2);
    int subHeight = (int)(bounds.y / 2);
    int x = (int)bounds.x;
    int y = (int)bounds.y;

    Rectangle r1(x + subWidth, y, subWidth,subHeight);
    nodes[0] = new Quadtree(level+1, r1);
    Rectangle r2(x, y, subWidth,subHeight);
    nodes[1] = new Quadtree(level+1, r2);
    Rectangle r3(x, y + subHeight, subWidth,subHeight);
    nodes[2] = new Quadtree(level+1, r3);
    Rectangle r4(x + subWidth, y + subHeight, subWidth,subHeight);
    nodes[3] = new Quadtree(level+1, r4);
  }

  int Quadtree::getIndex(Rectangle pRect)
  {
    int index = -1;
    double verticalMidpoint = bounds.x + (bounds.w / 2);
    double horizontalMidpoint = bounds.y + (bounds.h / 2);

    //object can fit completely within the top quadrantsi
    // of current node bounds
    bool topQuadrant = ((pRect.y < horizontalMidpoint) && 
        (pRect.y + pRect.h < horizontalMidpoint));

    //object can fit completely within the bottom quadrants 
    // of current node bounds
    bool bottomQuadrant = (pRect.y > horizontalMidpoint);

    //if object can fit with left side of node's bounds
    if(pRect.x < verticalMidpoint && pRect.x + pRect.w < verticalMidpoint)
    {
      if(topQuadrant)
      {
        index = 1;
      }
      else if(bottomQuadrant)
      {
        index = 2;
      }
    }
    //if the object can completely fit within right 
    // side node's bounds
    else if(pRect.x > verticalMidpoint)
    {
      if(topQuadrant)
      {
        index = 0;
      }
      else if(bottomQuadrant)
      {
        index = 3;
      }
    }

    return index;
  }


  void Quadtree::retrieve(std::vector<Rectangle>& returnObjects, Rectangle pRect)
  {
    int index = getIndex(pRect);
    if(index != -1 && nodes[0] != nullptr)
    {
      nodes[index]->retrieve(returnObjects, pRect);
    }

    //Combine objects that have the possibility of colliding with pRect
    for(int i = 0; i < objects.size(); i++)
    {
      returnObjects.push_back(objects[i]);
    }
  }

}//end Hearth
