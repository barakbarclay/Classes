/*
 * Barak Barclay
 * CS1150.002
 * Triangle Class
 */

public class Triangle extends GeometricObject {

    private double side1;
    private double side2;
    private double side3;

    //no arg constructor that creates a triangle with sides, 1, 1, 1
    public Triangle() {
        this("black", false, 1.0, 1.0, 1.0);
    }

    //constructor that creates triangle with specified sides
    public Triangle(String color, boolean filled, double side1, double side2, double side3) {
        super(color, filled);
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    //getter for side1
    public double getSide1() {
        return side1;
    }

    //getter for side2
    public double getSide2() {
        return side2;
    }

    //getter for side3
    public double getSide3() {
        return side3;
    }

    //method that returns the area of the triangle
    public double Area() {
        return Math.sqrt(this.Perimeter() / 2 * ((this.Perimeter() / 2)
                - side1) * ((this.Perimeter() / 2) - side2)
                * ((this.Perimeter() / 2) - side3));
    }

    //method that returns the perimeter of the triangle
    public double Perimeter() {
        return side1 + side2 + side3;
    }

    //method that returns a string of information of the triangle
    public String toString() {
        return "Triangle:\nside1 = " + side1 + "\nside2 = " + side2 + "\nside3 = "
                + side3 + super.toString();
    }
}
