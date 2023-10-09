
#ifndef PADDLE_H
#define PADDLE_H

#include "include\SDL.h"

#include "moveEntity.h"

class paddle: public moveEntity
{
private:
    int width{60};
    int height{10};
    SDL_Texture* m_paddleTexture;

public:
    paddle(int x = m_width/2, int y = m_hieght-8, double speed = 10);
    void moveTo(int x, int y);
    void moveToLeft();
    void moveToRight();
    void moveToUp();
    void moveToDown();
    void setSpeed(double speed);
    void update();
    void draw();
    ~paddle();
};


#endif