#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <exception>
#include "UUIDGen.h"
#include <Windows.h>

#define PATH_TO_PLACEHOLDER "assets/test/placeholder.png"

const int width = 960, height = 540;

SDL_Window* gwindow = nullptr;
SDL_Renderer* grenderer = nullptr;
SDL_Texture* gtexture = nullptr;

SDL_Texture* loadTexture(std::string path) {
	SDL_Texture* newTexture = nullptr;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == nullptr) {
		throw std::exception("Failed to load image " + *SDL_GetError());
	}

	newTexture = SDL_CreateTextureFromSurface(grenderer, loadedSurface);

	if (newTexture == nullptr) {
		throw std::exception("Failed to create texture " + *SDL_GetError());
	}

	SDL_FreeSurface(loadedSurface);

	return newTexture;
}

void init() {
	if (SDL_Init(SDL_INIT_VIDEO < 0)) {
		throw std::exception("Failed to Initialize SDL Video " + *SDL_GetError());
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		OutputDebugStringA("Couldn't enable Linear Texture Filtering");
	}

	gwindow = SDL_CreateWindow("SDL TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (gwindow == nullptr) {
		throw std::exception("Failed to Create a Window!: " + *SDL_GetError());
	}

	grenderer = SDL_CreateRenderer(gwindow, -1, SDL_RENDERER_ACCELERATED);

	if (grenderer == nullptr) {
		throw std::exception("Failed to create renderer!: " + *SDL_GetError());
	}

	SDL_SetRenderDrawColor(grenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	int imgFlags = IMG_INIT_PNG;

	if (!(IMG_Init(imgFlags) & imgFlags)) {
		throw std::exception("SDL_Image Failed to Initialize " + *IMG_GetError());
	}
}

void loadMedia() {
	gtexture = loadTexture(PATH_TO_PLACEHOLDER);

	if (gtexture == nullptr) {
		throw std::exception("Failed to load texture Image: " + *SDL_GetError());
	}
}

void close() {
	SDL_DestroyTexture(gtexture);
	gtexture = nullptr;

	SDL_DestroyRenderer(grenderer);
	SDL_DestroyWindow(gwindow);
	gwindow = nullptr;
	grenderer = nullptr;

	IMG_Quit();
	SDL_Quit();
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd)
{
	try {
		init();
		loadMedia();
	}
	catch (std::exception& e) {

		close();
		OutputDebugStringA(e.what() + '\n');
		MessageBox(nullptr, e.what(), "Fatal Error", MB_ICONERROR | MB_OK | MB_TASKMODAL);
		return -1;

	}

	SDL_Event e;
	bool w = false;

	Keyhan::ID id;
	id.GenerateID("helllo");
	OutputDebugStringA(id.GetStringID().c_str());

	while (!w) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				w = true;
			}
		}
		SDL_RenderClear(grenderer);
		SDL_RenderCopy(grenderer, gtexture, nullptr, nullptr);
		SDL_RenderPresent(grenderer);
	}
	close();
	
	return 0;
}