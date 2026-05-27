//
// Created by andya on 5/25/2026.
//

#include "walker.h"
#include <cstdlib>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

walker::walker(SDL_Renderer* renderer) {
    SDL_Rect currViewport;
    SDL_GetRenderViewport(renderer, &currViewport);

    prevX = (currViewport.w / 2) + currViewport.x;
    prevY = (currViewport.h / 2) + currViewport.y;
}

void walker::nextStep() {
    nextX = prevX;
    nextY = prevY;

    int randDirection = rand() % 4;

    if (randDirection == 0) {
        nextX -= 1; // left
    }
    else if (randDirection == 1) {
        nextY += 1; // down
    }
    else if (randDirection == 2) {
        nextY -= 1; // up
    }
    else if (randDirection == 3) {
        nextX += 1; // right
    }
}
