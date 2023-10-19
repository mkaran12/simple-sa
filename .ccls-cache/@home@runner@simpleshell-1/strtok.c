#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char string_origi[] = "i am a software engineer";
  char *str_cooppy = malloc(sizeof(char) * (strlen(string_origi) + 1));  

  if (str_cooppy == NULL) {
    perror("Memory allocation failed");
    return EXIT_FAILURE;
  }

  strcpy(str_cooppy, string_origi);  

  char *delimiter = " ";
  char *token = strtok(str_cooppy, delimiter);

  while (token != NULL)
  {
    printf("%s\n", token);
    token = strtok(NULL, delimiter);
  }

  free(str_cooppy);

  return 0;
}
