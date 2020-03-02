//
//			HWK2(7).cpp
//
//	By: Barak Barclay
//	Date: 15 Sept 2015
//
//	Problem Statement: Write a program to evaluate the equations below. Find the answer by hand first, check by running the program.
//	Given:   int x1 = 0;
//	int x2 = 2;
//	int x3 = -7;
//	int x4 = 11;
//	int x5 = 3;
//	int x6 = -8;
//	int ans1 = 0;
//	int ans2;
//
//	ans1 = x1 * (x2 * x4) + x6 * x5 – x3 * x5 + (x3 + x6);
//
//	ans2 = x1 + (x2 - x4) + x6 / x5 + x3 / x5 + (x6 + x3);
//
//
//
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
//	start main
//		init variables
//		do first equation
//		print answer to first equation
//		do second equation
//		print answer to second equation
//	end main
//
#include <stdio.h>
int main(void)
{
	int x1 = 0;
	int x2 = 2;
	int x3 = -7;
	int x4 = 11;
	int x5 = 3;
	int x6 = -8;
	int ans1 = 0;
	int ans2;

	ans1 = x1 * (x2 * x4) + x6 * x5 - x3 * x5 + (x3 + x6);
	printf("ans1 = %d", ans1);
	ans2 = x1 + (x2 - x4) + x6 / x5 + x3 / x5 + (x6 + x3);
	printf("\n\nans2 = %d", ans2);

	printf("\n\n");
	return 0;
}