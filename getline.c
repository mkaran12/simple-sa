#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  size_t nob =20;
  char *buffr = malloc(sizeof(char) * nob);

  printf("input name");
  ssize_t charats_read = getline(&buffr, &nob, stdin);

  if (charats_read != -1) {
      printf("Read %zd characters: %s", charats_read, buffr);
  } else {
      perror("getline");
  }
  free(buffr);
  return 0;
}