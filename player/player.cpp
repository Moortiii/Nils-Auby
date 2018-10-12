//
// Created by morten on 12.10.18.
//

#include "player.h"
#include "../texture_manager/texture_manager.h"
#include "../config/config.h"

Player::Player(SDL_Renderer *renderer) {
    _renderer = renderer;
    texture = TextureManager::loadTexture("images/character_sprite.png", renderer);
    srcRect = { 40, 40, 40, 40};
    dstRect = { 0, 0, Config::WINDOW_WIDTH / 2, Config::WINDOW_HEIGHT / 2};
};

void Player::draw() {
    if (texture) {
        SDL_RenderCopy(_renderer, texture, nullptr, &dstRect);
    }
};
