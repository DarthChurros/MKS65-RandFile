#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "randgen.h"

void rand_ary(int* nums, int size) {
  int randfile = open("/dev/random", O_RDONLY);
  read(randfile, nums, sizeof(int)*size);
  close(randfile);
}

int write_ary(int fd, int* nums, int size) {
  return 0;
}

int read_ary(int fd, int* nums, int size) {
  return 0;
}
