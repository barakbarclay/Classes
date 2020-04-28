//
//			quizAverage.cpp
//
//	By: Barak Barclay
//	Date: 14 Sept 2015
//
//	Problem Statement: Write a program to calculate the average quiz score.
//
//
//			%%%%	Algorthim	%%%%
//
//	preprocessor directives
// start main
//		init variables
//		while loop	-	auumen will enter 5 quiz scores
//			prompt user to enter quiz score
//			read in score
//			add to sum
//		end while
//		caculate average
//		print average to monitor
//	end main
//
#include <stdio.h>
#pragma warning(disable: 4996) //Pragma command ignores error numbers			//scanf_s can also be used

int main(void)
{
	int score = 0;	//quiz score 0-10
	int sum = 0;
	int count = 1; //start at 1 instead of 0 to count to 5

	float average = 0.0; // .0 for a decimal float number

	while (count <= 5)
	{
		puts("\nEnter a quiz score.");
		scanf("%d", &score);

		sum = sum + score;

		count++;	// count = count + 1;
	}	//end while
	average = (float) sum / (float) (count - 1);	//(float) converts the equation to integer math
	printf("\nThe average quiz score is : %f\n", average);

	return 0;
}//main
