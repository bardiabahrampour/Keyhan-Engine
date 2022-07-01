#include "TexturedEntity.h"

Keyhan::Sprite::Sprite(std::string texturepath, Vector2D pos) {
	texture.LoadFromFile(texturepath, false);
	this->position = pos;
	uuid.GenerateID(class_name);
}

