//
//			HWK3(5).cpp
//
//	By: Barak Barclay
//	Date: 23 Sept 2015
//
//	Problem Statement:Money and float math. Prompt the user to enter in the cost of an item.
//	Assume the sales tax is 6%. Calculate the total amount due. Work this problem using floats 
//	for the math operations. Work it again using integers, convert by multiplying dollar/cent amount 
//	by 100 – i.e $33.33 * 100 = 3333 (an int). Final step is to convert back to float and divide by 100.
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variables
//		while loop	(true)
//			prompt user to enter the cost of an item
//			read in f
//			ftot = 1.06 * f;
//			set f2 = f * 10000;
//			set i = f2 + f2 * 6 / 100;
//			set itot = i / 10000;
//			print ftot
//			print itot
//		end while
//	end main
//
#include<stdio.h>
int main()
{
	while (true)
	{
		float f = 0;
		float f2 = 0;
		float ftot = 0;
		int i = 0;
		float itot = 0;
		printf_s("Enter the cost of an item:");
		scanf_s("%f", &f);
		ftot = 1.06 * f;
		f2 = f * 10000;
		i = f2 + f2 * 6 / 100;
		itot = (float) i / 10000;
		printf("%f\n", ftot);
		printf("%f\n", itot);
	}
	return 0;
}