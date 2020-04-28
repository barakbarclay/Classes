//
//		Prog1.cpp
//
//	By: Barak
//	Date: 31 Aug 2015
//
//
//	Problem Statement: Write a program that adds two numbers
//
//
//		<<<<<	Algorithm	>>>>>
//
//		psuedocode algorithm here
//
//
#include <stdio.h>

#pragma warning(disable : 4996)

int main(void)
{
	int integer1 = 0;
	int integer2 = 0;
	int sum = 0;

	char letter = 'A';

	printf("Enter first integer number:");
	scanf("%d", &integer1);		// & is the address operator 

	printf("\nEnter second integer number:");
	scanf("%d", &integer2);		// & is the address operator 

	sum = integer1 + integer2;

	printf("\nThe sum of %d + %d = %d.  \n\n", integer1, integer2, sum);

	printf("%s", "This is a preferred method for printing strings with printf command \n\n");

	letter = getchar();		//supposed to keep the program open when it starts with debugging, but it doesn't

	return 0;
}