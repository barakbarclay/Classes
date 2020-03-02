//
//		charArraySearch.cpp
//
//By: Camille Blanton
//Date: 26 Oct 2015
//
//Problem Statement: Write a program that will prompt the user to enter
//	a string with length <= 30 characters. You should be able to easily
//	adjust the array size. Read in the string. Then using a for loop count
//	the number of char characters (hardcode in a char to search for) in the
//	string. Print out the char you searched for and the number of times 
//	you found it in the array of char. 
//	
//
//		<<Algorithm>>
//
// preprocessor directives
// init global constant
// 
//	task main
//		init variables
//		prompt user to enter a string <= 30 characters
//		read in string 
//		for loop
//			count char number of times found
//		end for loop
//		print result
//	end main
//

#include <stdio.h>

#define SIZE 31

#pragma warning (disable:4996)

void main(void)
{
	char find_char = 'e';
	char string[SIZE];

	int count_e = 0;

	size_t i;


	printf("Enter a string without space, tab, newline or eof and less than %d characters", (SIZE - 1));
	//scanf("%s", string); // does not need address operator since its in an array
	gets(string); // allows for spaces in the string

	puts("\n");

	for (i = 0; i < SIZE; i++)
	{
		if (string[i] == find_char)
		{
			++count_e;
		}
	} //end for loop

	printf("\nThe number of %c's in the string is %d. \n\n", find_char, count_e);


} // end main function