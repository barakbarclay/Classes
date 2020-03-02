//
//			HWK2(2).cpp
//
//	By: Barak Barclay
//	Date: 15 Sept 2015
//
//	Problem Statement: Nested looping structures. Write a program that prompts the user to enter in a symbol. Read in the symbol. Next prompt the user to enter an integer for the size of a square box to print. Read in the integer. Use the symbol and size to print a square (filled-in) to the screen using a looping structure. The inner looping structure should only use a single printf() statement.
//
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
//	start main
//		init variables
//		prompt user to enter symbol
//		read in symbol
//		prompt user to enter box size
//		read in size
//		while loop
//			count1++
//			print to next line
//			set count2 = 0
//			while loop
//				count2++
//				print symbol
//			end while
//		end while
//	end main
//
#include <stdio.h>
int main(void)
{
	char symbol = 0;

	int size = 0;
	int count1 = 1;
	int count2 = 1;

	printf("Enter a symbol:");
	scanf_s("%c", &symbol);
	printf("\n\nEnter an integer for the size of a square box to print:");
	scanf_s("%d", &size);
	printf("\n\n");

	while (count1 <= size)
	{
		count1++;
		printf("\n");
		count2 = 0;
		while (count2 < size)
			{
			count2++;
			printf("%c", symbol);
			}
	}

	printf("\n\n");
	return 0;
}
