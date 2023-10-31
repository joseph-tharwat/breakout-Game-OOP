
#ifndef PADDLE_H
#define PADDLE_H

#include "include\SDL.h"

#include "moveEntity.h"

#include "main.h"

class paddle: public moveEntity
{
private:
    int width{70};
    int height{15};
    SDL_Texture* m_paddleTexture;

public:
    paddle(int x, int y, double speed = 10);
    void moveTo(int x, int y);
    void moveToLeft();
    void moveToRight();
    void moveToUp();
    void moveToDown();

    int getX();
    int getY();
    int getX2();
    int getY2();

    void setSpeed(double speed);
    void update();
    ~paddle();
};


#endif