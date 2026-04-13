#include <raylib.h>
#include "consts.h"
#include "Player.h"
#include "GridUtils.h"
#include "Voxel.h"

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