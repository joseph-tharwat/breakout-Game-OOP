
#include "brick.h"

brick::brick(int x, int y): m_x(x), m_y(y)
{
    
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
