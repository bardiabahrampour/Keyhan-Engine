#pragma once
#include "Entity.h"
#include "api.h"
#include "Texture.h"
#include "Root.h"

namespace Keyhan {
	class Sprite : Keyhan::Entity {
		Keyhan::Root* root;
		Keyhan::Texture texture;
		const std::string class_name = "Sprite";
		bool visible = true;
	public:
		Sprite(std::string texturepath, Vector2D pos,Root* root);
		void Hide();
		void Show();
		bool GetVisibility();
		void SetVisibility(bool w);
	};
};

