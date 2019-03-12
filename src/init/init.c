#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "error.h"
#include "sort.h"

void init_data(int *data, int size, int M) {
  int i;

  i = 0;
  while (i < size) {
    data[i] = rand() % (M + 1);
    i++;
  }
}

static void init_positions(int *elem_count, int *positions, int M) {
  int i;

  i = 1;
  positions[0] = elem_count[0];
  while (i <= M) {
    positions[i] = elem_count[i] + positions[i - 1];
    i++;
  }
  printf("%d\n", positions[M]);
}

static int count_elem(int *data, int *elem_count, int size, int M) {
  int i;

  i = 0;
  while (i < size) {
    if (data[i] > M) {
      return (error(INVALID_MAX_ELEM));
    }
    elem_count[data[i]] += 1;
    i++;
  }
  return (EXIT_SUCCESS);
}

int init(int *data, int size, int M) {
  int *ele_count;
  int *positions;

  if (size <= 0 || M <= 0)
    return (error(INVALID_INPUT));
  if ((ele_count = malloc((M + 1) * sizeof(int))) == NULL ||
      (positions = malloc((M + 1) * sizeof(int))) == NULL)
    return (error(NULL_MALLOC));
  if (memset(ele_count, 0, (M + 1) * sizeof(int)) == NULL)
    return (error(NULL_MEMSET));
  if (count_elem(data, ele_count, size, M) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  init_positions(ele_count, positions, M);
  return (sort(data, positions, size));
}
