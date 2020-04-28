//
//			HWK2(5).cpp
//
//	By: Barak Barclay
//	Date: 15 Sept 2015
//
//	Problem Statement: Modify problem 4. Write a program using if statements. Write 5 if statements, one for each possible Grade entered. If true, the if statement will execute a puts statement that writes your letter grade to the monitor. Assume the user will enter a valid Grade.
//
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
//	start main
//		init variables
//		prompt user to enter a grade from the set { A, B, C, D, F }:
//		read in grade
//		if grade = A
//			puts You expect to get an A in this class
//		end if
//		if grade = B
//			puts You expect to get an B in this class
//		end if
//		if grade = C
//			puts You expect to get an C in this class
//		end if
//		if grade = D
//			puts You expect to get an D in this class
//		end if
//		if grade = F
//			puts You expect to get an F in this class
//		end if
//	end main
//
#include <stdio.h>
int main(void)
{
	char grade = 0;

	printf("Enter in a grade from the set { A, B, C, D, F }:");
	scanf_s("%c", &grade);

	if (grade == 'A')
	{
		puts("\nYou expect to get an A in this class");
	}
	if (grade == 'B')
	{
		puts("\nYou expect to get an B in this class");
	}
	if (grade == 'C')
	{
		puts("\nYou expect to get an C in this class");
	}
	if (grade == 'D')
	{
		puts("\nYou expect to get an D in this class");
	}
	if (grade == 'F')
	{
		puts("\nYou expect to get an F in this class");
	}


	printf("\n");
	return 0;
}