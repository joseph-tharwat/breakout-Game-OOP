
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

void brick::draw()
{
    if(m_strength == 3)
    {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, VERY_STRONG_BRICK_COLOR, 255);
    }
    else if(m_strength == 2)
    {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, STRONG_BRICK_COLOR, 255);
    }
    else if(m_strength == 1)
    {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, WEAK_BRICK_COLOR, 255);
    }
    

    SDL_Rect rect{m_x, m_y, m_brickWidth, m_brickHeight};
    SDL_RenderFillRect(m_renderer, &rect);
    // SDL_RenderPresent(m_renderer); 
}

brick::~brick()
{
}
