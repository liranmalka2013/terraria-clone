#pragma once

#include <raylib.h>
#include <iostream>

#include "consts.h"
#include "Player.h"
#include "GridUtils.h"


using std::vector;

class GameManger {
public:
    GameManger();
    ~GameManger();

    void draw();
    void handleInputs();
    void update();
private:
    Player* player;
    std::vector<Voxel> grid;    
};