#include <iostream>
#include "config/config.h"
#include "game.h"

#include <jsoncpp/json/json.h>
#include <fstream>

int main() {
    Game game((char*)"Nils-Auby", SDL_WINDOWPOS_CENTERED,
              SDL_WINDOWPOS_CENTERED, Config::WINDOW_WIDTH,
              Config::WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    Clock clock;

    while(game.isRunning()) {
        clock.tick();

        game.handleEvents();
        game.update(clock.getDeltaTime());
        game.render();
    }

    game.clean();

    return 0;

}