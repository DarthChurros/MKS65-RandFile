#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "randgen.h"

int main() {
  int nums[10];
  rand_ary(nums, 10);

  int testfile = open("./testfile", O_RDWR);

  close(testfile);
  return 0;
}

void rand_ary(int* nums, int size) {
  int randfile = open("/dev/random", O_RDONLY);
  read(randfile, nums, sizeof(int)*size);
  close(randfile);
}
