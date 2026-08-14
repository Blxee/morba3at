#ifndef LOGIC_H
#define LOGIC_H

typedef struct{

  char *array;
  int width;
  int hight;

} grid;

void distroy_grid(grid *distroy);
grid *create_grid(int width, int hight);

#endif // !LOGIC_H




