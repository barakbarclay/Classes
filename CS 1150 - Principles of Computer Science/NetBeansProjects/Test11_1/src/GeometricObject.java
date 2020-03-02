/*
 * Barak Barclay
 * CS1150.002
 * GeometricOject Class
 */

public class GeometricObject {

    private String color;
    private boolean filled;

    //no arg consturtor that creates a geometric object 
    public GeometricObject() {
        this("black", false);
    }

    //construtor that creates a geometric object with specified parameters
    public GeometricObject(String color, boolean filled) {
        this.color = color;
        this.filled = filled;
    }

    //getter for color
    public String getColor() {
        return color;
    }

    //setter for color
    public void setColor(String color) {
        this.color = color;
    }

    //getter for filled
    public boolean getFilled() {
        return filled;
    }

    //setter for filled
    public void setFilled(boolean filled) {
        this.filled = filled;
    }
    
    //method that returns string of information of geometric object
    public String toString(){
        return "\ncolor = " + color + "\nis filled: " + filled;
    }
}
