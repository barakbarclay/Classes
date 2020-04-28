/*
 * Barak Barclay
 * CS1150.002
 * Example 10.4 The MyPoint Class
 * PAST DUE. TURNING IN LATE.
 * This program will find the distance between two point objects or a point 
 * object and a point specified by user inputed x and y values. The MyPoint 
 * class has x and y data fields representing coordinates, getters for both data
 * fields, a no-arg constructor that creates point (0,0), a construtor that 
 * creates a point with specified coordinates, and two distance methods that do
 * what was described above.
 */

import java.util.Scanner;

public class Ex10_4Test {

    public static void main(String[] args) {               

        Scanner input = new Scanner(System.in);

        int choice = 0;
        double x = 0;
        double y = 0;
        MyPoint point1 = new MyPoint(0,0);
        MyPoint point2 = new MyPoint(10,30.5);

        //print welcome and description
        System.out.printf("Welcome to Barak's MyPoint Program."
                + "\nThis program will find the distance between two point "
                + "objects or a point object and a point specified by user "
                + "inputed x and y values.\n\n");

        //prints menu and gets choice
        System.out.printf("0) exit\n1) find distance between two objects\n2)"
                + " find distance between object and inputted point\nInput "
                + "choice:");
        choice = input.nextInt();
        
        //prints distance based on choice
        if (choice == 1){
            System.out.printf("The distance between (0,0) and (10,30.5) is "
                    + "%.2f\n", point1.distance(point2));
        }
        else if (choice == 2){
            System.out.printf("Input x:");
            x = input.nextDouble();
            System.out.printf("Input y:");
            y = input.nextDouble();
            System.out.printf("The distance between (0,0) and (%.2f,%.2f) is "
                    + "%.2f\n", x, y, point1.distance(x,y));
        }
      }
}