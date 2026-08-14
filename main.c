#include "logic.h"
#include "visual.h"
#include <ncurses.h>
#include <unistd.h>

int main(void)
{
  game_t *game;
  int pressed_key;

  game = create_game();
  if (game == NULL)
    return (1);
  initscr();
  raw();
  noecho();
  pressed_key = '\0';
  while (pressed_key != 'q')
  {
    step_game(game, pressed_key);
    print_game(game, stdscr);
    refresh();
    pressed_key = getch();
  }
  endwin();
  return (0);
}
