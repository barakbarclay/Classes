//
//		PointersWithArrays
//
#include <stdio.h>

int *pointerArray(int *Fun_startPtr, int *Fun_endPtr, int Fun_search4);

void main(void)
{
	int intArray[10] = { 0 };
	int *startPtr = &intArray[0];
	int *endPtr = &intArray[9];

	int search4 = 10;	//startPtr + 10

	size_t k;

	for (k = 0; k < 10; k++)
	{
		intArray[k] = 10 * k;
		printf("%3d located at %p\n", intArray[k], &intArray[k]);
	}

	printf("\n\n%p\n\n", pointerArray(startPtr, endPtr, search4));

	puts("\n");

}//end main
int *pointerArray(int *Fun_startPtr, int *Fun_endPtr, int Fun_search4)
{

	while (Fun_startPtr <= Fun_endPtr)
	{
		printf("\nThe value is %d", *Fun_startPtr);
		if (Fun_search4 == *Fun_startPtr)
		{
			return Fun_startPtr;
		}
		Fun_startPtr++;
	}
	return NULL;
}//end uf