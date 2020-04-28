/*
 * Barak Barclay
 * CS1150.002
 * Programming Exercise 9.1 Rectangle Class
 * due 3-9-2017
 * This program has a no argument default construtor that creates a rectangle 
 * height and width of 1. It also has a constructor that creates a rectangle 
 * with a specified width and height. It also includes two methods, one that
 * calculates and returns the area of the rectangle and one that does it from
 * perimeter. The Test program creates two rectangles, one with awidth of 4 and
 * height of 40 and one with a width of 3.5 and a height of 35.9. The test 
 * then prints the width, height, area, and perimeter of both rectangles by 
 * calling the methods in the Rectangle class. 
 */
public class Ex9_1Test {

    public static void main(String[] args) {
        //creates a rectangle with width of 4 and height of 40
        Rectangle rectangle1 = new Rectangle(4, 40);
        //creates a rectangle with width of 3.5 and height of 35.9
        Rectangle rectangle2 = new Rectangle(3.5, 35.9);
        //prints width, height, area and perimeter of first rectangle
        System.out.printf("A rectangle with a width of 4 and a height of 40 has"
                + " a area of %.2f and a perimeter of %.2f\n", 
                rectangle1.getArea(),rectangle1.getPerimeter());
        //prints width, height, area and perimeter of second rectangle
        System.out.printf("A rectangle with a width of 3.5 and a height of 35.9"
                + " has a area of %.2f and a perimeter of %.2f\n", 
                rectangle2.getArea(),rectangle2.getPerimeter());
    }
}
