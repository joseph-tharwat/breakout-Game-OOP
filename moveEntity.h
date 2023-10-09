
#ifndef MOVE_ENTITY_H
#define MOVE_ENTITY_H

#include "entity.h"

class moveEntity: public entity
{
protected:
    int m_x;
    int m_y;
    double m_speedX;
    double m_speedY;
public:
    moveEntity(int x, int y, double speed = 5);
    virtual void update();
    virtual void moveToLeft();
    virtual void moveToRight();
    virtual void moveToUp();
    virtual void moveToDown();
    virtual void moveTo(int x, int y);
    virtual void draw();
    ~moveEntity();
};


#endif