#include "utils.h"
#include <math.h>

static Bullet bullets[MAX_BULLETS];

static Asteroid asteroids[MAX_ASTEROIDS];

void CheckCollisions(Player *player, bool *gameOver, int *level)
{
    // Check player-asteroid collision
    for (int i = 0; i < MAX_ASTEROIDS; i++)
    {
        if (asteroids[i].active)
        {
            if (CheckCollisionCircleRec(asteroids[i].position, asteroids[i].radius, (Rectangle){player->position.x - 10, player->position.y - 10, 20, 20}))
            {
                *gameOver = true;
                return;
            }
        }
    }

    // Check bullet-asteroid collision
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (bullets[i].active)
        {
            for (int j = 0; j < MAX_ASTEROIDS; j++)
            {
                if (asteroids[j].active)
                {
                    if (CheckCollisionCircles(bullets[i].position, 2, asteroids[j].position, asteroids[j].radius))
                    {
                        bullets[i].active = false;
                        asteroids[j].active = false;
                        // Add scoring or level advancement logic here
                    }
                }
            }
        }
    }

    // Check if all asteroids are destroyed to advance level
    bool allDestroyed = true;
    for (int i = 0; i < MAX_ASTEROIDS; i++)
    {
        if (asteroids[i].active)
        {
            allDestroyed = false;
            break;
        }
    }

    if (allDestroyed)
    {
        *level += 1;
        InitAsteroids(); // Reset asteroids for next level
    }
}
