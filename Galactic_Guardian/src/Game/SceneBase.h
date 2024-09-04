#pragma once

namespace glitc
{
	class SceneBase
	{
	protected:
		virtual void Initialize() = 0;
		virtual void Update(float dt) = 0;
		virtual void Render() = 0;
		virtual void Destruct() = 0;
	};
}

