#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Player {
    Vector2 position;
    Vector2 velocity;
    float rotation;
    float speed;
    float radius;
    bool active;

} Player;

void InitPlayer(Player *player);
void UpdatePlayer(Player *player);
void DrawPlayer(Player *player);


#endif