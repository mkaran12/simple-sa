#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    char *commad = NULL, *commad_coppy = NULL, *token = NULL;
    char *delimiter = "\n";
    size_t nomb = 0;
    int argc = 0, i = 0;
    char **argv = NULL;

    printf("$");
    if (getline(&commad, &nomb, stdin) == -1) {
        free(commad);  // Free memory before exiting on error
        return -1;
    }

    commad_coppy = strdup(commad);

    token = strtok(commad, delimiter);
    while (token) {
        token = strtok(NULL, delimiter);
        argc++;
    }

    printf("%d\n", argc);

    argv = malloc(sizeof(char *) * argc);
    token = strtok(commad_coppy, delimiter);

    i = 0;
    while (token) {
        argv[i] = token;
        token = strtok(NULL, delimiter);
        i++;
    }

    argv[i] = NULL;

    i = 0;
    while (argv[i]) {
        printf("%s\n", argv[i]);
        i++;
    }

    free(commad);
    free(commad_coppy);
    free(argv);

    return 0;
}
