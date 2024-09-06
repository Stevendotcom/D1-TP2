#include "raylib.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TP2");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLANK);

        DrawRectangle(0, 0, 90, 90, WHITE);

        EndDrawing();
    }

}
