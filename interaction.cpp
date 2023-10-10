

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