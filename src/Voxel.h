#include <raylib.h>
#include <cstdint>

enum VoxelType : uint8_t {
    air = 0,
    grass = 1,
};

typedef struct Voxel
{
    VoxelType type;
    uint8_t isCollidable;
} Voxel;

void DrawVoxel(Voxel voxel);