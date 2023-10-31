
#include "screen.h"
#include<iostream>

using namespace std;

SDL_Renderer* screen::m_renderer = nullptr;

int screen::m_width{0};
int screen::m_hieght{0};

screen::screen(string windowName, int windowWidth, int windowHieght)
{
    m_width = windowWidth;
    m_hieght = windowHieght;
    m_window = SDL_CreateWindow(windowName.c_str(),
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                windowWidth,
                                windowHieght,
                                SDL_WINDOW_SHOWN);

    m_renderer = SDL_CreateRenderer(m_window,
                                    -1,
                                    SDL_RENDERER_PRESENTVSYNC);

    buffer = new int[windowWidth*windowHieght];
    
    memset(buffer, 0, m_width*m_hieght*sizeof(int));
}


screen::~screen()
{
    close();
}

void screen::clear()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
}

void screen::draw()
{  
    SDL_RenderPresent(m_renderer);
}

void screen::draw(ball b)
{
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

    int x = b.getX();
    int y = b.getY();
    int radius = b.getRadius(); 

    int offsetx, offsety, d;

    offsetx = 0;
    offsety = radius;
    d = radius -1;

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
        else if (d < 2 * (radius - offsety))
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
}

void screen::draw(paddle p)
{
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

    SDL_Rect rect{p.getX(), p.getY(), p.getX2()-p.getX(), p.getY2()-p.getY()};
    SDL_RenderFillRect(m_renderer, &rect);
}

void screen::draw(brick b)
{
    if(b.getStrength() == 3)
    {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, VERY_STRONG_BRICK_COLOR, 255);
    }
    else if(b.getStrength() == 2)
    {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, STRONG_BRICK_COLOR, 255);
    }
    else if(b.getStrength() == 1)
    {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, WEAK_BRICK_COLOR, 255);
    }

    SDL_Rect rect{b.getX(), b.getY(), b.getX2()-b.getX(), b.getY2()-b.getY()};
    SDL_RenderFillRect(m_renderer, &rect);   
}

void screen::draw(brickGrid bg)
{
    for(int i=0; i<bg.getRows() * bg.getCols(); i++)
    {
        if(bg.m_bricks[i]->isDestroyed == false)
            draw(*bg.m_bricks[i]);
    }
}

void screen::draw(background b)
{
    SDL_RenderCopy(
        m_renderer,
        SDL_CreateTextureFromSurface(m_renderer, b.getsurface()),
        NULL, NULL
    );
}

void screen::draw(background back, brickGrid bg, ball b, paddle p)
{
    clear();
    
    //draw every entity
    draw(back); 
    draw(bg);
    draw(b);
    draw(p);

    //perform the drawing
    draw();   
}

bool screen::eventProcess()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            return false;
        }
        
    }
    return true;
}


void screen::close()
{
    delete [] buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void screen::setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B)
{
    if(x<0 || x>m_width || y<0 || y>m_hieght)   
    {
        return;
    }

    int color = R<<24;
    color = color + G<<16;
    color = color + B<<8;
    color = color + 0xFF;//alpha
    buffer[m_width*y+x] = color;
}

void screen::setPixel(int x, int y,int color)
{
    if(x<0 || x>m_width || y<0 || y>m_hieght)
    {
        return;
    }
    setPixel(x, y,  color>>24,
                    color>>16,
                    color>>8 );
}


int screen::getPixel(int x, int y)
{
    return buffer[m_width*y+x];
}

int screen::getWidth()
{   
    return m_width;
}

int screen::getHieght()
{
    return m_hieght;
}


