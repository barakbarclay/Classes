//
//			HWK4(5).cpp
//
//	By: Barak Barclay
//	Date: 23 Sept 2015
//
//	Problem Statement:  Use the math library. Write a program to calculate
//	the sin function from 0 to pi, in increments of pi/20.    
//	y = sin(i*pi / 20)         where i is an integer 0 to 20, and y is a float.
//	print out the 21 values to the screen.
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variable
//		for
//			y = sin(i*pi / 20)
//			print y
//		end for
//	end main
//

#include <stdio.h>
#include <math.h>

int main(void)
{
	int i = 0;
	double y = 0;

	for (i = 0; i <= 20; i++)
	{
		y = (double)sin((double)i*3.141592 / 20.0);
		printf("%lf\n", y);
	}	//end while
	return 0;
}//main