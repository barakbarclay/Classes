//
//				randomWalk.cpp
//
//	By: Barak Barclay
//	Date: 12 Oct 2015
//
// Problem Statement: Using rand() function, write a program for a 
// random walk. Use a switch statement to keep tack and print the direction 
// choosen. Attach end o fthe program print out total number of steps
// taken in each direction.
//
//
//			####	Algorithm	####
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable :4996)

void main(void)
{
	unsigned int count_N = 0; //unsigned int uses sign bits for the magnitude
	unsigned int count_S = 0;
	unsigned int count_E = 0;
	unsigned int count_W = 0;
	unsigned int steps;
	unsigned int count;

	int direction = -1;
	
	puts("\nEnter in the number of steps for your random walk.\n");
	scanf_s("%u", &steps); // %u is the conversion specifier for an unsigned int
	puts("\n");

	srand((unsigned)time(NULL));

	for (count = 0; count < steps; count ++)
	{
		direction = rand() %4; // give random number 0 to 3 

		switch (direction)
		{
		case 0:
		{
			//printf_s("N", direction);
			count_N += 1;
			break;
		}
		case 1:
		{
			//printf_s("S", direction);
			count_S += 1;
			break;
		}
		case 2:
		{
			//printf_s("E", direction);
			count_E += 1;
			break;
		}
		case 3:
		{
			//printf_s("W", direction);
			count_W += 1;
			break;
		}
		default:
		{
			puts("\n\n		ERROR - Direction out of bounds - ERROR");
			count_N += 1;
			break;
		}
		}//end switch
	}//end for
	printf_s("%s", "\n");
	printf_s("\n North step count -> %u \n", count_N);
	printf_s("\n South step count -> %u \n", count_S);
	printf_s("\n East step count  -> %u \n", count_E);
	printf_s("\n West step count  -> %u \n\n", count_W);
}//end main