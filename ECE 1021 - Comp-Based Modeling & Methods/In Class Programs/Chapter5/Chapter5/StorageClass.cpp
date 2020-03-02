//
//				StorageClass.cpp
//
//
//
#include <stdio.h>

void PrintInt(int fun_PrintTimes);

int main(void)
{
	int printtimes = 0;

	puts("\nEnter in the number of times to print.\n");
	scanf_s("%d", &printtimes);

	PrintInt(printtimes);

	puts("\nEnter in the number of times to print.\n");
	scanf_s("%d", &printtimes);

	PrintInt(printtimes);

} //end main


void PrintInt(int fun_PrintTimes)
{
	int i;
	static int printf_lines = 0; // static variables are only intitalized at program creation

	for (i = 1; i <= fun_PrintTimes; i++)
	{
		printf("\nCount-up print times -> %d \n\n", i);
		printf_lines++;
	} // end for loop

	printf("\n       Total Lines Printed -> %d \n\n", printf_lines);

} //end user function