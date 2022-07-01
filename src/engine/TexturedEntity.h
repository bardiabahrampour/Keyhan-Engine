#pragma once
#include "Entity.h"
#include "api.h"
#include "Texture.h"

namespace Keyhan {
	class __declspec(dllexport) Sprite : Keyhan::Entity {
		Keyhan::Texture texture;
		const std::string class_name = "Sprite";
	public:
		Sprite(std::string texturepath, Vector2D pos);
	};
};

