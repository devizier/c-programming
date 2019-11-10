#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main() {
  if (maxSeq((int[]) {2, 0, 0, -2}, 4) != 1) {
    return EXIT_FAILURE;
  }

  if (maxSeq((int[]){1, -2, 1, -3, 0, 1, 1}, 7) != 3) {
    return EXIT_FAILURE;
  }

 
  if (maxSeq((int[]){}, 0) != 0) {
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}
