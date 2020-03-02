//
//				arrayExample.cpp
//
//	By: Barak Barclay
//	Date: 19 Oct 2015
//
#include <stdio.h> //standard input/output library
//#include <stddef.h> <- array code is included in here if it isn't working with another compiler
#define arraysize 100

void main(void)
{
	int size = 9;
	int myArray[arraysize]; //must intialize and put intial value in curly braces

		size_t i;

		//for (i = 0; i < arraysize; i++)
		//{
		//	printf_s("Array element %u is -> %d \n", i, myArray[i]);
		//}
		for (i = 0; i < arraysize; i++)
		{
			size++;
			myArray[i] = size;
			//myArray[i] = 10;
		}
		for (i = 0; i < arraysize; i++)
		{
			printf_s("Array element %-2u is -> %d \n", i, myArray[i]);
		}
}//end main