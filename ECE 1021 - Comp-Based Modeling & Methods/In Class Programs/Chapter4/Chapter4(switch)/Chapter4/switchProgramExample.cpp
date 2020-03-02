//			switchProgramExample.cpp
//
//	By: Barak Barclay
//	Date: 23 Sept 2015
//
//	Problem Statement: Write a program that will prompt the user to enter an integer 
//	number between 0 and 5 - inclusive. Use a Sentinel loop to keep looping until 
//	the user wants to quit. Read in integer. Use a switch statement to test which
//	number was entered to write a message to the screen stating what the number was. 
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variables
//		do..while loop
//			prompt user to enter a number
//			read number
//			switch(number)
//				case 0 :
//					print zero
//					break
//				case 1:
//					print one
//					break
//				case 2:
//					print two
//					break
//				case 3:
//					print three
//					break
//
//					ditto
//
//				default:
//				print errot I never seen that number
//				break
//			endswitch
//		end do..while
//	end main
#include<stdio.h>

int main(void)
{
	int num = -1;

	do{
		printf_s("\nEnter a number between 0 and 9, =99 to quit.\n");
		scanf_s("%d", &num);

		if (num == -99)
			break;

		switch (num)
		{
		case 0:
		{
				  puts("\nYou entered zero. ");
				  break;
		}	//end case
		case 1:
		{
				  puts("\nYou entered one. ");
				  break;
		}	//end case
		case 2:
		{
				  puts("\nYou entered two. ");
				  break;
		}	//end case
		case 3:
		{
				  puts("\nYou entered three. ");
				  break;
		}	//end case
		case 4:
		{
				  puts("\nYou entered four. ");
				  break;
		}	//end case
		case 5:
		{
				  puts("\nYou entered five. ");
				  break;
		}	//end case
		case 6:
		{
				  puts("\nYou entered six. ");
				  break;
		}	//end case
		case 7:
		{
				  puts("\nYou entered seven. ");
				  break;
		}	//end case
		case 8:
		{
				  puts("\nYou entered eight. ");
				  break;
		}	//end case
		case 9:
		{
				  puts("\nYou entered nine. ");
				  break;
		}	//end case
		default:
		{
				  puts("\n\n	ERROR - no valid number entered. \n\n");
				  break;
		}	//end case

		}	//end switch

	} while (num != -99); //end do..while
	return 0;
}