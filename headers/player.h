#ifndef PLAYER_H
#define PLAYER_H

#include "macros.h"

// Player structure
typedef struct {
    float x;
    float y;
    float width;
    float height;
    int turn_direction; // -1 for left, +1 for right
    int walk_direction; // -1 for back, +1 for forward
    float rotation_angle;
    float move_speed;
    float rotation_speed;
} Player;

// Function to initialize the player
void initialize_player(void);

// Function to update the player's position
void update_player(void);

// Function to render the player
void render_player(void);

#endif // PLAYER_H

