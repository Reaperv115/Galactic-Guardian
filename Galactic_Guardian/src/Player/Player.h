#pragma once

namespace glitc
{
	class Player
	{
	public:
		Player() = default;
		Player(float speed, Vector2 pos, float width, float height);
		void Draw();
		Texture2D GetPlayerTexture() const;
		Vector2 GetPlayerPosition() const;
	private:
		Rectangle playerRect;
		float f_speed;
		Vector2 v2_position;
		Image playerImage;
		Texture2D playerTexture;
		float playerWidth, playerHeight;
	};
}

