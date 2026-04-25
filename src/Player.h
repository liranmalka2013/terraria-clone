#pragma once

#include <raylib.h>
#include <raymath.h>
#include <vector>
#include <iostream>

#include "GridUtils.h"
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

void UpdatePlayer(Player* player);
void DrawPlayer(Player& player);
void UpdatePlayerCamera();
void HandlePlayerInputs(Player* player); 
