#pragma once
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include "consts.h"
#include "math.h"

typedef struct  Player
{
    Vector2 pos;
    int vel;
    int dir;
    bool canJump;
} Player;

Player* InitPlayer(Vector2 pos);
Player* InitPlayer();

void UpdatePlayer(Player& player, std::vector<Rectangle> collidables);
void DrawPlayer(Player& player);
void UpdatePlayerCamera();
void HandlePlayerInputs(Player* player); 
float getDistanceFromGridEdge(int dir, float pos);
