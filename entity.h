
#ifndef ENTITY_H
#define ENTITY_H

#include "include\SDL.h"
#include "screen.h"

class entity: public screen
{
public:
    
public:
    entity(); 

    virtual int getX();
    virtual int getY();

    virtual void update();
    virtual void draw();

    ~entity();
};






#endif