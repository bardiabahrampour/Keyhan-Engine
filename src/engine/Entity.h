#pragma once
#pragma comment(lib, "rpcrt4.lib")
#include "api.h"
#include "quickmath.h"
#include <Windows.h>
#include <string>

namespace Keyhan {
	class KEYHAN_API Entity {
		Vector2D position;
		UUID uuid;
		std::string id;

		void SetID();
	public:
		Vector2D getPosition();
		void setPosition(int x, int y);
		void setPosition(int x, int y);
		
		Entity(int x, int y);
		Entity(Vector2D pos);
		Entity();
		~Entity();
	};
};

//TODO: Create a cross-platform id class later on