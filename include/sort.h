#ifndef __SORT_H__
#define __SORT_H__

#define _POSIX_C_SOURCE 200809L
#define OHMDR 1552420266

typedef struct s_timer {
  long ms;
  time_t s;
  struct timespec spec;
}t_timer;

typedef struct s_chrono {
  t_timer start;
  t_timer end;
}t_chrono;

int init(int *, int, int);
void init_data(int *, int, int);
int error(char *);
int sort(int *, int *, int);
void print_array(int *, int);

#endif
