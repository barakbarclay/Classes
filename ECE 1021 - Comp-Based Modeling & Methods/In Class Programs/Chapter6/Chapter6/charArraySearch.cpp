//
//				charArraySearch.cpp
//
//	By: Barak Barclay
//	Date: 26 Oct 2015
//
//	Problem Statement: Write a program that will prompt the user to enter 
//	a string with length <= 30 characters. You should be able to easily 
//	adjust the array size. Read in string. Than using a for loop count 
//	the number of char characters (hardcode in a char to search for) in the
//	string. Print out the char you searched for and the number of times
//	you found it in the array of char.
//
//	
//
//				<<	Algorithm	>>
//	preprocessor directives
//	init global constants
//	start mian
//		init local varibles
//		prompt user to enter a string <= 30 characters
//		read in string
//		for loop
//			count char number of times found
//		end for loop 
//		print results
//	end main
//
//

#include <stdio.h> //standard input/output library
//#include <stddef.h> <- array code is included in here if it isn't working with another compiler
#define SIZE 5 //allow room for 30 characters plus null character

void Change_Array(float Fun_Array[], size_t Fun_SIZE);

int main()
{
	size_t i;

	float ArrayFloats[SIZE] = { 0.0 }; //have to intialize to get the remainder elements to not have random character in it

	for (i = 0; i < SIZE; i++)
	{
		printf_s("\n Before function call - Array element %u is equal % f \n", i, ArrayFloats);
	} //end for loop

	puts("\n");

	Change_Array(ArrayFloats, SIZE);

	return 0;
}//end main


void Change_Array(float Fun_Array[], size_t Fun_SIZE)
{
	size_t j;

	for (j = 0; j < SIZE; j++)
	{
		Fun_Array[j] = (float)j;
		printf_s("\n After function call - Array element %u is equal % f \n", j, Fun_Array);
	} //end for loop

}//end user fun1