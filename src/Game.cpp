#include "Game.h"

GameManger::GameManger() {
    player = InitPlayer(Vector2{WIN_WIDTH/2, WIN_HEIGHT/4}, Vector2{CELL_SIZE * 0.8, CELL_SIZE * 1.3});
    grid = InitializeGridChunk();
}

GameManger::~GameManger() {
    delete player;
}

void GameManger::draw() {
    drawChunk(grid);
    DrawPlayer(*player);
}

void GameManger::update() {
    UpdatePlayer(player);
}

void GameManger::handleInputs() {
    HandlePlayerInputs(player);
}
