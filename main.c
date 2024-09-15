#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define TEX_WIDTH 64
#define TEX_HEIGHT 64

int worldMap[MAP_WIDTH][MAP_HEIGHT] = {
    // (same map as before)
};

void draw(SDL_Renderer *renderer, int x, int y, int w, int h, Uint32 color) {
    SDL_Rect rect = {x, y, w, h};
    SDL_SetRenderDrawColor(renderer, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void raycast(SDL_Renderer *renderer, double posX, double posY, double dirX, double dirY, double planeX, double planeY) {
    // (same raycasting code as before)
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("3D Maze Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Could not create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    double posX = 22, posY = 12;
    double dirX = -1, dirY = 0;
    double planeX = 0, planeY = 0.66;

    int running = 1;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = 0;
                }
                if (event.key.keysym.sym == SDLK_UP) {
                    if (worldMap[(int)(posX + dirX * 0.1)][(int)posY] == 0) posX += dirX * 0.1;
                    if (worldMap[(int)posX][(int)(posY + dirY * 0.1)] == 0) posY += dirY * 0.1;
                }
                if (event.key.keysym.sym == SDLK_DOWN) {
                    if (worldMap[(int)(posX - dirX * 0.1)][(int)posY] == 0) posX -= dirX * 0.1;
                    if (worldMap[(int)posX][(int)(posY - dirY * 0.1)] == 0) posY -= dirY * 0.1;
                }
                if (event.key.keysym.sym == SDLK_LEFT) {
                    double oldDirX = dirX;
                    dirX = dirX * cos(0.1) - dirY * sin(0.1);
                    dirY = oldDirX * sin(0.1) + dirY * cos(0.1);
                    double oldPlaneX = planeX;
                    planeX = planeX * cos(0.1) - planeY * sin(0.1);
                    planeY = oldPlaneX * sin(0.1) + planeY * cos(0.1);
                }
                if (event.key.keysym.sym == SDLK_RIGHT) {
                    double oldDirX = dirX;
                    dirX = dirX * cos(-0.1) - dirY * sin(-0.1);
                    dirY = oldDirX * sin(-0.1) + dirY * cos(-0.1);
                    double oldPlaneX = planeX;
                    planeX = planeX * cos(-0.1) - planeY * sin(-0.1);
                    planeY = oldPlaneX * sin(-0.1) + planeY * cos(-0.1);
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        raycast(renderer, posX, posY, dirX, dirY, planeX, planeY);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

