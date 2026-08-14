#include "visual.h"

void print_grid(grid grid)
{
  int x;
  int y;
  char cell;

  y = 0;
  while (y < grid.hight)
  {
    x = 0;
    while (x < grid.width) {
      cell = grid.array[y * grid.width + x];
      write(1, &cell, 1);
    }
    write(1, "\n", 1);
  }
}

