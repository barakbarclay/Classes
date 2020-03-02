//
//			HWK3(4).cpp
//
//	By: Barak Barclay
//	Date: 23 Sept 2015
//
//	Problem Statement:Write a program which prompts the user to enter in a float number. Read in the number.
//	Convert the float to an integer number. If the number is odd, print it and the next 9 odd numbers to 
//	the screen. If the number is even, print the next 9 even numbers to the screen
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variables
//		while loop	(true)
//			prompt user to enter a float number
//			read in f
//			set i = f
//			if (i & 1)
//				print next 9 odd numbers
//			end if
//			else
//				print next 9 even numbers
//			end else
//		end while
//	end main
//
#include<stdio.h>
int main()
{
	while (true)
	{
		float f = 0;
		int i = 0;
		printf_s("Enter a float number:");
		scanf_s("%f", &f);
		i = f;
		if (i & 1)
			printf("%d, %d, %d, %d, %d, %d, %d, %d, %d\n", i + 2, i + 4, i + 6, i + 8, i + 10, i + 12, i + 14, i + 16, i + 18);
		else
			printf("%d, %d, %d, %d, %d, %d, %d, %d, %d\n", i + 2, i + 4, i + 6, i + 8, i + 10, i + 12, i + 14, i + 16, i + 18);
	}
	return 0;
}