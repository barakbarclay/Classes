#include <stdio.h>

void main(void)
{
	int a = 55;
	int *aPtr = &a;

	printf("\nThe value in a is %d. \n", a);
	printf("\nThe value in aPtr is %p. \n", aPtr); //note %p is used here
	printf("\nThe value pointed to is %d. \n", *aPtr);

}