//
//			HWK2(9).cpp
//
//	By: Barak Barclay
//	Date: 15 Sept 2015
//
//	Problem Statement: Write a program that uses looping to print the following table of values. Use the tab escape sequence, \t, in the printf statement to separate the columns with tabs. 
//
//	N       10*N    100*N   1000*N
//
//	1       10      100     1000 
//	2       20      200     2000 
//	3       30      300     3000 
//	4       40      400     4000 
//	5       50      500     5000 
//	6       60      600     6000 
//	7       70      700     7000 
//	8       80      800     8000 
//	9       90      900     9000 
//	10      100     1000    10000
//
//
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
//	start main
//		init variables
//		print N		10*N	100*N	100*N
//		while loop
//			set variables eqaul to count times respected value
//			print values
//			count++
//		end while
//	end main
//
#include <stdio.h>
int main(void)
{
	int number = 10;
	int count = 1;
	int N = 0;
	int tentimesN = 0;
	int hundredtimesN = 0;
	int thousandtimeN = 0;

	printf("N\t10*N\t100*N\t100*N\n\n");
	while (count <= number)
	{
		N = count;
		tentimesN = count * 10;
		hundredtimesN = count * 100;
		thousandtimeN = count * 1000;

		printf("%d\t%d\t%d\t%d\n", N, tentimesN, hundredtimesN, thousandtimeN);
		count++;
	}

	printf("\n");
	return 0;
}