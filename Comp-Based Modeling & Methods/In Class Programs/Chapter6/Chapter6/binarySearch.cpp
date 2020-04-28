//
//			binarySearch.cpp
//
//	By: Barak Barclay
//	Date: 11 Nov 2015
//
//	Problem Statement: Write a program to demostrate binary search. Create an array of 101 elements (0 to 100). 
//	Set each element wqual to its index number. (i.e. array[5] = 5). Prompt user to enter a value to earch for, 
//	or type a negative number to quit. Call a user function to do the binary search.
//
//		#####	Algorithm	####
//
//	preprocessor directives
//	 function prototypes
//	init global constants
//	main
//		init local variables
//		call function to set array values to index nuber
//		prompt user to enter number to search for
//		read in value
//		while (sentinel) loop
//			call binary searh function
//			prompt user for new value to search for
//			readin in new search value
//		end while
//		printout element/index number
//	end main
//
//
//		11111	UF1		1111
//	init local variables
//	for loop
//		array[i] = i;
//	enf for
//	end uf1
//
//		2222	UF2		2222
//	init local variables
//	while loop
//		find middle index number
//		print out lower, middle, upper index numbers
//		test if middle calue is match - yes return
//		less than - new middle value
//		greater than - new middle value
//	 end while
//	fif no match return -1
//	end uf2
//
//		3333	UF3		3333
//	init local variables
//	for loop
//		print out array elemtn
//	end for 
//	end uf3
//
//		4444	UF4		4444
//	init local variables
//	printi out answer
//	end uf3
//
//
#include <stdio.h>

#define SIZE 101

void setArrayValues(int binSearchArray[], size_t Fun_size);
void printOutArray(int binSearchArray[], size_t Fun_size);
int binarySearch(int binSearchArray[], size_t Fun_size, int Look4Value);
void printAnswer(int Answer, int ValueToFind);

void main(void)
{
	int MyArray[SIZE] = { 0 };
	int Search4 = -1;
	int Answer = -1;

	setArrayValues(MyArray, SIZE);

	printOutArray(MyArray, SIZE);

	puts("\nEneter in a value to search for (0 to 100), -1 to quit. \n");
	scanf_s("%d", &Search4);

	while (Search4 != -1)
	{
		Answer = binarySearch(MyArray, SIZE, Search4);

		printAnswer(Answer, Search4);

		puts("\nEneter in a value to search for (0 to 100), -1 to quit. \n");
		scanf_s("%d", &Search4);
	} //end sentinel loop
}	//end main

void setArrayValues(int binSearchArray[], size_t Fun_size)
{
	size_t i;
	for(i = 0; i < Fun_size; i++)
	{
		binSearchArray[i] = (int)100+i;
	}//end for loop
}//end uf

void printOutArray(int binSearchArray[], size_t Fun_size)
{
	size_t i;
	for (i = 0; i < Fun_size; i++)
	{
		printf("%5d", binSearchArray[i]);
	}//end for loop
	puts("\n\n");
}//end uf

int binarySearch(int binSearchArray[], size_t Fun_size, int Look4Value)
{
	int middle = -1;//middle value will change to be in between high and low
	int low = 0;
	int high = (Fun_size - 1);

	while (low <= high)
	{
		middle = (low + high) / 2;

		printf("\n Low = %d,   middle = %d   high = %d \n", low, middle, high);

		if (Look4Value == binSearchArray[middle])
		{
			return middle;
		}

		if (Look4Value < binSearchArray[middle])
		{
			high = middle - 1;	//look in lower half of array
		}
		else
		{
			low = middle + 1;	//look in upper half of array
		}
	}

	return -1;

}//end uf

void printAnswer(int Answer, int ValueToFind)
{
	printf("\nThe value in array element %d matches the searched for value %d. \n\n", Answer, ValueToFind);
}//end uf