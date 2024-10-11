#include "raylib.h"
#include "stdio.h"

int main(void) {
    InitWindow(1280, 720, "Minawan Land");
    SetTargetFPS(60);

    Texture2D minawan = LoadTexture("resources/Minawan_Clean.png");

    while (WindowShouldClose() == false) {
        BeginDrawing();
            ClearBackground(GREEN);

        EndDrawing();

        BeginDrawing();
            DrawTexture(minawan, GetScreenWidth() - 100, GetScreenHeight() - 100, RAYWHITE);

        EndDrawing();
        
    }

    return 0;
}