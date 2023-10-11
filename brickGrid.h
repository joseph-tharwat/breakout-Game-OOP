
#ifndef BRICK_GRID_H
#define BRICK_GRID_H

#include "entity.h"
#include "brick.h"
#include <vector>

using namespace std;

class brickGrid : public entity
{
private:
    int m_count{40};
    int m_rows{4};
    int m_colomns{10};
    int m_widthOffset{20};
    int m_heightOffset{20};
    brick* m_bricks[40];
public:
    brickGrid();

    void update();
    void draw();

    ~brickGrid();
};



#endif