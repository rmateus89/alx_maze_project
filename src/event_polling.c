#include "../headers/maze.h"

/**
 * poll_events - Handles SDL events such as keyboard and mouse inputs.
 * @sdl: Pointer to the SDL instance structure.
 * @player: Pointer to the player structure.
 * Return: 1 if the user requests to quit, 0 otherwise.
 */
int poll_events(sdl_instance *sdl, player *player)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            return (1);
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
                return (1);
            if (event.key.keysym.sym == SDLK_w)
                player->walk_direction = 1;
            if (event.key.keysym.sym == SDLK_s)
                player->walk_direction = -1;
            if (event.key.keysym.sym == SDLK_a)
                player->turn_direction = -1;
            if (event.key.keysym.sym == SDLK_d)
                player->turn_direction = 1;
        }
        if (event.type == SDL_KEYUP)
        {
            if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_s)
                player->walk_direction = 0;
            if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_d)
                player->turn_direction = 0;
        }
    }
    return (0);
}

