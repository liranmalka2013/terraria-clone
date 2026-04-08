#include "Block.h"

Block* InitGroundBlock(Rectangle rect) {
    
    return new Block{
        rect,
        RED,
        true  
    };
}
