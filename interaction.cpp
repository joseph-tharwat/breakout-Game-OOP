

#include "interaction.h"

using namespace std;

bool isInteracting(ball& b, paddle& p)
{
    if(b.getX() >= p.getX() && b.getX() <= p.getX2() && b.getY()-10 >= p.getY())
    {
        return true;
    }
    return false;
}

void handleCollision(ball& b, paddle& p)
{
    b.moveToUp();

    if(b.getX() > (p.getX()+p.getX2())/2)
    {
        b.moveToRight();
    }
    else if(b.getX() < (p.getX()+p.getX2())/2)
    {
        b.moveToLeft();
    }
}



void isInteracting_handle(ball& localBall, brickGrid& grid)
{
    int index = 0;
    
    for(auto localBrick : grid.m_bricks)
    {
        if( localBall.getX() >= localBrick->getX() && localBall.getX() <= localBrick->getX2() 
            &&
            (localBall.getY() >= localBrick->getY()  && localBall.getY() <= localBrick->getY2())
            && 
            (localBrick->isDestroyed == false)
        )
        {
           handleCollision(localBall, *localBrick); 
           return;
        }
        index++;
    }
}

void handleCollision(ball& localBall, brick& localBrick)
{
    localBrick.weaken();
    if(localBrick.isVeryWeak() == true)
    {
        localBrick.isDestroyed = true;
    }

    //+getSpeed() or -getSpeed() because the ball moves a specific number of pexil each time so we need to check range not just when ballX == brickX or ballY == brickY
    
    //from the top
    if(localBall.getX() >= localBrick.getX() && localBall.getX() <= localBrick.getX2()
     &&
      localBall.getY() >= localBrick.getY() && localBall.getY() <= localBrick.getY() + localBall.getSpeed() )
    {
        localBall.moveToUp();
    }

    //from the bottom
    if(localBall.getX() >= localBrick.getX() && localBall.getX() <= localBrick.getX2() 
     &&
      localBall.getY() <= localBrick.getY2() && localBall.getY() >= localBrick.getY2() - localBall.getSpeed())
    {
        localBall.moveToDown();
    }

    //from the left
    if(localBall.getY() >= localBrick.getY() && localBall.getY() <= localBrick.getY2()
     &&
      localBall.getX() >= localBrick.getX() && localBall.getX() <= localBrick.getX() + localBall.getSpeed())
    {
        localBall.moveToLeft();
    }

    //from the right
    if(localBall.getY() >= localBrick.getY() && localBall.getY() <= localBrick.getY2()
     &&
      localBall.getX() <= localBrick.getX2() && localBall.getX() >= localBrick.getX2() - localBall.getSpeed())
    {
        localBall.moveToRight();
    }

}


