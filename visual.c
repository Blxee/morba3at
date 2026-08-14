#include "visual.h"
#include "logic.h"
#include <ncurses.h>

game_t *create_game(void)
{
  game_t *game;
  
  game = malloc(sizeof(game_t));
  if (game == NULL)
    return (NULL);
  game->grid = create_grid(10, 20);
  if (game->grid == NULL)
    return (NULL);
  return (game);
}

void step_game(game_t *game, int input)
{
  (void)input;
  print_game(game);
}

void destroy_game(game_t *game)
{
  (void)game;
}


void print_game(game_t *game)
{
  int x;
  int y;
  char cell;

  y = 0;
  while (y < game->grid->hight)
  {
    x = 0;
    while (x < game->grid->width) {
      cell = game->grid->array[y * game->grid->width + x];
      addch(cell);
    }
    addch('\n');
  }
}

