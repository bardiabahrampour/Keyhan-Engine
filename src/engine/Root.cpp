#include "Root.h"

Keyhan::Vector2D Keyhan::Root::GetPosition() {
	return this->position;
}

void Keyhan::Root::SetPosition(Vector2D pos) {
	this->position = pos;
}

void Keyhan::Root::SetPosition(int x, int y) {
	this->position.x = x;
	this->position.y = y;
}

Keyhan::Root::Root() {
	this->SetPosition(0, 0);
}