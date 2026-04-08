#include "Game.h"

GameManger::GameManger() {
    player = InitPlayer(Vector2{WIN_WIDTH/2, WIN_HEIGHT/2});


    for(int i = BOX_SIZE ; i < WIN_WIDTH - BOX_SIZE; i+=BOX_SIZE ){
        blocks.push_back((Rectangle){i, 500, BOX_SIZE, BOX_SIZE});
    }
    blocks.push_back((Rectangle){BOX_SIZE * 3, 450, BOX_SIZE, BOX_SIZE});
    blocks.push_back((Rectangle){BOX_SIZE * 10, 450, BOX_SIZE, BOX_SIZE});
}

GameManger::~GameManger() {
    delete player;
}

void GameManger::draw() {
    DrawPlayer(*player);
    for(const Rectangle block : blocks){
        DrawRectangle(block.x, block.y, block.width, block.height, RED);
    }
}

void GameManger::update() {
    UpdatePlayer(*player, blocks);
}

void GameManger::handleInputs() {
    HandlePlayerInputs(player);
}
