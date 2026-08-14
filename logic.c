#include "logic.h"
#include <stdlib.h>

grid *create_grid(int width, int hight)
{
  grid *l3ba;
  int i;
  if(width <= 0 || hight <= 0)
    return (NULL);

  l3ba = malloc(sizeof(grid));
  if(!l3ba)
    return (NULL);
  
  l3ba->array = malloc(sizeof(l3ba->array));
  if(!l3ba->array)
    return (NULL);

  i = 0;
  while(i < width * hight)
  {
    l3ba->array[i] = '*';
    i++;
  }

  
  return (l3ba);
}

void distroy_grid(grid *distroy)
{
  if(!distroy)
  return;
  
   free(distroy->array);
  
   free(distroy);
}
