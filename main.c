#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MINA 80

typedef struct {
    Vector2 position;
    Vector2 scale;
    int direction; // 0 = LEFT, 1 = RIGHT
} Mina;

int main(void) {

    int curMinawanSprites = 0;
    Mina minawanData[MAX_MINA];



    InitWindow(1280, 720, "Minawan Land");
    SetTargetFPS(30);

    for (int i = 0; i < MAX_MINA; i++) {
        
        minawanData[i].position = (Vector2) {GetRandomValue(0, 1240), 620};
        minawanData[i].scale = (Vector2) {1, 1};
        minawanData[i].direction = GetRandomValue(0, 1);
    }

    Texture2D minawan_tex = LoadTexture("resources/minawan.png");
    Texture2D minawanRight_tex = LoadTexture("resources/minawanRight.png");

    while (WindowShouldClose() == false) {
        BeginDrawing();
            ClearBackground(GREEN);

        BeginDrawing();
            ClearBackground(GREEN);

            // DrawTextureEx(minawan_tex, (Vector2) {80, 80}, 0, 1, RAYWHITE);

            for (int i = 0; i < MAX_MINA; i++) {
                if (minawanData[i].direction == 0) {
                    DrawTextureEx(minawan_tex, minawanData[i].position, 0, minawanData[i].scale.x, RAYWHITE);
                } else {
                    DrawTextureEx(minawanRight_tex, minawanData[i].position, 0, minawanData[i].scale.x, RAYWHITE);
                }

                switch(minawanData[i].direction) {
                    case 0:
                        minawanData[i].scale.x = 1;
                        minawanData[i].position.x -= 3;
                        break;
                    case 1:
                        minawanData[i].scale.x = 1;
                        minawanData[i].position.x += 3;
                        break;
                    default:
                        minawanData[i].direction = 0;
                        break;
                
                }

                if (minawanData[i].position.x > 1240) {
                    minawanData[i].direction = 0;
                } else if (minawanData[i].position.x < 0) {
                    minawanData[i].direction = 1;
                }
            }

        EndDrawing();
    }

    return 0;
}