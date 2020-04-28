//
//			HWK2(8).cpp
//
//	By: Barak Barclay
//	Date: 15 Sept 2015
//
//	Problem Statement: Write a program to print out all the even numbers from 0 to 30 using a looping structure. Print the numbers across the screen (horizontally) with 2 spaces separating each number.
//
//
//
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
//	start main
//		init variables
//		while loop
//			print count and 2 spaces
//			count++
//			count++
//		end while
//	end main
//
#include <stdio.h>
int main(void)
{
	int number = 30;
	int count = 0;

	while (count <= number)
	{
		printf("%d  ", count);
		count++;
		count++;
	}

	printf("\n\n");
	return 0;
}