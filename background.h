
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <string>
#include "entity.h"
#include "include\SDL.h"

using namespace std;

class background: public entity
{
private:
    SDL_Surface *m_surface{nullptr};
    SDL_Texture *m_texture{nullptr};

public:
    background(char* path);
    void update();
    void draw();
    SDL_Surface* getsurface();
    SDL_Texture* getTexture();
    ~background();
};


#endif