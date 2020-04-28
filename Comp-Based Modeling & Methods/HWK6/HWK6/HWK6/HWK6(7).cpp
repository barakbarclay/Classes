#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996)
void uf(int Fun_amp, float Fun_freq);
void main(void)
{
	int amp = 0;
	float randnum = 0;
	float freq = 0;
	amp = (rand() % 10) + 1;
	printf("Amp is: %d \n", amp);
	randnum = (float)(rand() % 40) + (float)10.0;
	freq = (float)randnum / (float)(RAND_MAX + 1);
	printf("Freq is: %d \n", freq);
	uf(amp, freq);
}
void uf(int Fun_amp, float Fun_freq)
{
	float x = 0.0;
	double Pi = 3.14159265359;
	int i;
	for (i = 0; i <= 50; i++)
	{
		x = (float)Fun_amp * (float)cos(Fun_freq * Pi * (float)i / 20.0);
		printf("i = %d\tx = %f\n", i, x);
	}
}