#include "GridUtils.h"

Color getVoxelColor(Voxel voxel);

void drawChunk(std::vector<Voxel> chunk) {
    for(int i = 0 ; i < CHUNK_HEIGHT * CHUNK_WIDTH ; i++ ){
        GridCoord coords = GetGridCoordsFromFlatIndex(i);
        DrawVoxel(coords, chunk[i]); 
    }
}

std::vector<Voxel> InitializeGridChunk() {
    std::vector<Voxel> chunk = std::vector<Voxel>(CHUNK_HEIGHT * CHUNK_WIDTH, Voxel{VoxelType::air, false});
    float seed = Remap(GetRandomValue(0 ,0xffffff),0, 0xffffff, 0, 0.1f);
    Image noise = GenImagePerlinNoise(CHUNK_WIDTH, 1, 0, 0, seed);
    
    
    for(int x = 0; x < CHUNK_WIDTH; x++ ){
        Color pixel = GetImageColor(noise, x, 0);

        int initialYValue =(int)Remap(pixel.r, 0, 255, CHUNK_HEIGHT, 0);
        for(int y = initialYValue; y < CHUNK_HEIGHT; y++) {
            chunk[GetFlatIndexFromGridCoords(GridCoord{x, y})] = Voxel{VoxelType::grass, true};
        }
    }

    return chunk;
}

GridCoord GetGridCoordsFromFlatIndex(int index) {
    return GridCoord{index % CHUNK_WIDTH, index / CHUNK_WIDTH};
}

int GetFlatIndexFromGridCoords(GridCoord coords) {
    return coords.y * CHUNK_WIDTH + coords.x;
}



void DrawVoxel(GridCoord coords, Voxel voxel) {
    if(voxel.type == VoxelType::air) return;
    DrawRectangle(coords.x * CELL_SIZE, coords.y * CELL_SIZE, CELL_SIZE, CELL_SIZE, getVoxelColor(voxel));
    DrawRectangleLines(coords.x * CELL_SIZE, coords.y * CELL_SIZE, CELL_SIZE, CELL_SIZE, PURPLE);
}

Color getVoxelColor(Voxel voxel) {
    switch (voxel.type)
    {
    case VoxelType::grass:
        return GREEN;
        break;
    default:
        return RED;
        break;
    }
}