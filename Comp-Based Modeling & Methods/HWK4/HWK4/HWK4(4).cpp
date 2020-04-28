//
//			HWK4(4).cpp
//
//	By: Barak Barclay
//	Date: 23 Sept 2015
//
//	Problem Statement: Use a do..while loop. Write a program that prompts 
//	the user to enter the radius of a circle – type double. Read in the radius. 
//	Next print a list of menu options for the user to choose from – see below. 
//	Read in the user option and preform the desired function. Repeat until the 
//	user enters a number to quit. Print an error message if the user enters an 
//	integer number outside the allowed values. Repeat until the user enters 
//	the Quit value.  
//	0 – Calculate the diameter of a circle.   
//	1 – Calculate the circumference of the circle.   
//	2 – Calculate the area of the circle.   
//	3 – Calculate the volume of a sphere.   
//	4 – Quit program.
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variable
//		prompt user tot enter radius
//		read in r
//		do while num != 4
//			prompt to enter one of options
//			read in num
//			if num == 4
//				break
//			end if
//		switch
//			cases
//		end switch
//		end do while
//	end main
//

#include <stdio.h>

int main(void)
{
	double r = 0;
	double d = 0;
	double c = 0;
	double a = 0;
	double v = 0;
	int num = 0;

	printf_s("Enter a radius of a circle\n");
	scanf_s("%lf", &r);
	do
	{
		printf_s("Enter 0 to calculate the diameter of a circle.\nEnter 1 to calculate the circumference of the circle.\nEnter 2 to calculate the area of the circle.\nEnter 3 to calculate the volume of a sphere.\nEnter 4 to quit program.\n");
		scanf_s("%d", &num);
		if (num == 4)
		{
			break;
		}
		switch (num)
		{
		case 0:
		{
				  d = 2.0 * r;
				  printf_s("%lf\n", d);
				  break;
		}	//end case
		case 1:
		{
				  c = 2.0 * 3.141592 * r;
				  printf_s("%lf\n", c);
				  break;
		}	//end case
		case 2:
		{
				  a = 3.141592 * r * r;
				  printf_s("%lf\n", a);
				  break;
		}	//end case
		case 3:
		{
				  v = (4.0 / 3.0) * 3.141592 *r * r * r;
				  printf_s("%lf\n", v);
				  break;
		}	//end case
		default:
		{
				   puts("\n\n	ERROR - no valid number entered. \n\n");
				   break;
		}	//end case

		}	//end switch
	} while (num != 4);

	
	return 0;
}//main