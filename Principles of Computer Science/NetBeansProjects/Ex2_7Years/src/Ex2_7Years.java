/*
 * Barak Barclay 
 * CS1150.002
 * Exercise 2.7 Find the number of years
 * due 1-26-2017
 * Converts minutes to years and days. Prompts user to input minutes and 
 * converts them to the amount of years and days the minutes are equal to. The 
 * variables are doubles.
 */

import java.util.Scanner;

public class Ex2_7Years {

    public static void main(String[] args) {               

        Scanner input = new Scanner(System.in);

        double min = 0;
        double years = 0;
        double days = 0;

        //print welcome and description
        System.out.printf("Welcome to Barak's Minutes to Years and Days "
                + "Converter\nThis program will tell you how many years and "
                + "days the number of minutes you enter is. ");

        //Get minutes from user
        System.out.printf("Enter the number of minutes: ");
        min = input.nextDouble();

        //convert to years and days and print result
        years = min/(60*24*365);
        days = (min%(60*24*365))/(60*24);
        System.out.printf("%.0f minutes is approximately %.0f years and %.0f "
                + "days\n", min,years,days);
      }
}