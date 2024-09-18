#ifndef MAZE_H
#define MAZE_H

#include "macros.h"

// Function to initialize the maze
void initialize_maze(void);

// Function to render the maze
void render_maze(void);

// Function to check for wall collisions
int is_wall(float x, float y);

#endif // MAZE_H

