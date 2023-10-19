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

