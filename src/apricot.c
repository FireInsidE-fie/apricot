#include "../include/apricot.h"

// Begin macro definitions
#define TITLE_COLOR ORANGE
#define TEXT_COLOR BLACK

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

		DrawText("apricot", 20, 20, 64, TITLE_COLOR);
		DrawText(TextFormat("File name: %s", argv[1]), 20, 100, 32, TEXT_COLOR);
		DrawText(TextFormat("Total size: %uKB", header->overall_size / 1000), 20, 150, 20, TEXT_COLOR);
		DrawText(TextFormat("Number of channels: %u", header->channels), 20, 175, 20, TEXT_COLOR);
		DrawText(TextFormat("Sample rate : %uhz", header->sample_rate), 20, 200, 20, TEXT_COLOR);
		DrawText(TextFormat("Bits per sample: %u", header->bits_per_sample), 20, 225, 20, TEXT_COLOR);
		DrawText(TextFormat("Duration of file: %u seconds", header->data_size / header->byterate), 20, 250, 20, TEXT_COLOR);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
