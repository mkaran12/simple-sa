#include <stdio.h>

int sumup_numbers(int k, int j) {
    return k + j;
}

int main(void) {
    int numb1 = 10;
    int numb2 = 20;
    int total = sumup_numbers(numb1, numb2);
    
    printf("The sum of %d and %d is: %d\n", numb1, numb2, total);
    
    return 0;
}
