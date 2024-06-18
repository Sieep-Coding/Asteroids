#include "raylib.h"
#include "bullet.h"
#include "utils.h"
#include <math.h>

#define MAX_BULLETS 50
#define BULLET_SPEED 500.0f

static Bullet bullets[MAX_BULLETS];

void InitBullets(void)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        bullets[i].active = false;
    }
}

void UpdateBullets(void)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (bullets[i].active)
        {
            bullets[i].position.x += bullets[i].velocity.x * GetFrameTime();
            bullets[i].position.y += bullets[i].velocity.y * GetFrameTime();

            // Deactivate bullets that go off-screen
            if (bullets[i].position.x > SCREEN_WIDTH || bullets[i].position.x < 0 || bullets[i].position.y > SCREEN_HEIGHT || bullets[i].position.y < 0)
            {
                bullets[i].active = false;
            }
        }
    }
}

void DrawBullets(void)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (bullets[i].active)
        {
            DrawCircle(bullets[i].position.x, bullets[i].position.y, 2, WHITE);
        }
    }
}

void ShootBullet(Vector2 position, float rotation)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (!bullets[i].active)
        {
            bullets[i].active = true;
            bullets[i].position = (Vector2){position.x + sinf(rotation * DEG2RAD) * 20, position.y - cosf(rotation * DEG2RAD) * 20};
            bullets[i].velocity = (Vector2){sinf(rotation * DEG2RAD) * BULLET_SPEED, -cosf(rotation * DEG2RAD) * BULLET_SPEED};
            break;
        }
    }
}
