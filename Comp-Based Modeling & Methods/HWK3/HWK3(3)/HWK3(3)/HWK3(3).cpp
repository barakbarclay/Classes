//
//			HWK3(3).cpp
//
//	By: Barak Barclay
//	Date: 23 Sept 2015
//
//	Problem Statement:Using a while loop, write a program which prompts the user to enter in integer 
//  numbers (between 0 and 9 - inclusive) to average together. Error check each number entered, 
//  reject the number if it is not between 0 and 9 and write a message to the screen that the number 
//  entered was out of bounds. After the user enters in -99, error check to make sure the user entered 
//  in at least one valid number, if not - print an error message, else print the average value and the 
//  remainder value to the screen.  
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variable
//		while loop	(num != -99)
//			prompt user to enter a integer that's greater than or equal to 0, but less than or equal to 9
//			read in num
//			increment i 
//			if (num != -99 && (num <= 0 || num >= 9))
//				set num = 0
//				print the number entered was out of bounds
//				decrement i 
//			end if
//			else
//				add num to total
//			end else
//		end while
//		print average
//		print remainder
//	end main
//
#include <stdio.h>
int main(void)
{
	int num = 0;
	int total = 0;
	int i = 0;

	while (num != -99)
	{
		printf_s("Enter a integer that's greater than or equal to 0, but less than or equal to 9.\n");
		scanf_s("%d", &num);
		i++;
		if (num != -99 && (num <= 0 || num >= 9))
		{
			num = 0;
			printf_s("The number entered was out of bounds.\n");
			i--;
		}
		else
		{
			total += num;
		}
	}	//end while
	printf_s("The average is %d.\n", (total + 99) / (i - 1));
	printf_s("The remainder of the average is %d.\n", (total + 99) % (i - 1));
	return 0;
}//main