
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

void brick::update()
{
    
}

void brick::draw()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 255, 255);

    SDL_Rect rect{m_x, m_y, m_brickWidth, m_brickHeight};
    SDL_RenderFillRect(m_renderer, &rect);
    // SDL_RenderPresent(m_renderer); 
}

brick::~brick()
{
}
