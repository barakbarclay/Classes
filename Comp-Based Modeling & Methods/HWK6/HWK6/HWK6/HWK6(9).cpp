#include <stdio.h>
#define SIZE 20
#pragma warning(disable : 4996)
void main(void)
{
	int list[SIZE] = { 0 };
	int i;
	int j;
	int c = 0;
	int d;
	int n;


	printf("Enter 20 integers between 10 and 100:\n");
	for (i = 0; i < SIZE; i++)
	{
		d = 0;
		scanf("%d", &n);
		while (n < 10 || n > 100)
		{
			printf("\n\n	ERROR - Invalid Input	\n\n");
			scanf("%d", &n);
		}
		for (j = 0; j < c; j++)
		{
			if (n == list[j])
			{
				d = 1;
				break;
			}
		}
		if (!d)
		{
			list[c++] = n;
		}
	}
	printf("\nNon-duplcate integers:\n");
	for (i = 0; i < SIZE && list[i] != 0; i++)
	{
		printf("%d\t", list[i]);
	}
}