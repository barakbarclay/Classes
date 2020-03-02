//
//			EnumeratedDataType.cpp
//
//By: Camille Blanton
//Date: 12 Oct 2015
//
//Problem Statement: Write a program using Enumerated data types for
//the days of the week. Use a while loop to loop until day = Saturday.
//Use a switch statement to write out a message for each day of the week
//and set the day to the next day of the week. 
//
//			<<<<Algorithm>>>>
//
//initialize variables
//	declare enum data type
//while loop
//	switch
//		write day message
//		set day to next day
//	end switch 
//end while
//
//
#include <stdio.h>

enum Weekday{ Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
 
int main(void)
{
	enum Weekday Day = Sunday; // start @ Sunday

	while (Day != Saturday)
	{
		switch (Day)
		{
		case 0:
		{
			puts("It's Sunday - Play day. \n");
			Day = Monday;
			break;
		}

		case 1:
		{
			puts("It's Monday - Time to program in C. \n");
			Day = Tuesday;
			break;
		}

		case 2:
		{
			puts("It's Tuesday - Time to do ECE 1021 homework. \n");
			Day = Wednesday;
			break;
		}

		case 3:
		{
			puts("It's Wednesday - Yay programming again.\n");
			Day = Thursday;
			break;
		}

		case 4:
		{
			puts("It's Thursday - Sad no C for a week. \n");
			Day = Friday;
			break;
		}

		case 5:
		{
			puts("It's Friday - Free at last. \n");
			Day = Saturday;
			break;
		}

		default:
		{
			puts("\n\n     ERROR - Not a valid case - ERROR\n\n");
			break;
		}


		} // end switch

	} // end while

	printf("\n Day of the Week integer is -> %d \n\n", Day);
	Day = static_cast<Weekday> (Day - 6);
	printf("\n Day of the Week integer is -> %d \n\n", Day);

} // end main