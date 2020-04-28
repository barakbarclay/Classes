//
//			userFunction.cpp
//
//	By: Barak Barclay
//	Date: 28 Sept 2015
//
//	Problem Statement: Write a program to claculate Area, Circumference and Diameter of circle
//
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variables
//		while loop	-	auumen will enter 5 quiz scores
//			prompt user to enter quiz score
//			read in score
//			add to sum
//		end while
//		caculate average
//		print average to monitor
//	end main
//
//			1111	Algorithm User Function 1	1111
//
//
//			2222	Algorithm User Function 2	2222
//
//
//			3333	Algorithm User Function 3	3333
#include <stdio.h>
#include <math.h>

double circle_diameter(double Fun_radius);
double circle_circumference(double Fun_radius);
void circle_area(double Fun_radius); //needs a semi-colon
const double pi = 3.14159265;

int main(void)
{
	double radius = 0.0;

	puts("Enter the radius of a circle (one or two digits).");
	scanf_s("%lf", &radius);
	if (radius >= 0)
	{
		printf_s("\nThe diameter is : %10.2lf\n\n", circle_diameter(radius));
		printf_s("\nThe circumference is : %10.2lf\n", circle_circumference(radius));//prints a copy of what the user functions returns
		circle_area(radius); 
	}
	if (radius <0)
	{
		puts("\n\n	ERROR - no valid number entered. \n\n");
	}
	return 0;
}//main
double circle_diameter(double Fun_radius)
{
	return 2.0 * Fun_radius;
}
double circle_circumference(double Fun_radius)
{
	return 	 2.0 * pi * Fun_radius;
}
void circle_area(double Fun_radius) //if you have anything other than void defining the function, you need to have a return
{
	double area = 0.0;
	area = Fun_radius * Fun_radius * pi;
	printf_s("\nThe area is : %10.2lf\n", area);
}