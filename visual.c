#include "visual.h"
#include "logic.h"
#include <malloc.h>
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
  (void)game;
  (void)input;
}

void destroy_game(game_t *game)
{
  if (game == NULL)
    return ;
  // if (game->grid != NULL)
  //   destroy_grid(game->grid);
  free(game);
}


void print_game(game_t *game, WINDOW *stdscr)
{
  int max_x;
  int max_y;
  int x;
  int y;
  char cell;

  getmaxyx(stdscr, max_y, max_x);
  (void)cell;
  (void)max_x;
  (void)max_y;
  y = 0;
  while (y < game->grid->hight)
  {
    x = 0;
    while (x < game->grid->width) {
      cell = game->grid->array[y * game->grid->width + x];
      addstr(".");
      x++;
    }
    addstr("\n");
    y++;
  }
}

