
#include "paddle.h"

using namespace std;

paddle::paddle(int x, int y, double speed): moveEntity(x,y,speed)
{
   
}

void paddle::moveTo(int x, int y)
{
    m_x = x;
    m_y = y;
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

void paddle::setSpeed(double speed)
{
    m_speedX = speed;
}

void paddle::update()
{
    if(m_x >= m_width || m_x <= 0)
    {
        m_speedX = -m_speedX;
        m_x =  m_x + m_speedX;
    }
}


void paddle::draw()
{   
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

    SDL_Rect rect{m_x, m_y, width, height};
    SDL_RenderFillRect(m_renderer, &rect);
    // SDL_RenderPresent(m_renderer); 
}


paddle::~paddle()
{
}

