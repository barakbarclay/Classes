/*
 * Barak Barclay
 * CS1150.002
 * ScoreAnalyzer  
 * due 4-6-2017
 * This program asks the user to input the number of scores they have, input all
 * of the scores individually, creates and fills an array with those scores, and
 * calls 5 methods that analyze the scores. The methods find the min and max 
 * scores, the average, the # of scores at or above average, and the # of scores
 * below average.
 */

import java.util.Scanner;

public class ScoreAnalyzer {

    public static int size = 0;

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        double average = 0.0;
        double scores[];
        
        //print welcome and description
        System.out.printf("Welcome to Barak's ScoreAnalyzer Program"
                + "\nAfter inputing the number of scores you have, and "
                + "inputting each score indiviually, this program will tell you"
                + " the min and max scores, the average, the # of scores at or "
                + "above average, and the # of scores below average.\n");

        //creates array
        System.out.printf("Input the number of scores:");
        size = input.nextInt();
        scores = new double[size];

        //fills array
        for (int i = 1; i <= size; i++) {
            System.out.printf("Input score:");
            scores[i - 1] = input.nextDouble();
        }

        //calls all 5 methods and prints return values for them all
        average = averager(scores);
        System.out.printf("\nMax score: %.2f\nMin score:%.2f\nAverage:%.2f\n# of "
                + "scores at or above average:%d\n# of scores below average:%d"
                + "\n", maxScore(scores), minScore(scores), average, 
                averageAndAbove(scores, average), belowAverage(scores,average));
    }

    //finds max score
    public static double maxScore(double scores[]) {
        double temp = scores[0];
        for (int i = 1; i <= size - 1; i++) {
            if (scores[i] > scores[i - 1]) {
                temp = scores[i];
            }
        }
        return temp;
    }

    //finds min score
    public static double minScore(double scores[]) {
        double temp = scores[0];
        for (int i = 1; i <= size - 1; i++) {
            if (scores[i] < scores[i - 1]) {
                temp = scores[i];
            }
        }
        return temp;
    }

    //finds average
    public static double averager(double scores[]) {
        double temp = scores[0];
        for (int i = 1; i <= size - 1; i++) {
            temp += scores[i];
        }
        temp /= size;
        return temp;
    }

    //finds # of score at and above average
    public static int averageAndAbove(double scores[], double average) {
        int temp = 0;
        for (int i = 1; i <= size; i++) {
            if (scores[i - 1] >= average) {
                temp++;
            }
        }
        return temp;
    }

    //finds # of scores below average
    public static int belowAverage(double scores[], double average) {
        int temp = 0;
        for (int i = 1; i <= size; i++) {
            if (scores[i - 1] < average) {
                temp++;
            }
        }
        return temp;
    }
}
