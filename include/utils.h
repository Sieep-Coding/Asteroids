#ifndef UTILS_H
#define UTILS_H

#include "player.h"
#include "asteroid.h"
#include "bullet.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

#define MAX_ASTEROIDS 10
#define MAX_BULLETS 50

void CheckCollisions(Player *player, bool *gameOver, int *level);

#endif
