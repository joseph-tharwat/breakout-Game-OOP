
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
    
    // memset(buffer, 0, m_width*m_hieght*sizeof(int));
    // memset(blurBuffer, 0, m_width*m_hieght*sizeof(int));
}

void screen::draw()
{   
    // SDL_UpdateTexture(m_texture, NULL, buffer, m_width*sizeof(int));
    SDL_RenderPresent(m_renderer);
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


