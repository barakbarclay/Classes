/*
 * Barak Barclay
 * CS1150.002
 * Ex 3.2 Add Three Numbers
 * due 1-31-2017
 * This program generates 3 single digit integers, prompts the user to enter 
 * the sum of those integers, and returns the correct answer.
 */

import java.util.Scanner;

public class Ex3_2AddThree {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        //initialize variables to random inegers
        int number = 0;
        int number1 = (int) (Math.random() * 10);
        int number2 = (int) (Math.random() * 10);
        int number3 = (int) (Math.random() * 10);
        int answer = number1 + number2 + number3;

        //print welcome and description
        System.out.printf("Welcome to Barak's addition game.\nThis program will"
                + " ask you the sum of three randon single digit integers.");

        //asks user to enter the sum
        System.out.print(
                "What is " + number1 + " + " + number2 + " + " + number3
                + "? ");
        number = input.nextInt();

        //tells user what the answer is
        System.out.println(
                number1 + " + " + number2 + " + " + number3 + " = " + answer
                + " is " + (number1 + number2 + number3 == answer) + ". Your "
                        + "answer is " + (number == answer) + ".");
    }
}
