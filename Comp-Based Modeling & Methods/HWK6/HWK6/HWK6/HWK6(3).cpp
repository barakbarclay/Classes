#include <stdio.h>
#include <math.h>
#pragma warning(disable : 4996)
double uf1(float Fun_f1, float Fun_f2);
double uf2(float Fun_f1, float Fun_f2);
double uf3(float Fun_f1, float Fun_f2);
void main(void)
{
	float f1 = 0.0;
	float f2 = 0.0;
	printf("Enter a float number corresponding to a side of a rectangle:");
	scanf("%f", &f1);
	printf("\n");
	printf("Enter a float number corresponding to the other side of the rectangle:");
	scanf("%f", &f2);
	printf("\n");
	printf("Parameter is: %lf", uf1(f1, f2));
	printf("\n");
	printf("Diameter is: %lf", uf2(f1, f2));
	printf("\n");
	printf("Area is: %lf", uf3(f1, f2));
	printf("\n\n");
}
double uf1(float Fun_f1, float Fun_f2)
{
	double p = 0.0;
	p = 2 *(double)Fun_f1 + 2 * (double)Fun_f2;
	return p;
}
double uf2(float Fun_f1, float Fun_f2)
{
	double c = 0.0;
	double d = 0.0;
	c = pow((double)Fun_f1, 2.0) + pow((double)Fun_f2, 2.0);
	d = sqrt(c);
	return d;
}
double uf3(float Fun_f1, float Fun_f2)
{
	double a = (double)Fun_f1 * (double)Fun_f2;
	return a;
}