#include "../headers/maze.h"

/**
 * init_sdl - Initializes SDL and creates a window and renderer.
 * @sdl: Pointer to the SDL instance structure.
 * Return: 0 on success, 1 on failure.
 */
int init_sdl(sdl_instance *sdl)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return (1);
    }

    sdl->window = SDL_CreateWindow("Maze Game",
                                   SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT,
                                   0);
    if (!sdl->window)
    {
        printf("Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }

    sdl->renderer = SDL_CreateRenderer(sdl->window, -1, 0);
    if (!sdl->renderer)
    {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(sdl->window);
        SDL_Quit();
        return (1);
    }

    return (0);
}

/**
 * cleanup_sdl - Cleans up SDL resources.
 * @sdl: Pointer to the SDL instance structure.
 */
void cleanup_sdl(sdl_instance *sdl)
{
    SDL_DestroyRenderer(sdl->renderer);
    SDL_DestroyWindow(sdl->window);
    SDL_Quit();
}

