#include "raylib.h"
#include "stdio.h"

int main(void) {
    InitWindow(1280, 720, "Minawan Land");

    while (WindowShouldClose() == false) {
        BeginDrawing();
            ClearBackground(RAYWHITE);

        EndDrawing();
    }

    return 0;
}