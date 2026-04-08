#include <raylib.h>
#include "Game.h"
#include "consts.h"
int main() 
{
    // const Color darkGreen = {20, 160, 133, 255};
    
    constexpr int screenWidth = WIN_WIDTH;
    constexpr int screenHeight = WIN_HEIGHT;
    
    GameManger* game = new GameManger();

    
    InitWindow(screenWidth, screenHeight, "Terraria");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        game->handleInputs();
        game->update();
        
        BeginDrawing();
        ClearBackground(BLACK);

        game->draw();
        
        EndDrawing();
    }

    delete game;
    CloseWindow();
}