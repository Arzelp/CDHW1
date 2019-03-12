#include "error.h"
#include <stdio.h>
#include <stdlib.h>

int error(char *err) {
  printf("%s", err);
  return (EXIT_FAILURE);
}
