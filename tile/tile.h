//
// Created by morten on 12.10.18.
//

#ifndef NILSAUBY_TILE_H
#define NILSAUBY_TILE_H


#include <SDL2/SDL_system.h>

class Tile {
private:
    int x;
    int y;
    int width;
    int height;
    SDL_Texture* texture;
public:
    Tile(int x, int y, int width, int height);
};


#endif //NILSAUBY_TILE_H
