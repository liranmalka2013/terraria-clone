#pragma once

class Player {
public: 
    Player();
    void draw();
    void update();

private:
    int posX;
    int posY;
    int speedX;
    int speedY;
        
};