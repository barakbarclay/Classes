//			FormattedOutput.cpp
//
//	By: Barak Barclay
//	Date: 28 Sept 2015
//
//	Problem Statement: Excersise 3.25
//
//			%%%%	Algorthim	%%%%
//
#include<stdio.h>

int main(void)
{
	int A = 0;
	int line;

	char Header[] = " A \tA+2 \tA+4 \tA+6";
	printf_s("%s\n\n", Header);

	for (line = 1; line <= 5; ++line)
	{
		A += 3;
		printf_s(" %-2d %-5d %-5d %-5d \n", A, A + 2, A + 4, A + 6); //negative is left justify. numer is the allotted amount of space for the value
	}
	
}