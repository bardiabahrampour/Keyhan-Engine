#pragma once
#include "api.h"
#include "UUIDGen.h"
#include "quickmath.h"
#include <Windows.h>
#include <string>

/*
	======================================================
	Entity is a base class for any `thing` that is movable
	and has a unique id
	like: Spawnpoint, Checkpoint , Sprites, Bodies etc...
	======================================================
	it is not exported by the dll because it is unusable
	for a game developer
	======================================================
*/

namespace Keyhan {
	//Base class for any movable object
	class Entity {
	protected:
		Vector2D position;
		ID uuid;
		const std::string class_name = "Entity";

	public:
		Vector2D GetPosition();
		void SetPosition(int x, int y);
		void SetPosition(Vector2D pos);
		
		Entity(int x, int y);
		Entity(Vector2D pos);
		Entity();
	};
};
