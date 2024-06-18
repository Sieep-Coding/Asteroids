#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

typedef struct Bullet {
    Vector2 postition;
    Vector2 velocity;
    bool active;

} Bullet;

void InitBullets(void);
void UpdateBullets(void);
void DrawBullets(void);
void ShootBullets(Vector2 position, float rotation);


#endif