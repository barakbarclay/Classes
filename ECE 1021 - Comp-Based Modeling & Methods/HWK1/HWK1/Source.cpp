#include <stdio.h>

int main(void)
{
	printf("I am learning the C programming language.\n\n""I am using Microsoft Visual Studio.\n\n""I will become a great C programmer.\n\n");

	float y1 = 1.10 * 100;

	printf("y = 1.10 * 100 = %f\n\n", y1);

	int y2 = 3 / 5 + 51 / 3 * 2 - 5;

	printf("y = 3 / 5 + 51 / 3 * 2 - 5 = %d\n\n", y2);

	printf("     *****\n     *   *\n     *   *\n     *   *\n     *****\n\n");

	bool boolean = 1;

	char character = 'A';

	printf("%d, %c, %f, %d \n\n", boolean, character, y1, y2);
}