#pragma once
#include "pch.h"
#include "api.h"
#include "Texture.h"
#include <functional>

typedef std::function<void()> LoopFunc;

namespace Keyhan {
	class KEYHAN_API Renderer {
	public:
		Renderer();
		~Renderer();

		void setLoop(LoopFunc* loop);
		void RenderTexture(Texture*);
	private:
		SDL_Rect mainViewport = { 0,0,0,0 };
	};
};
