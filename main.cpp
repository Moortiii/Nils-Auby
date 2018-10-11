#include <iostream>
#include "config/config.h"
#include "game.h"

int main() {
    Game game((char*)"Nils-Auby", SDL_WINDOWPOS_CENTERED,
              SDL_WINDOWPOS_CENTERED, Config::WINDOW_WIDTH,
              Config::WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    Clock clock;

    while(game.isRunning()) {
        clock.tick();

        game.handleEvents();
        game.render();
        game.update(clock.getDeltaTime());
    }

    game.clean();

    return 0;

}