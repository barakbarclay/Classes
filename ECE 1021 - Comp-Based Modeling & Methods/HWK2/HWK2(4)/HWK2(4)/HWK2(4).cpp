//
//			HWK2(4).cpp
//
//	By: Barak Barclay
//	Date: 15 Sept 2015
//
//	Problem Statement: Write a program that prompts the user to enter in a char data type called Grade from the set { ‘A’, ‘B’, ‘C’, ‘D’, ‘F’ }. Write a message to the monitor, which states you expect to get an  (insert entered char) in this class. Assume the user will enter a valid Grade.
//
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
//	start main
//		init variables
//		prompt user to enter a grade from the set { A, B, C, D, F }:
//		read in grade
//		print you expect to get an (insert enter char) in this class
//	end main
//
#include <stdio.h>
int main(void)
{
	char grade = 0;

	printf("Enter in a grade from the set { A, B, C, D, F }:");
	scanf_s("%c", &grade);
	printf("You expect to get an %c in this class", grade);

	printf("\n\n");
	return 0;
}