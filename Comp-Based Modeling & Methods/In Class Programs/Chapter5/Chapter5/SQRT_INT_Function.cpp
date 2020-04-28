//
//				SQRT_INT_Function.cpp
//
//	By: Barak Barclay
//	Date: 7 Oct 2015
//
//	Problem Statement: N/A
//
//			%%%%	Algorthim	%%%%
//
// preprocessor directives
// function definition statement
// start main
//		init variable
//		prompt user to enter an integer, or neg. number to quit
//		read integer
//		sentinel loop
//			call function
//			prompt user to enter an integer, or neg. number to quit
//			read integer
//		end loop
//	end main
//
//
//			1111	User Function Algorithm	1111
//
//	init variables
//	calculate root
//	print reselt to screen
//	end user funciton
//
//
#include <stdio.h>
#include <math.h>

#pragma warning(disable :4996)

void intRootFunction(int  Fun_num);

void main(void)
{
	int num = 0;
	while (num >= 0)
	{
		printf_s("%s", "\nEnter a positve integer, or enter a negative number to quit:");
		scanf_s("%d", &num);
		intRootFunction(num);
	}
}//end main

void intRootFunction(int Fun_num)
{
	double root = 0.0;
	root = sqrt((double)Fun_num);
	printf_s("\nFun_num is:%d", Fun_num);
	printf_s("\nSquare root is:%lf", root);
}//end user function intRootFunction