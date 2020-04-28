//
//			passPinter2Function.cpp
//
//	By: Barak Barclay
//	Date: 23 Nov 2015
//
//	Problem Statement: Write an example program passing a pointer to a user function.
//	
//
//			%%%%	Algorthim	%%%%
//
//	
//
#include <stdio.h>
#include <math.h>

int SqaurePlusOne(int *aPtr);

int main(void)
{
	int a = 3;
	int *aPtr = &a;
	//int*bPtr = NULL;
	int b = 0;

	printf("\n\nThe hex stored in aPtr is %p.\n\n", aPtr);

	printf("\n\nThe value in \"a\" before function call is %d.\n", *aPtr);

	//bPtr = SqaurePlusOne(aPtr);

	b = SqaurePlusOne(aPtr); //could put &a as well

	printf("\n\nThe value in \"a\" after function call is %d.\n", *aPtr);

	//printf("\n\nThe hex address stored in aPtr after function call is %p.\n\n", bPtr);

	printf("\n\nThe value of b after function call is %d.\n\n", b);
}//end main

int SqaurePlusOne(int *aPtr)
{
	int temp = -1;

	temp = *aPtr;

	*aPtr = pow((float)temp, 2) + 1;

	printf("\n\nThe value in \"a\" after function call is %d.\n", *aPtr);
	
	//aPtr = aPtr + 1;

	//printf("\n\nThe hex adress stored in aPtr after function call is %p.\n\n", aPtr);

	//return aPtr;
	return *aPtr;
}