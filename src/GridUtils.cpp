#include "GridUtils.h"

Vector2 GridIndexToWorldCoords(Vector2 gridIndex) {
    return Vector2{gridIndex.x * CELL_SIZE, gridIndex.y * CELL_SIZE};
};

Vector2 WorldCoordsToGridIndex(Vector2 worldCoords) {

}

std::vector<Rectangle> GetSurroundingVoxels(Player* player, std::vector<Rectangle> grid) {

}