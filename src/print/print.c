#include <stdio.h>

void print_array(int *sorted, int size) {
  int i;

  i = 0;
  while (i < size) {
    printf("%d : %d\n", i, sorted[i]);
    i++;
  }
}
