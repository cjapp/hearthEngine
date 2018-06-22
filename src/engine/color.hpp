/**
 * @file color.hpp
 * @brief 
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-10-02
 * @edited Wed 25 Apr 2018 11:19:53 AM PDT
 */
#ifndef COLOR_HPP
#define COLOR_HPP 


namespace Hearth
{
  enum ColorEnum
  {
    WHITE,
    RED,
    BLUE,
    GREEN,
    YELLOW,
    BLACK,
    MISSING
  };

  struct Color
  {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;

    Color():
      r(0), g(0),b(0),a(255)
    {}

    Color(char rd, char gr, char bl, char al):
      r(rd), g(gr),b(bl),a(al)
    {}

    Color(ColorEnum c)
    {
      Color t = cToVC(c);
      r = t.r;
      g = t.g;
      b = t.b;
      a = t.a;
    }

    void set(char rd, char grn, char bl, char al = 255)
    {
      r = rd;
      g = grn;
      b = bl;
      a = al;
    }


    Color cToVC(ColorEnum ce, char al = 255)
    {
      Color c;
      switch(ce)
      {
        case WHITE:
          c.set(255,255,255,al);
          break;
        case RED:
          c.set(255,0,0,al);
          break;
        case BLUE:
          c.set(0,0,255,al);
          break;
        case GREEN:
          c.set(0,255,0,al);
          break;
        case YELLOW:
          c.set(255,255,0,al);
          break;
        case BLACK:
          c.set(0,0,0,al);
        case MISSING:
          c.set(255,0,255,al);
          break;
      }
      return c;
    }

  };

}//end Hearth

#endif /* COLOR_HPP */
