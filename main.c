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
  cbreak();
  curs_set(0);
  noecho();
  keypad(stdscr, TRUE);
  pressed_key = '\0';
  while (pressed_key != 'q')
  {
    clear();
    step_game(game, pressed_key);
    print_game(game, stdscr);
    refresh();
    pressed_key = getch();
  }
  endwin();
  destroy_game(game);
  return (0);
}
