#ifndef BULLET_H
#define BULLET_H

typedef struct Bullet {
    Vector2 position;
    Vector2 velocity;
    float radius;
    bool active;
} Bullet;

void InitBullets(void);
void UpdateBullets(void);
void DrawBullets(void);
void ShootBullet(Vector2 position, float rotation);

#endif
