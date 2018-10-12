cmake_minimum_required(VERSION 3.12)
project(nilsauby)

set(CMAKE_CXX_STANDARD 14)

add_executable(nilsauby main.cpp game.cpp game.h config/config.cpp config/config.h clock/clock.cpp clock/clock.h texture_manager/texture_manager.cpp texture_manager/texture_manager.h player/player.cpp player/player.h tile/tile.cpp tile/tile.h map/map.cpp map/map.h)

target_link_libraries(nilsauby SDL2 SDL2_image jsoncpp)