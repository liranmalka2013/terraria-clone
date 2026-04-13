#include "Player.h"
#include "Voxel.h"

using std::vector;

Vector2 GridIndexToWorldCoords(Vector2 gridIndex);
Vector2 WorldCoordsToGridIndex(Vector2 worldCoords);

std::vector<Rectangle>  GetSurroundingVoxels(Player* player, std::vector<Rectangle> grid);

std::vector<Voxel> InitializeGrid();