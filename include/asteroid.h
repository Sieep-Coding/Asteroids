#ifndef ASTEROID_H
#define ASTEROID_H

#include "raylib.h"

typedef struct Asteroid {
    Vector2 position;
    Vector2 velocity;
    float radius;
    bool active;
} Asteroid;

void InitAsteroids(void);
void UpdateAsteroids(void);
void DrawAsteroids(void);

#endif
