//
// Created by morten on 12.10.18.
//

#ifndef NILSAUBY_TEXTURE_MANAGER_H
#define NILSAUBY_TEXTURE_MANAGER_H


#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class TextureManager {
public:
    static SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer);
};


#endif //NILSAUBY_TEXTURE_MANAGER_H
