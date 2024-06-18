#include "raylib.h"
#include "asteroid.h"
#include "utils.h"
#include <math.h>

#define MAX_ASTEROIDS 10

static Asteroid asteroids[MAX_ASTEROIDS];

void InitAsteroids(void)
{
    for (int i = 0; i < MAX_ASTEROIDS; i++)
    {
        asteroids[i].position = (Vector2){GetRandomValue(0, SCREEN_WIDTH), GetRandomValue(0, SCREEN_HEIGHT)};
        asteroids[i].velocity = (Vector2){GetRandomValue(-100, 100) / 100.0f, GetRandomValue(-100, 100) / 100.0f};
        asteroids[i].radius = GetRandomValue(15, 30);
        asteroids[i].active = true;
    }
}

void UpdateAsteroids(void)
{
    for (int i = 0; i < MAX_ASTEROIDS; i++)
    {
        if (asteroids[i].active)
        {
            // Update asteroid position based on velocity
            asteroids[i].position.x += asteroids[i].velocity.x;
            asteroids[i].position.y += asteroids[i].velocity.y;

            // Check if asteroid goes out of bounds and wrap it around
            if (asteroids[i].position.x > SCREEN_WIDTH + asteroids[i].radius)
                asteroids[i].position.x = -asteroids[i].radius;
            else if (asteroids[i].position.x < -asteroids[i].radius)
                asteroids[i].position.x = SCREEN_WIDTH + asteroids[i].radius;

            if (asteroids[i].position.y > SCREEN_HEIGHT + asteroids[i].radius)
                asteroids[i].position.y = -asteroids[i].radius;
            else if (asteroids[i].position.y < -asteroids[i].radius)
                asteroids[i].position.y = SCREEN_HEIGHT + asteroids[i].radius;
        }
    }
}

void DrawAsteroids(void)
{
    for (int i = 0; i < MAX_ASTEROIDS; i++)
    {
        if (asteroids[i].active)
        {
            DrawCircle(asteroids[i].position.x, asteroids[i].position.y, asteroids[i].radius, GRAY);
        }
    }
}