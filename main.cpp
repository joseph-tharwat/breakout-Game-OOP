
//To compile without any error
//g++ main.cpp screen.cpp entity.cpp moveEntity.cpp background.cpp ball.cpp -lmingw32 -lSDL2main -lSDL2

#include<iostream>

#include "include\SDL.h"

#include"main.h"
#include "screen.h"
#include "ball.h"
#include "background.h"

using namespace std;

int main(int argc, char* argv[])
{   
    srand(time(NULL));

    screen* mainScreen = new screen(SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    background mainBackground("background.bmp");
    mainBackground.draw();

    ball mainBall(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    mainBall.draw();
    
    while(true)
    {   
        // mainScreen->clear();
        mainBackground.draw();
        mainBall.draw();
        mainScreen->update();

        if(mainScreen->eventProcess() == false)
        {
            break;
        } 

    }
    
    mainScreen->close();
    return 0;
}
