
#include "brickGrid.h"
#include <cstdlib>

brickGrid::brickGrid()
{
    int index=0;
    srand(time(0));
    for(int i =0; i<m_rows; i++)
    {
        for(int j = 0; j<m_colomns; j++)
        {   
            int x_value = j*BRICK_WIDTH + m_widthOffset + m_spaceBetweenBricks*j;
            int y_value = i*BRICK_HEIGHT + m_heightOffset + m_spaceBetweenBricks*i;
            m_bricks.push_back(new brick(x_value, y_value));

            int randamStrength = rand()%3 + 1;
            m_bricks[index]->setStrength(randamStrength);
            
            index++;
        }
    }
}

void brickGrid::update()
{
    
}

void brickGrid::draw()
{
    for(int i=0; i<m_rows*m_colomns; i++)
    {
        if(m_bricks[i]->isDestroyed == false)
            m_bricks[i]->draw();
    }
}

void brickGrid::reset()
{
    for(auto br : m_bricks)
    {
        br->isDestroyed = false;
    }
}

bool brickGrid::isDistroedAll()
{
    for(auto br : m_bricks)
    {
        if(br->isDestroyed == false)
        {
            return false;
        }
    }
    return true;
}

brickGrid::~brickGrid()
{
}
