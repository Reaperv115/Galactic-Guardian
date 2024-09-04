#include "ggpch.h"
#include "Scene.h"

void glitc::Scene::Initialize()
{
	
	// stuff for matrices when I start to use them
	double FoV = 90.0f * (std::numbers::pi / 180.000);
	double aspectRatio = (double)screenWidth / (double)screenHeight;
	double nearZ = 0.1;
	double farZ = 100.0;
	//

	InitWindow(screenWidth, screenHeight, "Galactic Guardian");

	backgroundImage = LoadImage("src/Pictures/battlenewyork.png");
	backgroundTexture = LoadTextureFromImage(backgroundImage);
	renderTexture = LoadRenderTexture(screenWidth, screenHeight);
	renderTexture.texture = backgroundTexture;
}

void glitc::Scene::Update(float dt)
{

}

void glitc::Scene::Render()
{
	BeginDrawing();
	ClearBackground(WHITE);
	DrawTexturePro(renderTexture.texture, Rectangle{ 0.0f, 0.0f, (float)renderTexture.texture.width, (float)renderTexture.texture.height },
		Rectangle{ 0, 0, (float)screenWidth, (float)screenHeight },
		Vector2{ 0,0 }, 0.0f, WHITE);
	EndDrawing();
}

void glitc::Scene::Destruct()
{
	CloseWindow();
}
