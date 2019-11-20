#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int nums[10];
  int randfile = open("/dev/random", O_RDONLY);
  read(randfile, nums, 10 * sizeof(int));
  close(randfile);

  printf("___________________\nNUMBERS GENERATED:\n");
  int i;
  for (i = 0; i < 10; i++) {
    printf("\t%d\n", nums[i]);
  }

  int testfile = open("./testfile", O_CREAT | O_RDWR);
  write(testfile, nums, 10 * sizeof(int));
  lseek(testfile, 0, SEEK_SET);

  int nums_copy[10];
  read(testfile, nums_copy, 10 * sizeof(int));
  close(testfile);

  printf("___________________\nNUMBERS READ:\n");
  for (i = 0; i < 10; i++) {
    printf("\t%d\n", nums[i]);
  }

  return 0;
}
