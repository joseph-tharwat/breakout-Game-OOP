
#include "brickGrid.h"

brickGrid::brickGrid()
{
    int index=0;
    for(int i =0; i<m_rows; i++)
    {
        for(int j = 0; j<m_colomns; j++)
        {
            //3 to seperate each brick from each other
            int x_value = j*BRICK_WIDTH + m_widthOffset + m_spaceBetweenBricks*j;
            int y_value = i*BRICK_HEIGHT + m_heightOffset + m_spaceBetweenBricks*i;
            
            m_bricks.push_back(new brick(x_value, y_value));
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

brickGrid::~brickGrid()
{
}
