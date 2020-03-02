//
//			arrayAddressing.cpp
//
//By: Camille Blanton
//Date: 28 Oct 2015
//
//Problem Statement: Write a program to show how array addressing works.
//
//
//		<<<Algorithm>>>
//
//	preprocessor directive
//	init/define global constants
//	main
//		init local variables
//		print array values and addresses
//	end main
//

#include <stdio.h>

#define SIZE 5

int main(void)
{
	int myArray[SIZE] = { 10. 20. 30 , 40 , 50 };

	printf("\nThe value of the array element zero is %c. \n", myArray[0]);	
	printf("The array starting address is %p or this %p. \n\n\n", myArray, &myArray[0]);

	printf("The array address for the second element is %p. \n\n\n", &myArray[1]);

	printf("The array address for the third element is %p. \n\n", &myArray[2]);

	return 0;
} // end main