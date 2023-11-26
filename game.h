

#ifndef GAME_H
#define GAME_H


#include<iostream>

#include <future>

#include "include\SDL.h"

#include"main.h"

#include "screen.h"
#include "ball.h"
#include "background.h"
#include "paddle.h"
#include "brickGrid.h"

#include "interaction.h"

using namespace std;

enum status
{
    LOSE,
    WIN,
    PLAYING,
    PASUE
};

class game
{
private:

public:
    screen* m_screen;
    background m_background;
    ball m_ball;
    paddle m_paddle;
    brickGrid m_brickGrid;

    enum status m_status{PASUE};
public:
    game();
    void run();
    void checkStatus();
    
    ~game();
};

#endif