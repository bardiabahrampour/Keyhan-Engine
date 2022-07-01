#pragma once
#include "api.h"
#include "UUIDGen.h"
#include "quickmath.h"
#include <Windows.h>
#include <string>

namespace Keyhan {
	class __declspec(dllexport) Entity {
	protected:
		Vector2D position;
		ID uuid;
		const std::string class_name = "Entity";

	public:
		Vector2D getPosition();
		void setPosition(int x, int y);
		void setPosition(Vector2D pos);
		
		Entity(int x, int y);
		Entity(Vector2D pos);
		Entity();
	};
};
