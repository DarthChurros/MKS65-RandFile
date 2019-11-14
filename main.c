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
