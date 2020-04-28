//
//		PointersWithArrays
//
#include <stdio.h>

void circleMath(double Fun_radius, double *diameter, double *area);

void main(void)
{
	double radius = -1.0;
	double diameter = 0.0;
	double area = 0.0;

	puts("\nEnter a radius");
	scanf_s("%lf", &radius);

	circleMath(radius, &diameter, &area);

	printf("\nThe diameter is %lf \n", diameter);
	printf("\nThe area is %.8lf \n", area);
}
void circleMath(double Fun_radius, double *Fun_diameter, double *Fun_area)
{
	double MyPi = 3.14159265;
	*Fun_diameter = 2.0 *Fun_radius; //changes data value of address
	*Fun_area = MyPi * Fun_radius * Fun_radius; //changes data value of address
}