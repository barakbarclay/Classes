//
//			HWK4(7).cpp
//
//	By: Barak Barclay
//	Date: 30 Sept 2015
//
//	Problem Statement: Write a program to produce the output below using
//	looping structures. Zero points for not using looping structures. 
//	Each new line of  ‘#’  is indented one extra space. Line one of the 
//	#’s starts at column 10. 
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variable
//		for 5 times
//			for 9 times
//			print values 1-9
//			end for
//			print 0
//		end for
//		for 10 times
//			while
//			print spaces
//			end while
//			print ##########
//		end for
//		for 5 times
//			for 9 times
//			print values 1-9
//			end for
//			print 0
//		end for
//	end main
//

#include <stdio.h>
#include <math.h>

#include<stdio.h>

int main(void)
{
	int line;
	int line1 = 1;
	int repeat;
	int spaces = 0;

	char Header[] = "##########";
	for (repeat = 1; repeat <= 5; ++repeat)
	{
		for (line = 1; line <= 9; ++line)
		{
			printf_s("%d", line);
		}
		printf_s("0");
	}
	printf_s("\n\n");
	for (line = 1; line <= 10; ++line)
	{
		line1 = line;
		while (spaces < line1)
		{
			line1--;
			printf_s(" ");
		}
		printf_s("%20s\n", Header);
	}
	printf_s("\n");
	for (repeat = 1; repeat <= 5; ++repeat)
	{
		for (line = 1; line <= 9; ++line)
		{
			printf_s("%d", line);
		}
		printf_s("0");
	}
	printf_s("\n\n");
	return 0;
}