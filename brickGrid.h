
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
    int m_spaceBetweenBricks{3};

public:
    vector<brick*> m_bricks;
    
public:
    brickGrid();

    int getRows();
    int getCols();

    void update();
    void reset();
    bool isDistroedAll();
    ~brickGrid();
};



#endif