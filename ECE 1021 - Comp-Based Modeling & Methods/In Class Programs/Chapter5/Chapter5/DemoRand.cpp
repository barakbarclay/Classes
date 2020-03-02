//
//				DemoRand.cpp
//
//	By: Barak Barclay
//	Date: 7 Oct 2015
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable :4996)

void main(void)
{
	int randnum = 0;
	int i;

	srand( (unsigned) time(NULL) );

	for (i = 0; i < 10;  i++)
	{
		randnum = rand(); //random number from 0 to 32,767
		printf_s("\nMy random number is:%d",randnum);
		randnum = rand();
		printf_s("\nMy random number is:%d", randnum);
	}
	printf_s("%s", "\n");
}//end main