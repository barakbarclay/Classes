//
//			bubbleSort.cpp
//
//By: Camille Blanton
//Date: 04 Nov 2015
//
//Problem Statement: You work at a company with 100 employees (1 to 100).
//	The company has three different arrays used to calculate an employee's pay.
//	One array for base pay, and two arrays for extra/bonus pay. The company
//	wishes to determine if any employee(s) are getting double pay - i.e. their
//	employee number occurs more than once in an array. So you can not determine
//	the pay of your co-workers, the company provides you with three arrays of
//	employee numbers. Your job is to write a C program, using functions to 
//	search each array for duplication entries - use a linear search function.
//	Do not output any message for those employees not found in an array, only
//	those found in more than one....
//
//	Output a matrix of those employee numbers each time it is found as a
//	duplicate.
//
//			Pay array		Bonus array		Incentive array
//			   ###				###				  ###
//
//	((We're going to bubble sort and find out which ones are in the arrays more 
//	than once, instead of doing it where we pick a number and check each number 
//	individually.))


#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define Fill1 90
#define Fill2 80
#define Fill3 70

void RandFill(int randarray[], size_t size, int fillcode);
void PrintCheck(int randarray[], size_t size); // prints out all the values in the array to check for any problems at each stage
void LinearSort(int randarray[], size_t size);
void FindDups(int ranarray[], size_t size, int duparray[], size_t size1);
void PrintOut(int randarray[], size_t size1, int duparray[], size_t size2,int duparray3[], size_t size3); 


int main(void)
{
	int Pay[SIZE] = { 0 };
	int DupPay[SIZE] = { 0 };
	int Bonus[SIZE] = { 0 };
	int DupBonus[SIZE] = { 0 };
	int Incentive[SIZE] = { 0 };
	int DupIncentive[SIZE] = { 0 };


	RandFill(Pay, SIZE, Fill1);
	PrintCheck(Pay, SIZE);

	RandFill(Bonus, SIZE, Fill2);
	PrintCheck(Bonus, SIZE);

	RandFill(Incentive, SIZE, Fill3);
	PrintCheck(Incentive, SIZE);

	LinearSort(Pay, SIZE);
	PrintCheck(Pay, SIZE);

	LinearSort(Bonus, SIZE);
	PrintCheck(Bonus, SIZE);

	LinearSort(Incentive, SIZE);
	PrintCheck(Incentive, SIZE);



	return 0;

}

void RandFill(int randarray[], size_t size, int fillcode)
{
	size_t j;

	for (j = 0; j < size; j++)
	{
		randarray[j] = (rand() % fillcode) + 1;
	} // end for loop 

} // end Random Fill

void PrintCheck(int randarray[], size_t size)
{
	size_t k;

	for (k = 0; k < size; k++)
	{
		if ((k % 15) == 0)
		{
			puts(" ");
		}

		printf("%4d", randarray[k]);
	} // end for loop

	puts("\n\n");

} // end Print Check 

void LinearSort(int randarray[], size_t size)
{
	int count = 1;
	int pass;
	int hold;
	int i;

	for (pass = 1; (unsigned) pass < size; pass++) // we explicitly typecast 'pass' so that the 
									//program isn't comparing an unsigned with a signed integer
	{
		for (i = 0; i < (size - count); i++)
		{
			if (randarray[i] > randarray[i + 1]) // does the comparison from smallest to largest, 
										//therefore making the largest numbers go to the bottom
			{
				hold = randarray[i];
				randarray[i] = randarray[i + 1];
				randarray[i + 1] = hold;
			} // end if

		} // end inner for loop

		count += 1; // we do a count so that you dont recompare the larger 
			//numbers on the bottom, again, even though they're already in the correct order 

	} // end outer for loop

} //end Linear Sort/Bubble Sort