#include "Game.h"

GameManger::GameManger() {
    player = InitPlayer(Vector2{WIN_WIDTH/2, WIN_HEIGHT/2}, Vector2{CELL_SIZE * 0.8, CELL_SIZE * 1.3});

}

GameManger::~GameManger() {
    delete player;
}

void GameManger::draw() {
    DrawPlayer(*player);
    for(const Voxel voxel : grid){
        DrawVoxel(voxel);
    }
}

void GameManger::update() {
    UpdatePlayer(player, grid);
}

void GameManger::handleInputs() {
    HandlePlayerInputs(player);
}
