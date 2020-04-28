/*
 * Barak Barclay
 * CS1150.002
 * Excercise 11.1 (The Triangle Class)
 * PAST DUE. TURNING IN LATE.
 * This program creates a geometric object, specifically a triangle which is an 
 * extension of the geometric object. The triangle extension haas three sides as 
 * parameters, a no arg construtor creating a triangle with sides 1,1,1, getters 
 * for all three sides, methods that calculate and reurn the area and perimeter 
 * of the triangle, and a method that returns a string of information on the 
 * triangle including the information of the geometric object. The geometric 
 * object has data fields for the color and whether or not the object is filled.
 * it also has the getters, setters, constructors and toString method necessary 
 * to do this program. The test program allows the user to create an object with 
 * all the data fields mentioned above, prints back out those data fields, and 
 * the ones calculated. 
 */
import java.util.Scanner;

public class Test11_1 {

    public static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        
        double side1 = 0;
        double side2 = 0;
        double side3 = 0;
        String color = "black";
        boolean filled = false;
        
        //print welcome and description
        System.out.printf("Welcome to Barak's Triangle Program"
                + "\nAfter inputing the information for a triangle, this "
                + "program will print the information back to you along with "
                + "the area and the perimeter of the triangle.\n");
        
        //gets user input for triangle
        System.out.printf("Enter side 1 of triangle:");
        side1 = input.nextInt();
        System.out.printf("Enter side 2 of triangle:");
        side2 = input.nextInt();
        System.out.printf("Enter side 3 of triangle:");
        side3 = input.nextInt();
        System.out.printf("Enter color of triangle:");
        color = input.next();
        System.out.printf("The triangle is filled (true or false):");
        filled = input.nextBoolean();
        
        //creates triangle/geometric object
        Triangle myTriangle = new Triangle(color, filled, side1, side2, side3);
        
        //prints info for triangle
        System.out.printf("%s\narea = %.2f\nperimeter = %.2f\n", 
                myTriangle.toString(), myTriangle.Area(), 
                myTriangle.Perimeter());
    }
}
