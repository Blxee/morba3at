#ifndef VISUAL_H
#define VISUAL_H

#include <stdlib.h>
#include <ncurses.h>
#include "logic.h"

typedef struct game_s {
  grid *grid;
} game_t;

game_t *create_game(void);
void step_game(game_t *game, int input);
void print_game(game_t *game);
void destroy_game(game_t *game);

#endif // VISUAL_H
