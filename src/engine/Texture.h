#pragma once
#include "pch.h"
#include "api.h"
#include <string>
#include <SDL/SDL.h>

namespace Keyhan {
	class KEYHAN_API Texture {
	public:
		Texture(SDL_Renderer* renderer);
		~Texture();

		void         LoadFromFile(std::string path, bool colorKey);
		void         Free();
		unsigned int GetWidth();
		unsigned int GetHeight();

	private:
		unsigned int width, height;
		SDL_Texture* sdl_texture;
		SDL_Renderer* renderer;
	};
};