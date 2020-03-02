//
//			HWK4(1).cpp
//
//	By: Barak Barclay
//	Date: 23 Sept 2015
//
//	Problem Statement: Write a program that prompts the user to enter an 
//	integer number one-to-five (numbers represent the first five elements
//	in the periodic table) or enter a negative number to quit. Read in the
//	integer. Error check to see if the number is with-in bounds 
//	(one-to-five) – if out of bounds print an error message and start over 
//	again, else print out the name of the element. If the user enters a 
//	valid integer, using if-else statements print out the name of the entered
//	element. Loop until the user enters a negative number.
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variable
//		while loop	(num >= 0)
//			prompt user to enter integer
//			read in num
//			if statements
//		end while
//	end main
//
#include <stdio.h>

int main(void)
{
	int num = 0;
	while (num >= 0)
	{
		printf_s("\nEnter a integer between 1 and 5.\n");
		scanf_s("%d", &num);

		if (num == 0 || num > 5)
		{
			printf_s("Value entered is out of bounds.");
		}
		if (num == 1)
		{
			printf_s("Hydrogen");
		}
		if (num == 2)
		{
			printf_s("Helium");
		}
		if (num == 3)
		{
			printf_s("Lithium");
		}
		if (num == 4)
		{
			printf_s("Beryllium");
		}
		if (num == 5)
		{
			printf_s("Boron");
		}
	}
}