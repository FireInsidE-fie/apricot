#include "../include/apricot.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int		screenWidth = 1200;
	const int		screenHeight = 800;
	//const int		darkMode = 0;
	const t_header	*header = read_wav_head(argv[1]);

	if (argc != 2)
		return (-1);

	InitWindow(screenWidth, screenHeight, "apricot");

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("apricot", 20, 20, 64, ORANGE);
		DrawText(TextFormat("Number of channels: %08i", header->channels), 200, 80, 20, RED);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
