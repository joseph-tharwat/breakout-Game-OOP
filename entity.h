
#ifndef ENTITY_H
#define ENTITY_H

#include "include\SDL.h"

class entity
{
public:
    
public:
    entity(); 

    virtual int getX();
    virtual int getY();

    virtual void update();

    ~entity();
};






#endif