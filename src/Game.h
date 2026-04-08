#include <raylib.h>
#include <vector>
#include "consts.h"
#include "Player.h"

class GameManger {
public:
    GameManger();
    ~GameManger();

    void draw();
    void handleInputs();
    void update();
private:
    Player* player;
    std::vector<Rectangle> blocks;    
};