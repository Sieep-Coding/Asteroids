#include "utils.h"
#include <stdio.h> // For debugging, remove in final version
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
            // Calculate distance between player and asteroid
            float distance = Vector2Distance(player->position, asteroids[i].position);
            if (distance < player->radius + asteroids[i].radius)
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
                    // Calculate distance between bullet and asteroid
                    float distance = Vector2Distance(bullets[i].position, asteroids[j].position);
                    if (distance < bullets[i].radius + asteroids[j].radius)
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
        *level += 1; // Increase level after all asteroids destroyed
        InitAsteroids(); // Reset asteroids for next level
    }
}
