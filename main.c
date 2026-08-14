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
  while (pressed_key != 'q')
  {
    pressed_key = getch();
    step_game(game, pressed_key);
  }
  endwin();
}
