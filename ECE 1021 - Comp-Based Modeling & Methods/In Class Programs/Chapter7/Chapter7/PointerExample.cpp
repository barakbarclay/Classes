//
//			PointerExample.cpp
//
//	By
//
//	Problem Statement: Write an example program using poiters
#include <stdio.h>

int main(void)
{
	double a = 5.0;
	double b = 17.0;
	double *aPtr = &a;
	double *bPtr = &b;

	printf("\nThe address of a is %p.\n\n", &a);
	printf("\nThe address of a is %p.\n\n", aPtr);
	printf("\nThe address of a pointer (aPtr) is %p.\n\n", &aPtr);
	printf("\n\nThe value of a and the value in aPtr is %lf.\n\n", *aPtr);//	"*" is a indirection operator 
	printf("\n\nThe value of b and the value in bPtr is %lf.\n\n", *bPtr);
	printf("\n\na * b = %lf\n\n", (*aPtr) * (*bPtr));
	printf("\n\nThe address of aPtr + 1 = %p.\n\n", aPtr + 1);//adds 8 bytes because it's a double and changes 8 memory values

	printf("\n\n&*aPtr = %p.\n\n", &*aPtr); //&*aPtr and *&aPtr is the same thing (the address of a)
	printf("\n\n*&aPtr = %lf.\n\n", *&aPtr);

	return 0;
}//end main