#include "Player.h"

void UpdatePlayer(Player& player, std::vector<Rectangle> collidables) {
    Vector2 oldPos = player.pos;
    Vector2 playerForces = Vector2Zero();
    float delta = GetFrameTime();

    playerForces.x += player.vel;

    playerForces.y += GRAVITY_MULTIPLIER;

    Vector2 deltaForces = Vector2Scale(playerForces, delta);

    //check collision
    Rectangle horizontalPlayerMove = {oldPos.x + deltaForces.x, oldPos.y, BOX_SIZE, BOX_SIZE};
    Rectangle verticlePlayerMove = {oldPos.x, oldPos.y + deltaForces.y, BOX_SIZE, BOX_SIZE};
   
    bool collidedX, collidedY = false;
    for(const auto& collidable : collidables) {
        if(!collidedX && CheckCollisionRecs(horizontalPlayerMove, collidable)){
            Rectangle overlap = GetCollisionRec(horizontalPlayerMove, collidable);
            if(overlap.width > 0){
                //snap to ground
                deltaForces.x = getDistanceFromGridEdge(horizontalPlayerMove.x > oldPos.x, oldPos.x);
                
                collidedX = true;
            }
        }
        
        if(!collidedY && CheckCollisionRecs(verticlePlayerMove, collidable)){
            Rectangle overlap = GetCollisionRec(verticlePlayerMove, collidable);
            if(overlap.height > 0) {
                //snap to ground
                deltaForces.y = getDistanceFromGridEdge(horizontalPlayerMove.y <= oldPos.y, oldPos.y);

                player.canJump = true;
                collidedY = true;
            }

        }

        if(collidedX && collidedY) break;
    }
    
    player.pos = Vector2Add(player.pos, deltaForces);   
}

float getDistanceFromGridEdge(int dir, float pos){
    float distanceFromWall = dir > 0 ? BOX_SIZE - fmod(pos, BOX_SIZE) : -fmod(pos, BOX_SIZE);
    return fmod(distanceFromWall, BOX_SIZE) ? distanceFromWall : 0;
}

void DrawPlayer(Player& player){
    DrawRectangle(player.pos.x, player.pos.y, BOX_SIZE, BOX_SIZE, GREEN);
}

void UpdatePlayerCamera(Player* player) {

}

void HandlePlayerInputs(Player* player) {
    if(IsKeyDown(KEY_D)) player->dir = 1;
    else if(IsKeyDown(KEY_A)) player->dir = -1;
    else player->dir = 0;

    player->vel = PLAYER_SPEED_MULTIPLIER * player->dir;
}


Player* InitPlayer(Vector2 pos) {
    return new Player{pos};
}

Player* InitPlayer() {
    return new Player{};
}