
#ifndef MOVE_ENTITY_H
#define MOVE_ENTITY_H

#include "entity.h"

class moveEntity: public entity
{
protected:
    int m_x;
    int m_y;
    double m_speed;
public:
    moveEntity(int x, int y, double speed = 0.5);
    virtual void update();
    virtual void moveTo(int x, int y);
    virtual void draw();
    ~moveEntity();
};


#endif