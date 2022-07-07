#pragma once
#include "pch.h"
#include "api.h"
#include "Texture.h"
#include <functional>

typedef std::function<void()> LoopFunc;

namespace Keyhan {

	//SDL Render Scale Quality
	enum class RenderQualtiy {
		Nearest = 0,
		Linear  = 1,
		Best    = 2,
	};

	class __declspec(dllexport) Renderer {
	public:
		Renderer();
		~Renderer();

		void setLoop(LoopFunc* loop);
		void RenderTexture(Texture*);
	private:
		SDL_Rect mainViewport = { 0,0,0,0 };
	};
};
