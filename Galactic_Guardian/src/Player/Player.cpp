#include "ggpch.h"
#include "Player.h"

glitc::Player::Player(float speed, Vector2 pos, float width, float height)
	: f_speed(speed), v2_position(pos), playerWidth(width), playerHeight(height)
{
	playerImage = LoadImage("src/Pictures/tank.png");
	playerTexture = LoadTextureFromImage(playerImage);

	playerRect = { v2_position.x, v2_position.y, playerWidth, playerHeight};
}

void glitc::Player::Draw()
{
	DrawTexturePro(playerTexture,
		Rectangle{ 0, 0, (float)playerTexture.width, (float)playerTexture.height },
		Rectangle(v2_position.x, v2_position.y, playerRect.width, playerRect.height),
		Vector2{ 0.0f, 0.0f }, 0.0f, WHITE);
}

Texture2D glitc::Player::GetPlayerTexture() const
{
	return playerTexture;
}

Vector2 glitc::Player::GetPlayerPosition() const
{
	return { v2_position.x, v2_position.y };
}
