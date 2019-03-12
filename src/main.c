#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
#include <time.h>
#include "error.h"
#include "sort.h"

static long my_first(long nb) {
  while (nb > 1000) {
    nb /= 10;
  }
  return (nb);
}

static void start_chrono(t_chrono *chrono) {
  clock_gettime(CLOCK_REALTIME, &(chrono->start.spec));

   chrono->start.s  = chrono->start.spec.tv_sec;
   chrono->start.ms = round(chrono->start.spec.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds
   if (chrono->start.ms > 999) {
       chrono->start.s++;
       chrono->start.ms = (chrono->start.ms - 1000 < 0) ? 0 : chrono->start.ms - 1000;
   }

}

static void end_chrono(t_chrono *chrono) {
  intmax_t seconds;
  long ms;
  clock_gettime(CLOCK_REALTIME, &(chrono->end.spec));

  chrono->end.s  = chrono->end.spec.tv_sec;
  chrono->end.ms = round(chrono->end.spec.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds
  if (chrono->end.ms > 999) {
      chrono->end.s++;
      chrono->end.ms = (chrono->end.ms - 1000 < 0) ? 0 : chrono->end.ms - 1000;
  }
  seconds = (intmax_t)chrono->end.s - (intmax_t)chrono->start.s;
  ms = my_first((long)chrono->end.ms) - my_first((long)chrono->start.ms);
  while (ms < 0) {
    ms += 1000;
    seconds -= 1;
  }
  printf("Time spent : %"PRIdMAX".%03ld seconds\n", seconds, ms);
}

int main(int ac, char **av) {
  srand(time(NULL));
  int size;
  int max_elem;
  int *data;
  t_chrono chrono;

  if (ac <= 2) {
    printf("Usage : ./sort [size] [max_elem]\n");
    return (EXIT_SUCCESS);
  }
  if ((size = atoi(av[1])) <= 0 || (max_elem = atoi(av[2])) <= 0)
    return (error(INVALID_INPUT));
  if ((data = malloc((size + 1) * sizeof(int))) == NULL)
    return (error(NULL_MALLOC));
  start_chrono(&chrono);
  init_data(data, size, max_elem);
  init(data, size, max_elem);
  end_chrono(&chrono);
  free(data);
  return (EXIT_SUCCESS);
}
