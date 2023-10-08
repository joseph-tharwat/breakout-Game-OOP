
#include "background.h"


background::background(char* path)
{
    m_surface = SDL_LoadBMP(path);
    m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);
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

void background::draw()
{
    //SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    // SDL_RenderPresent(m_renderer);
}

background::~background()
{
}