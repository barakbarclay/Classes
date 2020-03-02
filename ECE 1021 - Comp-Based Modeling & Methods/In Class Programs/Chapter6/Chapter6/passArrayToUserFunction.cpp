//
//				passArrayToUserFunction.cpp
//
//	By: Barak Barclay
//	Date: 26 Oct 2015
//
//	Problem Statement: Write a program that initializes an array of floats
//	of size (#define SIZE 5) to zero. Prints out the element number and
//	value. Calls a user function which changes the array - set each array
//	element to its index number. Then prints our the element numnber and 
//	value of the array again.
//
//	
//
//				<<	Algorithm	>>
//	preprocessor directives
//	function prototypes
//	init global constants
//	start mian
//		init local varibles
//		print out element and array value
//		call user function
//		print our element and array value
//		end main
//
//			$$$		11111	$$$
//	void Function change array
//		init local variables
//		change array
//	end user functions
//

#include <stdio.h> //standard input/output library
//#include <stddef.h> <- array code is included in here if it isn't working with another compiler
#define SIZE 5 //allow room for 30 characters plus null character

void Change_Array(float Fun_Array[], size_t Fun_SIZE);

int main()
{
	size_t i;

	float ArrayFloats[SIZE] = {0.0}; //have to intialize to get the remainder elements to not have random character in it

	for (i = 0; i < SIZE; i++)
	{
		printf_s("\n Before function call - Array element %u is equal % f \n", i , ArrayFloats);
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