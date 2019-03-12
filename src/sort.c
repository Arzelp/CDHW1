#include <stdlib.h>
#include "error.h"
#include "sort.h"

int sort(int *data, int *positions, int size) {
  int *sorted_array;
  int i;

  if ((sorted_array = malloc((size + 1) * sizeof(int))) == NULL)
    return (error(NULL_MALLOC));
  i = 0;
  while (i < size) {
    sorted_array[positions[data[i]] - 1] = data[i];
    positions[data[i]] -= 1;
    i++;
  }
//  print_array(sorted_array, size);
  return (EXIT_SUCCESS);
}
