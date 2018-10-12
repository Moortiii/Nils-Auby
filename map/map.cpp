//
// Created by morten on 12.10.18.
//

#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "map.h"
#include "../texture_manager/texture_manager.h"

bool Map::parseMap() {

    Json::Value root;
    Json::Reader reader;

    std::ifstream file("data/map.json");
    bool parseSuccessful = reader.parse(file, root);

    if(!parseSuccessful) {
        std::cout << "Unable to parse map correctly." << std::endl;
        return false;
    }

    mapWidth = root["width"].asInt();
    mapHeight = root["height"].asInt();
    tilewidth = root["tilewidth"].asInt();
    tileheight = root["tileheight"].asInt();
    std::string tilesetPath = "data/" + root["tilesets"][0u]["image"].asString();

    tileset = TextureManager::loadTexture(tilesetPath.c_str(), _renderer);

    // TODO: Give each tile it's correct texture area so that it can be easily rendered
    // In order to do this we have to find out how to get the correct texture area
    // when we have the tileID from the tile-set
    for(size_t i = 0; i < root["layers"][0u]["data"].size(); i++) {
        tiles.emplace_back(new Tile((int)i % mapWidth, (int)i / mapHeight, tilewidth, tileheight));
    }

    return true;
}

Map::Map(SDL_Renderer *renderer) {
    _renderer = renderer;
}
