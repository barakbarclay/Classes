//
//			HWK3(2).cpp
//
//	By: Barak Barclay
//	Date: 23 Sept 2015
//
//	Problem Statement:Write a program which prompts the user to enter in two double numbers and one
//	integer number. Read in the numbers. Calculate the sum and product of the three numbers and 
//	print the results to the screen.  Use explicit type casting.
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variables
//		prompt user to enter double number
//		read in d1
//		prompt user to enter double number
//		read in d2
//		prompt user to enter integer number
//		read in num
//		do sum and product of the 3 numbers
//		print sum and product
//	end main
//
#include <stdio.h>

int main(void)
{
	double d1 = 0;
	double d2 = 0;
	int num = 0;
	double sum = 0;
	double product = 0; 

	printf_s("Enter a double number:");
	scanf_s("%lf", &d1);
	printf_s("Enter another double number:");
	scanf_s("%lf", &d2);
	printf_s("Enter an integer number:");
	scanf_s("%d", &num);
	sum = (double) (d1 + d2 + num);
	product =(double) (d1 * d2 * num);
	printf_s("%lf\n", sum);
	printf_s("%lf\n", product);
	return 0;
}