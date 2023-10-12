#ifndef SCREEN_H
#define SCREEN_H

#include "include\SDL.h"
#include<string.h>
#include<iostream>

using namespace std;

class screen
{
    private:
        int *buffer;

        SDL_Window* m_window;

    public: 
        static int m_width;
        static int m_hieght;
        static SDL_Renderer* m_renderer;

    public:
        screen() = default;
        screen(string windowName, int WindowWidth, int WindowHieght);

        void clear();
        void draw();
        void close();
    
        bool eventProcess();

        void setPixel(int x, int y, unsigned char R, unsigned char B, unsigned char G);
        void setPixel(int x, int y,int color);
        int getPixel(int x, int y);

        int getWidth();
        int getHieght();

        ~screen();
};


#endif