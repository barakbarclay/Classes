//
//			sentinelLoop.cpp
//
//	By: Barak Barclay
//	Date: 16 Sept 2015
//
//	Problem Statement: Write a program to calculate the average quiz score. (With sentinel loop.)
//
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variables
//		while loop	(sentinel loop)
//			prompt user to enter quiz score
//			read in score
//			add to sum
//		end while
//		caculate average
//		print average to monitor
//	end main
//
#include <stdio.h>

int main(void)
{
	int score = 0;	//quiz score 0-10

	while (true)
	{
		int count = 0;
		int sum = 0;

		float average = 0.0;

		printf_s("%s", "Enter 100 to calculate average. Enter 99 to escape program\n");
		
			while (score >= 0 && score <= 10)
			{
				sum = sum + score;
				count++;	// count = count + 1;
				printf_s("%s", "\nEnter a quiz score between 0-10: ");
				scanf_s("%d", &score);

				if (score != 100 && (score < 0 || score > 10))
				{
					printf_s("%s", "\nInvalid score entered\n");
					score = 0;
					count--;
				}
				if (score == 100)
				{
					average = (float)sum / (float)(count - 1);	//(float) converts the equation to integer math
					printf("\nThe average quiz score is : %f\n", average);
					score = 0;
					sum = 0;
					average = 0;
					count = 0;
				}

			}	//end while


	}
	return 0;
}//main
