#include "../headers/maze.h"

/**
 * main - Entry point of the maze game.
 * Return: 0 on success, 1 on failure.
 */
int main(void)
{
    sdl_instance sdl;
    player player;

    if (init_sdl(&sdl) != 0)
        return (1);

    initialize_player(&player);

    while (1)
    {
        if (poll_events(&sdl, &player))
            break;
        update_player(&player);
        render(&sdl, &player);
    }

    cleanup_sdl(&sdl);
    return (0);
}

