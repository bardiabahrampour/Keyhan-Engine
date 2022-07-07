#pragma once
#include <string>
#include <map>
#include <SDL/SDL.h>
#include "quickmath.h"

namespace Keyhan {

	enum class WindowMode {
		Windowed,
		Fullscreen,
		Borderless,
	};

	std::map<Vector2D, std::string> WindowResolutions{
		{ Vector2D{ 1920,1080 }, "1920x1080 16:9" },
		{ Vector2D{ 800,600 },   "800x600 4:5" },
		{ Vector2D{ 600,400 },   "600x400 4:5"},
	};

	class Window {
		std::string   title;
		Keyhan::Color clearcolor;
		bool          fullscreen;
		SDL_Window*   sdl_window;
		Vector2D      resolution;
		WindowMode    mode;
		bool          vsync;

	};
};