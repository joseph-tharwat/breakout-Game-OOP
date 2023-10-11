
//To compile without any error
//g++ main.cpp screen.cpp entity.cpp moveEntity.cpp background.cpp ball.cpp paddle.cpp interaction.cpp -lmingw32 -lSDL2main -lSDL2

#include<iostream>

#include "include\SDL.h"

#include"main.h"
#include "screen.h"
#include "ball.h"
#include "background.h"
#include "paddle.h"
#include "brickGrid.h"

#include "interaction.h"

#include <array>

using namespace std;

int main(int argc, char* argv[])
{   
    srand(time(NULL));

    screen* mainScreen = new screen(SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    background mainBackground(BACKGROUND_IMAGE_PATH);

    ball mainBall(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    
    paddle mainPaddle(SCREEN_WIDTH/2);

    brickGrid mainBrickGrid = brickGrid();
    // cout<<"created"<<endl;
    // brick b1(50,50);
    // brick b2(50,100);
    // brick b3(50,150);
    // brick b4(50,200);
    // brick vb[4] = {b1,b2,b3,b4};
    // vb.push_back(b1);
    // vb.push_back(b2);
    // vb.push_back(b3);
    // vb.push_back(b4);
    while(true)
    {   
        if(isInteracting(mainBall, mainPaddle) == true)
        {
            handleCollision(mainBall, mainPaddle);
        }

        mainScreen->clear();
        mainBackground.draw();
        mainBall.update();
        mainBrickGrid.update();

        mainPaddle.draw();
        mainBrickGrid.draw();
        mainBall.draw();

        mainScreen->draw();

        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                mainScreen->close();
                return 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        mainPaddle.moveToLeft();
                        break;
                    case SDLK_RIGHT:
                        mainPaddle.moveToRight();
                        break;
                }
                break;
            default:
                break;
            }
        }

        // if(mainScreen->eventProcess() == false)
        // {
        //     break;
        // } 

    }
    
    
    return 0;
}
