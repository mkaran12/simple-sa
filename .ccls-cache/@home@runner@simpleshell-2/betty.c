#include <stdio.h>

/**
 * main - Entry point
 * Descripltion: Th program tests whie loop function
 * Return:  Always 0 (success)
 */

int main(void)
{
	int c = 10; /*local variable definition*/

	/*while loop execusion*/
	while (c < 20)
	{
		printf("value of c: %d\n", c);
		c++;
	}
	return (0);
}
