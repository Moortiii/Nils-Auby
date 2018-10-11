//
// Created by morten on 11.10.18.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"
#include "config/config.h"

Game::Game(char* title, int xPos, int yPos, int width, int height, Uint32 flags) {
    running = true;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cout << "Initialization of SDL unsuccessful!" << std::endl;

    window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

    if(!window)
        std::cout << "Failed to create window." << std::endl;

    // Using vertical sync prevents the frame-rate from spiraling out of control
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    if(!renderer)
        std::cout << "Failed to create renderer." << std::endl;

    fillRect = { 0, 0, 25, 25 };
}

void Game::update(float deltaTime) {
    fillRect.x += 1;
}

void Game::render() {
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);

    // Prepare a red rectangle for rendering
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
    SDL_RenderFillRect(renderer, &fillRect);
    SDL_RenderDrawRect(renderer, &fillRect);

    // Render the screen
    SDL_RenderPresent(renderer);
}

bool Game::isRunning() const {
    return running;
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

void Game::handleEvents() {
    if(SDL_PollEvent(&event) == 0) {
        if(event.type == SDL_QUIT) {
            std::cout << "User has chosen to exit the program. Terminating." << std::endl;
            running = false;
        }
    }
}
