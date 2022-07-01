#include "Texture.h"
#include "pch.h"
#include <SDL/SDL_image.h>

using namespace Keyhan;

Texture::Texture(SDL_Renderer* renderer) {
	this->sdl_texture = nullptr;
	this->width = 0;
	this->height = 0;
	this->renderer = renderer;
}

Texture::~Texture() {
	this->Free();
}

void Texture::LoadFromFile(std::string path, bool colorKey) {
	this->Free();

	SDL_Surface* sur = IMG_Load(path.c_str());
	if (sur == nullptr) {
		throw std::exception("Failed to load images " + *SDL_GetError());
	}

	if (colorKey) {
		SDL_SetColorKey(sur, SDL_TRUE, SDL_MapRGB(sur->format, 0, 0, 0xFF));
	}

	this->sdl_texture = SDL_CreateTextureFromSurface(this->renderer, sur);

	if (this->sdl_texture == nullptr) {
		throw std::exception("Failed to load texture " + *SDL_GetError());
	}

	this->width = sur->w;
	this->height = sur->h;

	SDL_FreeSurface(sur);
}

void Texture::Free() {
	if (sdl_texture != nullptr) {
		SDL_DestroyTexture(sdl_texture);
		sdl_texture = nullptr;
		width = 0;
		height = 0;
	}
}

unsigned int Texture::GetHeight() {
	return this->height;
}

unsigned int Texture::GetWidth() {
	return this->width
}