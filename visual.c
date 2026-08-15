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
  if (game->grid != NULL)
    distroy_grid(game->grid);
  free(game);
}


static void _print_title(WINDOW *stdscr, int max_x, int max_y, int width, int height)
{
(void)stdscr;
(void)max_x;
(void)max_y;
(void)width;
(void)height;
  
}

static void _print_frame(WINDOW *stdscr, int max_x, int max_y, int width, int height)
{
  int x;
  int y;
  
  y = -1;
  while (y < height + 1)
  {
    move(max_y / 2 - height / 2 + y, max_x / 2 - width - 2);
    if (y == -1 || y == height)
      addch('+');
    else
      addch('|');
    x = 0;
    while (x < width * 2 && (y == -1 || y == height))
    {
      addch('-');
      x++;
    }
    move(max_y / 2 - height / 2 + y, max_x / 2 + width - 2);
    if (y == -1 || y == height)
      addch('+');
    else
      addch('|');
    y++;
  }
}

void print_game(game_t *game, WINDOW *stdscr)
{
  int max_x;
  int max_y;
  int x;
  int y;
  char cell;

  getmaxyx(stdscr, max_y, max_x);
  _print_frame(stdscr, max_x, max_y, game->grid->width, game->grid->hight);
  _print_title(stdscr, max_x, max_y, game->grid->width, game->grid->hight);
  y = 0;
  while (y < game->grid->hight)
  {
    x = 0;
    move(max_y / 2 - game->grid->hight / 2 + y, max_x / 2 - game->grid->width - 1);
    while (x < game->grid->width) {
      cell = game->grid->array[y * game->grid->width + x];
      addch(cell);
      if (x < game->grid->width - 1)
        addch(' ');
      x++;
    }
    y++;
  }
}

