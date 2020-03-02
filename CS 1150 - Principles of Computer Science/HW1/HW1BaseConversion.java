/*
 * Barak Barclay
 * CS1450.002
 * HW1BaseConversion
 * 9/19/17
 * ////////////////////////////////////////////////////////////////////
 */
import java.util.*;
import java.util.Scanner;

public class HW1BaseConversion {

    public static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {

        int originalBase = 0;
        int newBase = 0;
        String numericalRepresentation = null;
        boolean continueInput = true;

        //print welcome and description
        System.out.printf("Welcome to Barak's HW1 Base Conversion Program\n");

        //gets the orignal base and only moves on if the user enters an integer
        do {
            try {
                System.out.printf("Enter the orignal base as a number between 2"
                        + " and 36, both inclusive:");
                originalBase = input.nextInt();
                continueInput = false;
            } catch (InputMismatchException ex) {
                System.out.printf("Invalid Input. Try Again.\n");
                input.nextLine();
            }
        } while (continueInput);

        //resets boolean variable
        continueInput = true;

        //gets the new base and only moves on if the user enters an integer
        do {
            try {
                System.out.printf("Enter the new base as a number between 2"
                        + " and 36, both inclusive:");
                newBase = input.nextInt();
                continueInput = false;
            } catch (InputMismatchException ex) {
                System.out.printf("Invalid Input. Try Again.\n");
                input.nextLine();
            }
        } while (continueInput);

        //resets boolean variable
        continueInput = true;

        //gets string and only moves on if the user enters a string
        do {
            try {
                System.out.printf("Enter the numerical representation as a "
                        + "String:");
                numericalRepresentation = input.next();
                continueInput = false;
            } catch (InputMismatchException ex) {
                System.out.printf("Invalid Input. Try Again.\n");
                input.nextLine();
            }
        } while (continueInput);

        //conversion
        for (int i = 0; i == numericalRepresentation.length(); i++) {
            numericalRepresentation.charAt(0);
        }

        //
        System.out.printf(
                "\noriginal base = %d\nnumerical representation = %s"
                + "\nin base %d, numerical representation = %s\n", originalBase,
                numericalRepresentation, newBase, numericalRepresentation);
    }
}
