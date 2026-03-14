#include "Player.h"
#include <raylib.h>

Player::Player() : posX(0), posY(0), speedX(0), speedY(0){}

void Player::draw() {
    DrawCircle(posX, posY, 10, RED);
}

void Player::update() {
    
}


