//
//			HWK4(2).cpp
//
//	By: Barak Barclay
//	Date: 23 Sept 2015
//
//	Problem Statement: Rewrite the first problem using a switch statement
//	instead of if-else statements.
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variable
//		do while loop	(num >= 0)
//			switch statement
//		end while
//	end main
//

#include<stdio.h>

int main(void)
{
	int num = 0;

	do{
		printf_s("\nEnter a integer between 1 and 5.\n");
		scanf_s("%d", &num);

		switch (num)
		{
		case 1:
		{
				  printf_s("Hydrogen");
				  break;
		}	//end case
		case 2:
		{
				  printf_s("Helium");
				  break;
		}	//end case
		case 3:
		{
				  printf_s("Lithium");
				  break;
		}	//end case
		case 4:
		{
				  printf_s("Beryllium");
				  break;
		}	//end case
		case 5:
		{
				  printf_s("Boron");
				  break;
		}	//end case
		default:
		{
				   printf_s("Value entered is out of bounds.");
				   break;
		}	//end case

		}	//end switch

	} while (num >= 0); //end do..while
	return 0;
}