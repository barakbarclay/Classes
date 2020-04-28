//
//				arrayOfChar.cpp
//
//	By: Barak Barclay
//	Date: 20 Oct 2015
//
//	Problem Statement: Write a program that will prompt the user to enter a string with length <= 30 characters. You should be able to easily 
//	adjust the array size. read in the string from the key board, Then using a for loop write each character to the screen, with a space after 
//	each array character. The characters printed to the screen should only be the characters in the entered string - no extra characters.
//
//	HNIT: A apace character is a blank ASCII character.
//
//				<<	Algorithm	>>
//	preprocessor directives
//	define functions
//	define global constants
//	start mian
//		define and init caribles
//		prompt user to enter string <= 30 characters
//		read in string
//		for loop
//			printf a char from a string
//		end loop
//	end main
#include <stdio.h> //standard input/output library
//#include <stddef.h> <- array code is included in here if it isn't working with another compiler
#define size 31 //allow room for 30 characters plus null character
#pragma warning(disable : 4996)

void main(void)
{
	char string[size] = {}; //have to intialize to get the remainder elements to not have random character in it

	size_t i;

	printf_s("\nEnter a string without a space, tab, newline or EOF and less than %d characters. \n\n", size);

	//scanf("%s", string); //to have someone enter an element other than zero put &string[1] insead of string <- replace 1 to use another element number
	//gets(string); //gets command will take in blank spaces
	fgets(string, sizeof string, stdin); //fgets commmand will take in blank spaces and it won't give an error if you enter too many characters //it needs size of and where the information is coming from

	for (i = 0; i < size; i++)
	{
		printf_s("%c ", string[i]);
	} //end for loop

	printf_s("\n");

}//end main