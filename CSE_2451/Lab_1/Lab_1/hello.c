#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char * argv[]) {
  srand( time(NULL));

  int r = rand()%500-500;
  printf("Hello World %d %x\n", r, r);
  return 0;
}