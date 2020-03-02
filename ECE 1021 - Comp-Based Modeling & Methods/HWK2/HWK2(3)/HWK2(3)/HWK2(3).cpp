//
//			HWK2(3).cpp
//
//	By: Barak Barclay
//	Date: 15 Sept 2015
//
//	Problem Statement: Write a program that prompts the user to enter in a double number, read in the double number. Square the entered number and print the result to the monitor.
//
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
//	start main
//		init variables
//		prompt user to enter double number
//		read in number
//		square number in squared varible
//		print squared
//	end main
//
#include <stdio.h>
int main(void)
{
	double number = 0;
	double squared = 0;

	printf("Enter a double number:");
	scanf_s("%lf", &number);
	squared = number * number;
	printf("\n%lf", squared);

	printf("\n\n");
	return 0;
}
