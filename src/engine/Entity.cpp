#include "Entity.h"

Keyhan::Vector2D Keyhan::Entity::getPosition() {
	return this->position;
}

void Keyhan::Entity::setPosition(int x, int y) {
	this->position.x = x;
	this->position.y = y;
}

void Keyhan::Entity::setPosition(Vector2D pos) {
	this->position = pos;
}

Keyhan::Entity::Entity(int x, int y) {
	position.x = x;
	position.y = y;
	uuid.GenerateID(class_name);
}

Keyhan::Entity::Entity(Vector2D pos) {
	position = pos;
	uuid.GenerateID(class_name);
}

//DO NOT USE THIS!!
Keyhan::Entity::Entity() {
	this->setPosition(0, 0);
	uuid.GenerateID(class_name);
}