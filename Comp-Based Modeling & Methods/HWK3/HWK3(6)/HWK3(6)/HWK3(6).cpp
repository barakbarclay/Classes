//
//			HWK3(6).cpp
//
//	By: Barak Barclay
//	Date: 23 Sept 2015
//
//	Problem Statement: Work book problem 4.16 page 153. Do each problem using multiple puts 
//	or printf statements. Do them again using a single puts or printf statement inside a loop. 
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variables
//			for loops to create patterns
//	end main
//
#include<stdio.h>

int main(void)
{
	int i;
	int i1;
	int i2 = 10;

	for (i = 1; i <= 10; i++)
	{
		for (i1 = 1; i1 <= i; i1++)
		{
			printf_s("*");
		}
		printf_s("\n");
	}
	printf_s("\n");
	for (i = 1; i <= 10; i++)
	{
		for (i1 = i; i1 <= 10; i1++)
		{
			printf_s("*");
		}
		printf_s("\n");
	}
	printf_s("\n");
	i2 = 10;
	for (i = 1; i <= 10; i++)
	{
		for (i1 = 10 - i2; i1 >= 1; i1--)
		{
			printf_s(" ");
		}
		i2--;
		for (i1 = 10; i1 >= i; i1--)
		{
			printf_s("*");
		}
		printf_s("\n");
	}
	printf_s("\n");
	for (i = 1; i <= 10; i++)
	{
		for (i1 = 1; i1 <= (10 - i); i1++)
		{
			printf_s(" ");
		}
		for (i1 = 1; i1 <= i; i1++)
		{
			printf_s("*");
		}
		printf_s("\n");
	}
	printf_s("\n");
	return 0;
}