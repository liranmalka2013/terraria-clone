#pragma once
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include "consts.h"
#include "math.h"

typedef struct  Player
{
    Vector2 pos;
    Vector2 size;

    Vector2 vel;
    int dir;
    bool canJump;
    bool isJumping;
} Player;

Player* InitPlayer(Vector2 pos, Vector2 size);
Player* InitPlayer();

void UpdatePlayer(Player* player, std::vector<Rectangle> collidables);
void DrawPlayer(Player& player);
void UpdatePlayerCamera();
void HandlePlayerInputs(Player* player); 
int getPositionOfSnappingLineX(int dir, float pos, float sizeInAxis);
int getPositionOfSnappingLineY(int dir, float pos, float sizeInAxis);
