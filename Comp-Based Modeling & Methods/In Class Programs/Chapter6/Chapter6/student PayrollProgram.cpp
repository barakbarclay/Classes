//
//			HWK4(5).cpp
//
//	By: Barak Barclay
//	Date: 23 Sept 2015
//
//	Problem Statement:  Write a student payroll program using multiple arrays and multiple user functions.
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
//	function prototypes
//	init global variables
//  start main
//		define local variable	
//		call uf enter hours worked
//		call uf pay rates
//		call uf calculate paycheck
//		call uf print tables
//	end main
//
//
//			%%%%		1		%%%%
//	 define local varibles
//	prompt user to enter hours worked
//	store hours worked into array
//	exit uf
//
//
//			%%%%		2		%%%%
//	define local variables
//	prompt user to enter payrates
//	store payrates into array
//	exit uf
//
//
//			%%%%		3		%%%%
//	define loccal variables
//	prompt user to enter paycheck
//	store paycheck into array
//	exit uf
//			%%%%		4		%%%%
//	define loccal variables
//	print pay table
//	exit uf
//
//
#include <stdio.h>
#include <stddef.h>
#define SIZE 6
#pragma warning(disable : 4996)

void studentHours(float hours[], size_t Fun_size);
void studentRates(float rates[], size_t Fun_size);
void studentPay(const float hours[], size_t Fun_size, const float rates[], size_t, float pay[], size_t);
void printTable(float hours[], size_t Fun_size, float rates[], size_t, float pay[], size_t);
void main(void)
{
	float Shours[SIZE] = { 0.0 };
	float Srates[SIZE] = { 0.0 };
	float Spay[SIZE] = { 0.0 };
	
	studentHours(Shours, SIZE);
	studentRates(Srates, SIZE);
	studentPay(Shours, SIZE, Srates, SIZE, Spay, SIZE);
	printTable(Shours, SIZE, Srates, SIZE, Spay, SIZE);
}
void studentHours(float hours[], size_t Fun_size)
{
	size_t i;
	for (i = 1; i < Fun_size; i++)
	{
		printf("\nEnter in the hours worked for student %d.\n", i);
		scanf("%f", &hours[i]);
	}
}
void studentRates(float rates[], size_t Fun_size)
{
	size_t i;
	for (i = 1; i < Fun_size; i++)// start at 1 and the zeroth element doesn't contain anything
	{
		printf("\nEnter in the student pay rate %d.\n", i);
		scanf("%f", &rates[i]);
	}
}
void studentPay(const float hours[], size_t Fun_size, const float rates[], size_t, float pay[], size_t)
{
	size_t i;
	for (i = 1; i < Fun_size; i++)
	{
		pay[i] = hours[i] * rates[i];
	}
}
void printTable(float hours[], size_t Fun_size, float rates[], size_t, float pay[], size_t)
{
	size_t i;
	puts("Student		Hours		Rate		Pay");
	for (i = 1; i < Fun_size; i++)
	{
		printf("%d		%10.2f %8.2f %9.2f \n\n", i, hours[i], rates[i], pay[i]);
	}
}