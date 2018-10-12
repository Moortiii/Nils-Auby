//
// Created by morten on 12.10.18.
//

#ifndef NILSAUBY_PLAYER_H
#define NILSAUBY_PLAYER_H


#include <SDL2/SDL_system.h>

class Player {
private:
    SDL_Texture* texture;
    SDL_Renderer* _renderer;
    SDL_Rect srcRect;
    SDL_Rect dstRect;
public:
    explicit Player(SDL_Renderer* renderer);
    void draw();
};


#endif //NILSAUBY_PLAYER_H
