
#include "background.h"


background::background(string path)
{
    m_surface = SDL_LoadBMP(path.c_str());
    
}


void background::update()
{
    //mo update in the background
}

SDL_Surface* background::getsurface()
{
    return m_surface;
}

SDL_Texture* background::getTexture()
{
    return m_texture;
}

background::~background()
{
}