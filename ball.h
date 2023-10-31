
#ifndef BALL_H
#define BALL_H

#include "include\SDL.h"

#include "main.h"

#include "moveEntity.h"

class ball: public moveEntity
{
private:
    static const int m_radius{5};
public:
    ball(int x, int y, double speed = 3);
    void moveTo(int x, int y);
    void moveToLeft();
    void moveToRight();
    void moveToUp();
    void moveToDown();

    int getX();
    int getY();
    int getRadius();

    void setSpeed(double speed);
    int getSpeed();
    void update();
    ~ball();
};


#endif