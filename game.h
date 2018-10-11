//
// Created by morten on 11.10.18.
//

#ifndef NILSAUBY_GAME_H
#define NILSAUBY_GAME_H

#include <string>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>
#include "clock/clock.h"

class Game {
public:

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    SDL_Rect fillRect;
    bool running;
public:
    Game(char* title, int xPos, int yPos, int width, int height, Uint32 flags);

    void update(float deltaTime);
    void render();
    void handleEvents();
    void clean();

    bool isRunning() const;
};


#endif //NILSAUBY_GAME_H
