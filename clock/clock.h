//
// Created by morten on 11.10.18.
//

#ifndef NILSAUBY_CLOCK_H
#define NILSAUBY_CLOCK_H


#include <SDL2/SDL_timer.h>

class Clock {
private:
    Uint32 currentTime;
    Uint32 previousTime;
    float deltaTime;
public:
    Clock() :currentTime(SDL_GetTicks()), deltaTime(0), previousTime(0) { }

    void tick() {
        previousTime = currentTime;
        currentTime = SDL_GetTicks();
        deltaTime = (float)(currentTime - previousTime) / 100;
    }

    float getDeltaTime() {
        if(deltaTime > 0.25f)
            deltaTime = 0.25f;

        return deltaTime;
    }
};


#endif //NILSAUBY_CLOCK_H
