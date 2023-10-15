
//To compile without any error
//g++ main.cpp screen.cpp entity.cpp moveEntity.cpp background.cpp ball.cpp paddle.cpp interaction.cpp game.cpp -lmingw32 -lSDL2main -lSDL2

#include "game.h"

int main(int argc, char* argv[])
{   
    game mainGame;

    mainGame.run();

    return 0;
}
