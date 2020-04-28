/*
 * Barak Barclay
 * CS1150.002
 * Excercise 12.2 (InputMismatchException)
 * 04/27/17
 * This program adds to integers and checks that the numbers entered are 
 * integers. It does this by going into a do-while loop and try block which gets
 * the users input. If the input is correct, a boolean variable is set to false 
 * and is allowed to exit the loop. If an invallid input is entered, the catch 
 * block contains an exception which tells the user he/she entered an invalid 
 * input and re-initiates the try block. To do this for the second integer, the 
 * boolean variable is reset and the same process is repeated. The sum is then 
 * printed to the user.
 */
import java.util.*;
import java.util.Scanner;

public class Ex12_2InputMismatch {

    public static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {

        int num1 = 0;
        int num2 = 0;
        boolean continueInput = true;

        //print welcome and description
        System.out.printf("Welcome to Barak's Addition Program\nThis program "
                + "will ask you to enter two integer and will return the sum to"
                + " you.\n");

        //gets the first integer and only moves on if the user enters an integer
        do {
            try {
                System.out.printf("Enter an integer:");
                num1 = input.nextInt();
                continueInput = false;
            } catch (InputMismatchException ex) {
                System.out.printf("Invalid Input. Try Again.\n");
                input.nextLine();
            }
        } while (continueInput);
        
        //resets boolean variable
        continueInput = true;
        
        //gets second integer and only moves on if the user enters an integer
        do {
            try {
                System.out.printf("Enter an integer:");
                num2 = input.nextInt();
                continueInput = false;
            } catch (InputMismatchException ex) {
                System.out.printf("Invalid Input. Try Again.\n");
                input.nextLine();
            }
        } while (continueInput);

        //prints the sum to the user
        System.out.printf("The sum of %d and %d is %d.", num1, num2, num1+num2);
    }
}
