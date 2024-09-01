

/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include <iostream>
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include <numbers>
#include <cmath>

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 1080;
	const int screenHeight = 720;

	double FoV = 90.0f * (std::numbers::pi / 180.000);
	double aspectRatio = (double)screenWidth / (double)screenHeight;
	double nearZ = 0.1;
	double farZ = 100.0;

	InitWindow(screenWidth, screenHeight, "Galactic Guardian");


	Rectangle player = { screenWidth / 2, screenHeight / 2, 40.0f, 40.0f };

	Rectangle backgroundRectangle = { 0, 0, screenWidth, screenHeight };
	
	Image playerTexture = LoadImage("src/Pictures/tank.png");
	Image backgroundImage = LoadImage("src/Pictures/battlenewyork.png");
	Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);
	RenderTexture2D renderTexture = LoadRenderTexture(screenWidth, screenHeight);
	renderTexture.texture = backgroundTexture;
	SetTextureFilter(renderTexture.texture, TEXTURE_FILTER_BILINEAR);
	Rectangle sourcerect = { 0.0f, 0.0f, (float)renderTexture.texture.width, -(float)renderTexture.texture.height };
	Rectangle destrect = { 0.0f, 0.0f, (float)screenWidth, (float)screenHeight };

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		float scale = MIN((float)GetScreenWidth() / screenWidth, (float)GetScreenHeight() / screenHeight);
		
		//----------------------------------------------------------------------------------
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(WHITE);
		DrawTexturePro(renderTexture.texture, Rectangle{0.0f, 0.0f, (float)renderTexture.texture.width, (float)renderTexture.texture.height},
			Rectangle{
				(GetScreenWidth() - ((float)screenWidth * scale)) * 0.5f, (GetScreenHeight() - ((float)screenHeight * scale)) * 0.5f,
				(float)screenWidth * scale, (float)screenHeight * scale}, 
				Vector2{0,0}, 0.0f, WHITE);
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
