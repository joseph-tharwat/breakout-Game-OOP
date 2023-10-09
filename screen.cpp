
#include "screen.h"
#include<iostream>

using namespace std;

// extern SDL_Renderer* m_renderer;

SDL_Renderer* screen::m_renderer = nullptr;
// screen* screen::m_screen{nullptr};


// screen* screen::getScreen()
// {
//     if(m_screen == nullptr)
//     {
//         m_screen = new screen();
//     }
//     return m_screen;
// }

int screen::m_width{0};
int screen::m_hieght{0};

screen::screen(char windowName[], int windowWidth, int windowHieght)
{
    m_width = windowWidth;
    m_hieght = windowHieght;
    m_window = SDL_CreateWindow(windowName,
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                windowWidth,
                                windowHieght,
                                SDL_WINDOW_SHOWN);

    m_renderer = SDL_CreateRenderer(m_window,
                                    -1,
                                    SDL_RENDERER_PRESENTVSYNC);

    m_texture = SDL_CreateTexture(m_renderer,
                                    SDL_PIXELFORMAT_RGBA8888,
                                    SDL_TEXTUREACCESS_STATIC,
                                    windowWidth,
                                    windowHieght);

    buffer = new int[windowWidth*windowHieght];
    blurBuffer = new int[windowWidth*windowHieght];
    
    memset(buffer, 0, m_width*m_hieght*sizeof(int));
    memset(blurBuffer, 0, m_width*m_hieght*sizeof(int));
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

void screen::boxBlur()
{
    int* temp = buffer;
    buffer = blurBuffer;   
    blurBuffer = temp;

    for(int y = 1; y<m_hieght-1; y++)
    {
        for(int x = 1; x<m_width-1; x++)
        {
            ////get the average color around the pixel 
            /*
             *0 0 0
             *0 1 0
             *0 0 0 
            */
           
            unsigned int totalRed = 0;
            unsigned int totalGreen = 0;
            unsigned int totalBlue = 0;

            unsigned int totalColor = 0;
            for(int rows=-1; rows<=1; rows++)
            {
                for(int cols=-1; cols<=1; cols++)
                {   
                    totalColor = getPixelBoxBlur(x+cols, y+rows);
            
                    totalRed = totalRed + (Uint8)(totalColor >> 24);
                    totalGreen = totalGreen + (Uint8)(totalColor >> 16);
                    totalBlue = totalBlue + (Uint8)(totalColor >> 8);         
                }
            }
            Uint8 red = totalRed/9;
            Uint8 green = totalGreen/9;  
            Uint8 blue = totalBlue/9;
            setPixel(x, y, red, green, blue);
        }
    }
}

void screen::update()
{   
    // SDL_UpdateTexture(m_texture, NULL, buffer, m_width*sizeof(int));
    // SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
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
    delete [] blurBuffer;
    SDL_DestroyTexture(m_texture);
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

unsigned int screen::getPixelBoxBlur(int x, int y)
{
    return blurBuffer[m_width*y+x];   
}

int screen::getWidth()
{   
    return m_width;
}

int screen::getHieght()
{
    return m_hieght;
}


