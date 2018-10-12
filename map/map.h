#ifndef NILSAUBY_MAP_H
#define NILSAUBY_MAP_H

#include <SDL2/SDL_system.h>
#include "../tile/tile.h"
#include <list>

class Map {
public:
    explicit Map(SDL_Renderer* renderer);
    bool parseMap();
private:
    int mapWidth;
    int mapHeight;
    int tilewidth;
    int tileheight;
    SDL_Texture* tileset;
    SDL_Renderer* _renderer;
    std::list<Tile*> tiles;
};


#endif //NILSAUBY_MAP_H
