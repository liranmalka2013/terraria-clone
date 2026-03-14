#include "Game.h"
#include <raylib.h>


Game::Game(): player(Player()) {

}

void Game::draw() {
    player.draw();
}