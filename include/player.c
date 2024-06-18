#include "raylib.h"
#include "player.h"
#include <math.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

#define PLAYER_SPEED 5.0f
#define PLAYER_TURN_SPEED 3.0f

void InitPlayer(Player *player) {
    player->position = (Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    player->velocity = (Vector2){0, 0};
    player->rotation = 0.0f;
    player->speed = PLAYER_SPEED;
    player->active = true;
}

void UpdatePlayer(Player *player) {
    if (IsKeyDown(KEY_LEFT)) player->rotation -= PLAYER_TURN_SPEED;
    if (IsKeyDown(KEY_RIGHT)) player->rotation += PLAYER_TURN_SPEED;
    if (IsKeyDown(KEY_UP)) {
        player->velocity.x += sin(player->rotation * DEG2RAD) * player->speed * GetFrameTime();
        player->velocity.y -= cos(player->rotation * DEG2RAD) * player->speed * GetFrameTime();
    }

    player->position.x += player->velocity.x;
    player->position.y += player->velocity.y;

    // Screen wrap
    if (player->position.x > SCREEN_WIDTH) player->position.x = 0;
    if (player->position.x < 0) player->position.x = SCREEN_WIDTH;
    if (player->position.y > SCREEN_HEIGHT) player->position.y = 0;
    if (player->position.y < 0) player->position.y = SCREEN_HEIGHT;
}

void DrawPlayer(Player *player) {
    Vector2 v1 = {player->position.x + sinf(player->rotation * DEG2RAD) * 20, player->position.y - cosf(player->rotation * DEG2RAD) * 20};
    Vector2 v2 = {player->position.x - cosf(player->rotation * DEG2RAD) * 10, player->position.y - sinf(player->rotation * DEG2RAD) * 10};
    Vector2 v3 = {player->position.x + cosf(player->rotation * DEG2RAD) * 10, player->position.y + sinf(player->rotation * DEG2RAD) * 10};
    
    DrawTriangle(v1, v2, v3, WHITE);
}
