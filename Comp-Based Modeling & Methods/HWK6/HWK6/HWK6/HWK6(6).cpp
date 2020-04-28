#include <stdio.h>
#include <math.h>
#pragma warning(disable : 4996)
double uf(double Fun_b, double Fun_p);
void main(void)
{
	double b = 2.0;
	double p = 3.0;
	printf("Enter a base:");
	scanf("%lf", &b);
	printf("Enter a power:");
	scanf("%lf", &p);
	printf("%lf", uf(b, p));
	printf("\n");
}
double uf(double Fun_b, double Fun_p)
{
	if ((int)Fun_p == 1)
	{
		return Fun_b;
	}
	else
	{
		return (Fun_b * pow(Fun_b, (Fun_p - 1)));
	}
}