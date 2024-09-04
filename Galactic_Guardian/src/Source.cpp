#include "ggpch.h"
#include "Game/Scene.h"

int main(void)
{
	glitc::Scene* scene = new glitc::Scene();
	scene->Initialize();

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		scene->Render();
	}

	return 0;
}
