#include "../headers/maze.h"

/**
 * render - Renders the entire game scene.
 * @sdl: Pointer to the SDL instance structure.
 * @player: Pointer to the player structure.
 */
void render(sdl_instance *sdl, player *player)
{
    SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255);
    SDL_RenderClear(sdl->renderer);

    render_walls(sdl);
    render_player(sdl, player);

    SDL_RenderPresent(sdl->renderer);
}

