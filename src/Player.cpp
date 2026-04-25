#include "Player.h"

void UpdatePlayer(Player* player) {
   Vector2 newPos = Vector2(player->pos);
   Vector2 forces = Vector2();
   float deltaTime = GetFrameTime();
   
   forces.y += GRAVITY_MULTIPLIER;

   newPos = Vector2Add(newPos, Vector2Scale(forces, deltaTime));

   player->pos = newPos;
}

void DrawPlayer(Player& player){
    DrawRectangleLines(player.pos.x, player.pos.y, player.size.x, player.size.y, RED);
}

void UpdatePlayerCamera(Player* player) {

}

void HandlePlayerInputs(Player* player) {
    if(IsKeyDown(KEY_D)) player->dir = 1;
    else if(IsKeyDown(KEY_A)) player->dir = -1;
    else player->dir = 0;

    // if(player->canJump && (IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_W))){
    //     player->isJumping = true;
    //     player->canJump = false;
    // }else{
    //     player->isJumping = false;
    // }
}


Player* InitPlayer(Vector2 pos, Vector2 size) {
    return new Player{pos, size, Vector2Zero(), 0, false, false};
}

Player* InitPlayer() {
    return new Player{};
}