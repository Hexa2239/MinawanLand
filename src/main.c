
#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir


typedef struct {
	Vector2 position;
	int direction;
} MinaData;

int main ()
{
	InitWindow(1280, 720, "Minawan Land");

	int MINA_MAX = 30;
	int curMina = 0;
	MinaData minaDataHold[MINA_MAX];

	for (int i = 0; i < MINA_MAX; i++) {
		minaDataHold[i].position = (Vector2) {GetRandomValue(0, 1240), 620};
		minaDataHold[i].direction = GetRandomValue(0, 1);
	}

	SetTargetFPS(30);

	SearchAndSetResourceDir("resources");

	Texture2D minawan = LoadTexture("minawan.png");
	Texture2D minawanRight = LoadTexture("minawanRight.png");

	while(WindowShouldClose() == false) {

		BeginDrawing();
			ClearBackground(GREEN);

		// DrawTexture(minawan, 300, 620, RAYWHITE); We are drawing more than wan texture now!

		for (int i = 0; i < MINA_MAX; i++) {
			if (minaDataHold[i].direction == 0) {
				DrawTexture(minawan, minaDataHold[i].position.x, minaDataHold[i].position.y, RAYWHITE);
			} else {
				DrawTexture(minawanRight, minaDataHold[i].position.x, minaDataHold[i].position.y, RAYWHITE);
			}

			switch (minaDataHold[i].direction) {
				case 0: // LEFT
					minaDataHold[i].position.x -= 3;
					break;
				case 1:
					minaDataHold[i].position.x += 3;
					break;

			}

			if (minaDataHold[i].position.x < 0) {
				minaDataHold[i].direction = 1;
			} else if (minaDataHold[i].position.x > 1200) {
				minaDataHold[i].direction = 0;
			}
		}


		EndDrawing();
	}

	
	CloseWindow();
	return 0;
}