//
// Created by morten on 12.10.18.
//

#include "texture_manager.h"

SDL_Texture *TextureManager::loadTexture(const char *filename, SDL_Renderer *renderer) {
    SDL_Surface* surface = nullptr;
    surface = IMG_Load(filename);

    if(!surface) {
        std::cout << "Unable to load texture image. Returning nullptr" << std::endl;
    }

    SDL_Texture* texture = nullptr;
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    if(!texture) {
        std::cout << "Unable to create texture from surface. Returning nullptr" << std::endl;
    }

    SDL_free(surface);
    return texture;
}
