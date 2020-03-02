/*
 * Barak Barclay
 * CS1150.002
 * Ex 2.4 Convert Pounds to Kilograms
 * due 01-24-2017
 * Converts pounds to kilograms. Prompts user to input pounds and converts them 
 * to kilograms. The variables are doubles.
 */

import java.util.Scanner;

public class Ex2_4LbsToKilos {

    public static void main(String[] args) {               

        Scanner input = new Scanner(System.in);

        double lbs = 0;
        double kilos = 0;

        //print welcome and description
        System.out.printf("Welcome to Barak's Pounds to Kilograms Converter"
                + "\nThis program converts pounds to kilograms.");

        //Get pounds from user
        System.out.printf("Input pounds > ");
        lbs = input.nextDouble();

        //convert to kilograms and print result
        kilos = 0.454 * lbs;
        System.out.printf("%f km = %f miles\n", lbs,kilos);
      }
}