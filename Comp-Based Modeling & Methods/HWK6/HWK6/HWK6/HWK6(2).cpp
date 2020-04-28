#include <stdio.h>
#pragma warning(disable : 4996)
bool uf(int Fun_n);
void main(void)
{
	int n = 0;
	printf("Enter an integer number:");
	scanf("%d", &n);
	printf("\n");
	uf(n);
}
bool uf(int Fun_n)
{
	int n2 = 0;
	printf("Enter an integer number:");
	scanf("%d", &n2);
	printf("\n");
	while (Fun_n%n2 != 0)
	{
		printf("Enter an integer number:");
		scanf("%d", &n2);
		printf("\n");
	}
	printf("%d is a divisor of %d\n", n2, Fun_n);
	return true; 
}