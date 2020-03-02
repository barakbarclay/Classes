//
//			HWK2(6).cpp
//
//	By: Barak Barclay
//	Date: 15 Sept 2015
//
//	Problem Statement: Modify problem 4. Write a program to evaluate the logical equations given below. Find the answer by hand first, check by running the program.
//		Given:  int x = 0;
//		int y = 33;
//		bool b = false;
//		bool c = true;
//		bool d = true;
//		bool e = -99;
//
//		y = x  &&  c  &&  !b  &&  d && (d || x) && e;
//
//		y = (!b && (!x || e)) && (b || e || y);
//
//
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
//	start main
//		init variables
//		do first equation
//		print answer to first equation
//		do second equation
//		print answer to second equation
//	end main
//
#include <stdio.h>
int main(void)
{
	int x = 0;
	int y = 33;
	bool b = false;
	bool c = true;
	bool d = true;
	bool e = -99;

	y = x  &&  c  &&  !b  &&  d && (d || x) && e;
	printf("y = %d", y);
	y = (!b && (!x || e)) && (b || e || y);
	printf("\n\ny = %d", y);


	printf("\n\n");
	return 0;
}