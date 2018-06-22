#include "ball.h"

#include "engine/window.hpp"

using namespace std;

Ball::Ball()
{

}

Ball::~Ball()
{

}

void Ball::init()
{
 string name = "smile";
 initSprite(name, 10, 10); 
 setPosition(Window::Instance()->Width()/2, Window::Instance()->Height()/2);
}

void Ball::update()
{
 

}

