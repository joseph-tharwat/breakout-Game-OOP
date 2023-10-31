
#include "paddle.h"

using namespace std;

paddle::paddle(int x, int y, double speed): moveEntity(x,y,speed)
{
   
}

void paddle::moveTo(int x, int y)
{
    m_x = x;
    // m_y = y;
    
}

void paddle::moveToLeft()
{
    m_x = m_x - m_speedX;
}

void paddle::moveToRight()
{
    m_x = m_x + m_speedX;
}

void paddle::moveToUp()
{
    //do nothing
}

void paddle::moveToDown()
{
    //do nothing
}

int paddle::getX()
{
    return m_x;
}

int paddle::getY()
{
    return m_y;
}

int paddle::getX2()
{
    return m_x + width;
}

int paddle::getY2()
{
    return m_y + height;
}

void paddle::setSpeed(double speed)
{
    m_speedX = speed;
}

void paddle::update()
{
    if(m_x >= SCREEN_WIDTH || m_x <= 0)
    {
        m_speedX = -m_speedX;
        m_x =  m_x + m_speedX;
    }
}

paddle::~paddle()
{
}

