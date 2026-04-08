#include <raylib.h>

typedef struct Block
{
    Rectangle rect;
    Color color;
    bool isCollidable;
} Block;

Block* InitGroundBlock();
