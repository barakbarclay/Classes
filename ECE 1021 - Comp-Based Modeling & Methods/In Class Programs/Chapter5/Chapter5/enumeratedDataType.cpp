//
//				enumeratedDataType.cpp
//
//	By: Barak Barclay
//	Date: 12 Oct 2015
//
// Problem Statement: Write aprogram using Enumerated dat types for
// the days of the week. Use a while loop to loop until day = Saturday.
// Use a switch statement to write out a message for each day of the week
// and set the day to the next day of the week.
//
//
//			####	Algorithm	####
//	int variables - decale enum data type
//  while loop
//		switch
//			write day message
//			set day to next day
//		end switch
//	end while
//
//
#include <stdio.h>

enum Weekday{Sunday = 3, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday}; // Sets whatever you want as data type. Normally starts at 0. Values inside can be set to start at different numbers ie. 3 in this case.

#pragma warning(disable :4996)

void main(void)
{
	enum Weekday Day = Saturday;

	while (Day != Saturday)
	{
		switch (Day)
		{

		}//end swtich

	}//end while
}//end main