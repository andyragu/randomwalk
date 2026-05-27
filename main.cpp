#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include "walker.h"

void drawWalker(SDL_Renderer* renderer, walker& w) {
    w.nextStep();

    SDL_SetRenderDrawColor(renderer, w.r, w.g, w.b, w.a);
    SDL_FRect rect = {
        w.nextX,
        w.nextY,
        2.0f,
        2.0f
    };

    SDL_RenderLine(renderer, w.prevX, w.prevY, rect.x, rect.y);

    w.prevX = w.nextX;
    w.prevY = w.nextY;
}

int main(int argc, char* argv[]) {
    bool done = false;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("randomwalk", 1920, 1280, SDL_WINDOW_RESIZABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);

    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "Couldn't create window: %s\n", SDL_GetError());
        return 1;
    }

    std::vector<walker> walkers;

    for (int i = 0; i < 10; i++) {
        walkers.emplace_back(renderer);
    }

    while (!done) {
        SDL_Event event;


        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
        }

        for (walker& w : walkers) {
            drawWalker(renderer, w);
        }

        // And now we present everything we draw after the clear.
        SDL_RenderPresent(renderer);
        SDL_Delay(1);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();
    return 0;
}
