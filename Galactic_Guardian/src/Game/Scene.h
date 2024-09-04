#pragma once
#include "SceneBase.h"
#include "../Player/Player.h"

namespace glitc
{
	class Scene : public SceneBase
	{
	public:
		Scene();
		void Initialize() override;
		void Update(float dt) override;
		void Render() override;
		void Destruct() override;
	private:
		const int screenWidth = 1080;
		const int screenHeight = 720;

		Image backgroundImage;
		Texture2D backgroundTexture;
		RenderTexture2D renderTexture;

		Player player;
	};
}

