//
//			forLoopProgram.cpp
//
//	By: Barak Barclay
//	Date: 21 Sept 2015
//
//	Problem Statement: Write a program using a for loop. Write a program that
//	reads in 5 integer numbers, sums the numbers and prints the average.
//
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variables
//		while loop	-	auumen will enter 5 quiz scores
//			prompt user to enter quiz score
//			read in score
//			add to sum
//		end while
//		caculate average
//		print average to monitor
//	end main
//
#include <stdio.h>

int main(void)
{
	int num = 0;
	int total = 0;
	int i;

	for (i = 1; i <= 5; i++)
	{
		puts("\nEnter in an integer. \n");
		scanf_s("%i", &num);

		if (num > 0)
		{
			total += num;
		}
		else
		{
			i--;
			puts("\nDon't enter a negative number. \n");
		}

	}	//end while

	printf_s("\nThe ineger average is %d \n\n", total / (i - 1));
	printf_s("\nThe ineger average is %d \n\n", total % (i - 1));

	return 0;
}//main
