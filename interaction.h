
#ifndef INTERACTION_H
#define INTERACTION_H

#include "paddle.h"
#include "ball.h"
#include "brickGrid.h"

bool isInteracting(ball& b, paddle& p);

void handleCollision(ball& b, paddle& p);


void isInteracting_handle(ball& localBall, brickGrid& grid);

void handleCollision(ball& localBall, brick& localBrick);

#endif