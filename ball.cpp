
#include "ball.h"
#include "include\SDL.h"

// extern SDL_Renderer* m_renderer;

using namespace std;

ball::ball(int x, int y, double speed): moveEntity(x,y,speed)
{
    
}

void ball::moveTo(int x, int y)
{
    m_x = x;
    m_y = y;
}

void ball::moveToUp()
{
    m_speedY = -abs(m_speedY);
}

void ball::moveToDown()
{
    m_speedY = abs(m_speedY);
}

void ball::moveToLeft()
{
    m_speedX = -abs(m_speedX);
}

void ball::moveToRight()
{
    m_speedX = abs(m_speedX);
}

int ball::getX()
{
    return m_x;
}

int ball::getY()
{
    return m_y;
}

int ball::getRadius()
{
    return m_radius;
}


void ball::setSpeed(double speed)
{
    m_speedX = speed;
    m_speedY = speed;
}

int ball::getSpeed()
{
    int max = m_speedX > m_speedY ? m_speedX : m_speedY;
    return max + m_radius;
}

void ball::update()
{
    m_x =  m_x + m_speedX;
    m_y =  m_y + m_speedY;

    if(m_x >= SCREEN_WIDTH || m_x <= 0)
    {
        m_speedX = -m_speedX;
    }
    
    if(m_y <= 0)
    {
        m_speedY = -m_speedY;
    }
}

ball::~ball()
{
}

