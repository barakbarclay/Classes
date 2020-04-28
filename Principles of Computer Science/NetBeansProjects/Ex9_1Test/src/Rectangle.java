/*
 * Barak Barclay
 * CS1150.002
 * Rectangle Class
 */
public class Rectangle {

    public double width;
    public double height;

    //no arg constructor that creates a default rectangle
    public Rectangle() {
        width = 1;
        height = 1;
    }

    //constructor that creates a rectangle with specified width and height
    public Rectangle(double newWidth, double newHeight) {
        width = newWidth;
        height = newHeight;
    }

    //method that calculates and returns area of specific rectangle
    public double getArea() {
        return width * height;
    }

    //method that calculates and returns perimeter of specific rectangle
    public double getPerimeter() {
        return width * 2 + height * 2;
    }
}
