#pragma once
#include "quickmath.h"

namespace Keyhan {
	class Root {
		Vector2D position;
	public:
		Vector2D GetPosition();
		void	 SetPosition(Vector2D pos);
		void     SetPosition(int x, int y);
		Root();
	};
};

