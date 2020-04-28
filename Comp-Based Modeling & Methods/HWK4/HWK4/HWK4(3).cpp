//
//			HWK4(3).cpp
//
//	By: Barak Barclay
//	Date: 23 Sept 2015
//
//	Problem Statement: Write a program that prompts the user to enter 
//	in an integer number. Read in the integer number. Using a for loop, 
//	calculate the sum of all the integers from zero to the entered number 
//	(including the entered number). Print the result to the screen.  
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variable
//		prompt user tot enter integer
//		read in num
//		for loop
//			calculate sum
//		end for
//		print sum
//	end main
//

#include <stdio.h>

int main(void)
{
	int num = 0;
	int i = 0;
	int sum = 0;

	printf_s("Enter a integer\n");
	scanf_s("%d", &num);

	for (i = 0; i < num; i++)
	{
		sum = sum + (num - i);
	}	//end while
	printf_s("%d\n", sum);
	return 0;
}//main