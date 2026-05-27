//
// Created by andya on 5/25/2026.
//

#ifndef RANDOMWALK_WALKER_H
#define RANDOMWALK_WALKER_H
#include <cstdint>
#include <cstdlib>
#include <SDL3/SDL_render.h>


class walker {
    public:
        float prevX;
        float prevY;
        float nextX;
        float nextY;
        walker(SDL_Renderer* renderer);
        void nextStep();
        uint8_t r = rand() % 255;
        uint8_t g = rand() % 255;
        uint8_t b = rand() % 255;
        uint8_t a = 0xFF;
};



#endif //RANDOMWALK_WALKER_H
