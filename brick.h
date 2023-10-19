
#ifndef BRICKS_H
#define BRICKS_H

#include "entity.h"

#define BRICK_WIDTH     50
#define BRICK_HEIGHT    20

#define VERY_STRONG_BRICK_COLOR  250
#define STRONG_BRICK_COLOR       200
#define WEAK_BRICK_COLOR         100


class brick : public entity
{
private:
    int m_x;
    int m_y;
    int m_brickWidth{BRICK_WIDTH};
    int m_brickHeight{BRICK_HEIGHT};
    int m_strength{3};
    
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
    bool isVeryWeak();
    void weaken();
    int getStrength();
    void setStrength(int s);
    ~brick();
};


#endif