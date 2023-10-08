
#ifndef BALL_H
#define BALL_H

#include "include\SDL.h"

#include "moveEntity.h"

class ball: public moveEntity
{
private:
    static const int m_radius{25};
public:
    ball(int x, int y, double speed = 0.5);
    void moveTo(int x, int y);
    void setSpeed(double speed);
    void update();
    void draw();
    ~ball();
};


#endif