
#include "brick.h"

brick::brick(int x, int y): m_x(x), m_y(y)
{
    
}

int brick::getX()
{
    return m_x;
}

int brick::getY()
{
    return m_y;
}

int brick::getX2()
{
    return m_x + m_brickWidth;
}

int brick::getY2()
{
    return m_y + m_brickHeight;
}

bool brick::isVeryWeak()
{
    if(m_strength<=0)
    {
        return true;
    }
    
    return false;   
}

void brick::weaken()
{
    m_strength--;
}

int brick::getStrength()
{
    return m_strength;
}

void brick::setStrength(int s)
{
    m_strength = s;
}

void brick::update()
{
    
}

brick::~brick()
{
}
