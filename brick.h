
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
    brick(int x, int y);
    void update();
    void draw();
    ~brick();
};


#endif