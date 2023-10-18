#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  size_t no =7;
  char *buf = malloc(sizeof(char) * no);

  printf("input name");
  ssize_t chars_read = getline(&buf, &no, stdin);

  if (chars_read != -1) {
      printf("Read %zd characters: %s", chars_read, buf);
  } else {
      perror("getline");
  }
  free(buf);
  return 0;
}