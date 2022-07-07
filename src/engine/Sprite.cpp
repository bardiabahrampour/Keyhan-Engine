#include "Sprite.h"

Keyhan::Sprite::Sprite(std::string texturepath, Vector2D pos,Root* root) {
	this->root = root;
	texture.LoadFromFile(texturepath, false);
	this->position.x = root->GetPosition().x + pos.x;
	this->position.y = root->GetPosition().y + pos.y;
	uuid.GenerateID(class_name);
}

void Keyhan::Sprite::Hide() {
	this->visible = false;
}

void Keyhan::Sprite::Show() {
	this->visible = true;
}

bool Keyhan::Sprite::GetVisibility() {
	return this->visible;
}

void Keyhan::Sprite::SetVisibility(bool w) {
	if (w) {
		this->Show();
		return;
	}
	this->Hide();
}