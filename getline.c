<<<<<<< HEAD
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    size_t nob = 20;
    char *buffr = (char *)malloc(sizeof(char) * nob);

    if (buffr == NULL) {
        perror("malloc");
        return 1;
    }

    printf("Input name: ");

    if (fgets(buffr, nob, stdin) != NULL) {
        buffr[strcspn(buffr, "\n")] = '\0';
        printf("Read: %s\n", buffr);
    } else {
        perror("fgets");
    }

    free(buffr);
    return 0;
}

=======
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
>>>>>>> b1e4e7bd475bb8c51c9bece7081c82a269432cc9
