/**
 * @file quadtree.h
 * @brief Quadtree spacial data structure using code borrowed from
 *    steven lambert tutorial on the subject and converted into c++:
 *    https://gamedevelopment.tutsplus.com/tutorials/quick-tip-use-quadtrees-to-detect-likely-collisions-in-2d-space--gamedev-374
 * @author Colby Japp
 *         Steven Lambert
 * @version 1.0.0
 * @date 2018-02-19
 * @edited 2018-02-19
 */
#ifndef QUADTREE_H
#define QUADTREE_H 

#include<vector>

#define MAX_OBJECTS 10
#define MAX_LEVELS 5

#define MAX_NODES 4

namespace Hearth
{

  class Rectangle
  {
    public:
      float x,y,w,h;
      Rectangle()
      {x=0.0f; y=0.0f; w=0.0f; h=0.0f;}
      Rectangle(float px, float py, float pw, float ph)
      {x=px; y=py; w=pw; h=ph;}
      ~Rectangle(){}
  };


  class Quadtree
  {
    private:
      int level;
      std::vector<Rectangle> objects;
      Rectangle bounds;
      Quadtree* nodes[MAX_NODES];

      void split();
      int getIndex(Rectangle pRect);

    public:
      Quadtree(int pLevel, Rectangle pBounds);
      ~Quadtree();
      void clear();
      void insert(Rectangle* pRect);
      void retrieve(std::vector<Rectangle*>&, Rectangle p);

  };

}//end Hearth
#endif /* QUADTREE_H */
