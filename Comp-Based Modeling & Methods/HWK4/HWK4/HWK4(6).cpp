//
//			HWK4(6).cpp
//
//	By: Barak Barclay
//	Date: 30 Sept 2015
//
//	Problem Statement:Rewrite problem 5, but this time you will graph 
//	the result. After you calculate the result y, multiple it by 15, 
//	type cast the float to an int and print out that many  ‘*’  to the 
//	screen. Go to the next line and repeat with the next result for y. 
//	Repeat for all 21 values. You should see a graph of the sine function, 
//	down the page, showing the positive sine shape. 
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variable
//		for
//			y = sin(i*pi / 20)
//			y = y * 15.0;
//			for loop
//			print *
//			end for
//			print new line
//		end for
//	end main
//

#include <stdio.h>
#include <math.h>

int main(void)
{
	int i = 0;
	int i1 = 0;
	double y = 0;
	int y1 = 0;

	for (i = 0; i <= 20; i++)
	{
		y = (double)sin((double)i*3.141592 / 20.0);
		y1 = y * 15.0;
		for (i1 = 0; i1 <= y1; i1++)
		{
			printf_s("*");
		}
		printf_s("\n");
	}	//end while
	return 0;
}//main