#include <stdio.h>
#pragma warning(disable : 4996)
void main(void)
{
	int n = 0;
	char a = 'a';
	int i;
	int j;
	printf("Enter a character:");
	scanf("%c", &a);
	printf("\n", a);
	printf("Enter an integer:");
	scanf("%d", &n);
	printf("\n", a);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%c", a);
		}
		printf("\n");
	}
}