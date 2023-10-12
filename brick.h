
#ifndef BRICKS_H
#define BRICKS_H

#include "entity.h"

#define BRICK_WIDTH     50
#define BRICK_HEIGHT    20

class brick : public entity
{
private:
    int m_x;
    int m_y;
    int m_brickWidth{BRICK_WIDTH};
    int m_brickHeight{BRICK_HEIGHT};

public:
    bool isDestroyed{false};

public:
    brick(int x, int y);
    int getX();
    int getY();
    int getX2();
    int getY2();
    void update();
    void draw();
    ~brick();
};


#endif