
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
    m_speedY = -m_speedY;
}

void ball::moveToDown()
{
    m_speedY = -m_speedY;
}

void ball::moveToLeft()
{
    m_speedX = -m_speedX;
}

void ball::moveToRight()
{
    m_speedX = -m_speedX;
}

int ball::getX()
{
    return m_x;
}

int ball::getY()
{
    return m_y;
}


void ball::setSpeed(double speed)
{
    m_speedX = speed;
    m_speedY = speed;
}

void ball::update()
{
    m_x =  m_x + m_speedX;
    m_y =  m_y + m_speedY;

    if(m_x >= m_width || m_x <= 0)
    {
        m_speedX = -m_speedX;
    }
    
    if(m_y <= 0)
    {
        m_speedY = -m_speedY;
    }

    // if(m_y >= m_hieght || m_y <= 0)
    // {
    //     m_speedY = -m_speedY;
    // }
}


void ball::draw()
{   
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

    int x = m_x;
    int y = m_y;
    int offsetx, offsety, d;

    offsetx = 0;
    offsety = m_radius;
    d = m_radius -1;

    while (offsety >= offsetx)
    {
        SDL_RenderDrawLine(m_renderer, x - offsety, y + offsetx,
                                     x + offsety, y + offsetx);
        SDL_RenderDrawLine(m_renderer, x - offsetx, y + offsety,
                                     x + offsetx, y + offsety);
        SDL_RenderDrawLine(m_renderer, x - offsetx, y - offsety,
                                     x + offsetx, y - offsety);
        SDL_RenderDrawLine(m_renderer, x - offsety, y - offsetx,
                                     x + offsety, y - offsetx);


        if (d >= 2*offsetx)
        {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (m_radius - offsety))
        {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else
        {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
    // SDL_RenderPresent(m_renderer); 
}


ball::~ball()
{
}

