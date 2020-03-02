//
//			multi_DimensionalArray.cpp
//
//	By: Barak Barclay
//	Date: 16 Nov 2015
//
//	Problem Statement: Write an example problem using multidimensional arrays.
//
//
//		#####	Algorithm	####
//
//	algorithm here
//
//
#include<stdio.h>

#define TableSIZE 13

void BuildMulTable(int MulTable[][TableSIZE], size_t Fun_s);
void PrintMulTable(int MulTable[][TableSIZE], size_t Fun_s);

void main(void)
{
	int MulTable[TableSIZE][TableSIZE] = { { 0 }, { 0 } };

	BuildMulTable(MulTable, TableSIZE);
	PrintMulTable(MulTable, TableSIZE);
}//end main

void BuildMulTable(int MulTable[][TableSIZE], size_t Fun_s)
{
	size_t j, k;

	for (j = 0; j < Fun_s; j++)
	{

		for (k = 0; k < Fun_s; k++)
		{
			MulTable[j][k] = j*k;
		}//end inner for

	}//end outer for
}//end uf

void PrintMulTable(int MulTable[][TableSIZE], size_t Fun_s)
{
	size_t j, k;

	puts("\n\n\t\t  Multiplication  Table (0-9) \n");
	printf("     ");

	for (j = 0; j < Fun_s; j++)
	{
		printf("%5d", j);
	}

	puts("\n");

	for (j = 0; j < Fun_s; j++)
	{
		printf("%5d", j);
		for (k = 0; k < Fun_s; k++)
		{
			printf("%5d", MulTable[j][k]);
		}//end inner for
		puts("");
	}//end outer for
	puts("\n");
}//end uf