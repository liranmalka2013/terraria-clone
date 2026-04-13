#include "Player.h"
#include <iostream>
#include "Voxel.h"

void UpdatePlayer(Player* player, std::vector<Voxel> collidables) {
    Vector2 oldPos = Vector2(player->pos);
    Vector2 newPos = Vector2(player->pos);
    Vector2 playerForces = Vector2Zero();
    float delta = GetFrameTime();

    player->vel.x = PLAYER_SPEED_MULTIPLIER * player->dir;

    if(player->isJumping){
        player->vel.y = -INITIAL_PLAYER_JUMP_FORCE
        
    }else{
        playerForces.y += GRAVITY_MULTIPLIER;
    }
    playerForces = Vector2Add(playerForces, player->vel); 

    Vector2 deltaForces = Vector2Scale(playerForces, delta);

    //check collision
    Rectangle horizontalPlayerMove = {oldPos.x + deltaForces.x, oldPos.y, player->size.x, player->size.y };
    Rectangle verticlePlayerMove = {oldPos.x, oldPos.y + deltaForces.y,  player->size.x, player->size.y};
   
    bool collidedX, collidedY = false;
    for(const auto& collidable : collidables) {
        if(!collidedX && CheckCollisionRecs(horizontalPlayerMove, collidable)){
            Rectangle overlap = GetCollisionRec(horizontalPlayerMove, collidable);
            if(overlap.width > 0){
                deltaForces.x = 0;
                
                newPos.x= getPositionOfSnappingLineX(player->dir, oldPos.x, player->size.x);
                collidedX = true;
            }
        }
        
        if(!collidedY && CheckCollisionRecs(verticlePlayerMove, collidable)){
            Rectangle overlap = GetCollisionRec(verticlePlayerMove, collidable);
            if(overlap.height > 0) {
                
                    int dir = playerForces.y > 0 ? -1 : 1;
                    playerForces.y = 0;
                    //snap to ground
                    std::cout << collidable.y << std::endl;    
                    newPos.y = getPositionOfSnappingLineY(dir, oldPos.y, player->size.y);
                    std::cout << newPos.y << std::endl;    
    
                    player->canJump = true;
                    collidedY = true;

            }

        }

        if(collidedX && collidedY) break;
    }
    
    player->pos = Vector2Add(newPos, deltaForces);   
}

int getPositionOfSnappingLineX(int dir, float pos, float sizeInAxis){
    return dir > 0 ? (std::ceil(pos / CELL_SIZE) * CELL_SIZE) - sizeInAxis : (std::floor(pos / CELL_SIZE) * CELL_SIZE);
}

int getPositionOfSnappingLineY(int dir, float pos, float sizeInAxis){
    std::cout << (std::ceil((pos +sizeInAxis) / CELL_SIZE)) * CELL_SIZE << std::endl;
    return((std::ceil((pos +sizeInAxis) / CELL_SIZE)) * CELL_SIZE) - sizeInAxis;
    // return dir > 0 ? (std::ceil(pos / CELL_SIZE) * CELL_SIZE) + sizeInAxis :
}

void DrawPlayer(Player& player){
    DrawRectangleLines(player.pos.x, player.pos.y, player.size.x, player.size.y, GREEN);
}

void UpdatePlayerCamera(Player* player) {

}

void HandlePlayerInputs(Player* player) {
    if(IsKeyDown(KEY_D)) player->dir = 1;
    else if(IsKeyDown(KEY_A)) player->dir = -1;
    else player->dir = 0;

    if(player->canJump && (IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_W))){
        player->isJumping = true;
        player->canJump = false;
    }else{
        player->isJumping = false;
    }
}


Player* InitPlayer(Vector2 pos, Vector2 size) {
    return new Player{pos, size, Vector2Zero(), 0, false, false};
}

Player* InitPlayer() {
    return new Player{};
}