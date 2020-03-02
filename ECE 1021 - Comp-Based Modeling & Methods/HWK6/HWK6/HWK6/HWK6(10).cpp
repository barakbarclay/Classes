#include <stdio.h>
#define SIZE 80
#pragma warning(disable : 4996)
void uf1(float *a, size_t *i);
void uf2(float Fun_a, size_t Fun_i);
void main(void)
{
	float a[SIZE];
	size_t i;
	uf1(a[SIZE], &i);
	uf2(a[SIZE], i);
}
void uf1(float *a, size_t *i)
{
	for (*i = 0; *i < SIZE; *i++)
	{
		a[*i]* = 10;
	}
}
