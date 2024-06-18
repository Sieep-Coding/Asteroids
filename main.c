#include "raylib.h"
#include "player.h"
#include "asteroid.h"
#include "bullet.h"
#include "utils.h"
#include <math.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Asteroids Game");
    SetTargetFPS(60);

    Player player;
    InitPlayer(&player);

    // Asteroid and Bullet initializations
    InitAsteroids();
    InitBullets();

    int level = 1;
    bool gameOver = false;

    while (!WindowShouldClose()) {
        // Update game logic
        if (!gameOver) {
            UpdatePlayer(&player);
            UpdateAsteroids();
            UpdateBullets();
            CheckCollisions(&player, &gameOver, &level);
        }

        // Draw everything
        BeginDrawing();
        ClearBackground(BLACK);

        if (gameOver) {
            DrawText("GAME OVER", SCREEN_WIDTH / 2 - 80, SCREEN_HEIGHT / 2, 20, RED);
        } else {
            DrawPlayer(&player);
            DrawAsteroids();
            DrawBullets();
            DrawText(TextFormat("Level: %d", level), 10, 10, 20, WHITE);
        }

        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
