
#ifndef INTERACTION_H
#define INTERACTION_H

#include "paddle.h"
#include "ball.h"

bool isInteracting(ball& b, paddle& p);

void handleCollision(ball& b, paddle& p);

#endif