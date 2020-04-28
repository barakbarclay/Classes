//
//			HWK3(1).cpp
//
//	By: Barak Barclay
//	Date: 23 Sept 2015
//
//	Problem Statement: Write a program which prompts the user to enter in an integer number between 48 
//  and 57 - inclusive. Read in the number. Using if statements, print out the ASCII code (decimal 
//  equivalent – Appendix B in book) for that number to the screen. The program should run until the 
//  user enters a negative number. 
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variable
//		while loop	(num >= 0)
//			prompt user to enter number
//			read in num
//			if (num ==48)
//				print 0 to screen
//			end if
//			copy and paste if statment changing 48 and 0 to correct numbers
//		end while
//	end main
//
#include <stdio.h>

int main(void)
{
	int num = 0;
	while (num >= 0)
	{
		printf_s("\nEnter a that's greater than or equal to 48, but less than or equal to 57.\n");
		scanf_s("%d", &num);

		if (num == 48)
		{
			printf_s("0");
		}
		if (num == 49)
		{
			printf_s("1");
		}
		if (num == 50)
		{
			printf_s("2");
		}
		if (num == 51)
		{
			printf_s("3");
		}
		if (num == 52)
		{
			printf_s("4");
		}
		if (num == 53)
		{
			printf_s("5");
		}
		if (num == 54)
		{
			printf_s("6");
		}
		if (num == 55)
		{
			printf_s("7");
		}
		if (num == 56)
		{
			printf_s("8");
		}
		if (num == 57)
		{
			printf_s("9");
		}
	}
}