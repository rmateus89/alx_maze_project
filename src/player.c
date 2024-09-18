#include "../headers/player.h"

/**
 * initialize_player - Initializes the player structure with default values.
 */
void initialize_player(void)
{
    player.x = SCREEN_WIDTH / 2;
    player.y = SCREEN_HEIGHT / 2;
    player.width = 1;
    player.height = 1;
    player.turn_direction = 0;
    player.walk_direction = 0;
    player.rotation_angle = 0;
    player.move_speed = MOVE_SPEED;
    player.rotation_speed = ROTATE_SPEED;
}

/**
 * update_player - Updates the player's position based on input.
 */
void update_player(void)
{
    float move_step = player.walk_direction * player.move_speed;
    player.x += cos(player.rotation_angle) * move_step;
    player.y += sin(player.rotation_angle) * move_step;

    player.rotation_angle += player.turn_direction * player.rotation_speed;
}

/**
 * render_player - Renders the player on the screen.
 * @sdl: Pointer to the SDL instance structure.
 */
void render_player(sdl_instance *sdl)
{
    SDL_Rect player_rect = {
        (int)player.x,
        (int)player.y,
        player.width,
        player.height
    };
    SDL_SetRenderDrawColor(sdl->renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(sdl->renderer, &player_rect);
}

