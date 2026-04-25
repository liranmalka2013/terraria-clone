#pragma once

#include <cstdint>

#include "Player.h"
#include "Consts.h"

using std::vector;

typedef struct GridCoord
{
    int x;
    int y;
} GridCoord;

enum class VoxelType : uint8_t {
    air,
    grass,
};

typedef struct Voxel
{
    VoxelType type;
    uint8_t isCollidable;
} Voxel;

std::vector<Voxel> InitializeGridChunk();
void drawChunk(std::vector<Voxel> chunk);
void DrawVoxel(GridCoord coord, Voxel voxel);

GridCoord GetGridCoordsFromFlatIndex(int index);
int GetFlatIndexFromGridCoords(GridCoord coords);

// std::vector<Rectangle>  GetSurroundingVoxels(Player* player, std::vector<Rectangle> grid);