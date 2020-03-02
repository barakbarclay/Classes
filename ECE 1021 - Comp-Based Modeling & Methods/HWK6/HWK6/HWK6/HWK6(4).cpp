#include <stdio.h>
#include <math.h>
#pragma warning(disable : 4996)
void uf(int Fun_n);
void main(void)
{
	int n = 0;
	printf("Enter a integer number corresponding to the size of a multiplication table:");
	scanf("%d", &n);
	printf("\n");
	uf(n);
}
void uf(int Fun_n)
{
	int i;
	int j;
	for (j = 1; j <= Fun_n; j++)
	{
		for (i = 1; i <= Fun_n; i++)
		{
			printf("%d\t", j*i);
		}
		printf("\n");
	}
}