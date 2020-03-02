/*
 * Barak Barclay
 * CS1150.002
 * Fan Class
 */
public class Fan {

    final static int SLOW = 1;
    final static int MEDIUM = 2;
    final static int FAST = 3;
    private int speed;
    private boolean on;
    private double radius;
    String color;

    //getter for speed
    public int getSpeed() {
        return speed;
    }

    //getter for on
    public boolean getOn() {
        return on;
    }

    //getter for radius
    public double getRadius() {
        return radius;
    }

    //getteer for color
    public String getColor() {
        return color;
    }
    
    //setter for speed
    public void setSpeed(int speed) {
        this.speed = speed;
    }

    //setter for on
    public void setOn(boolean on) {
        this.on = on;
    }

    //setter for radius
    public void setRadius(double radius) {
        this.radius = radius;
    }

    //setter for color
    public void setColor(String color) {
        this.color = color;
    }

    //no arg default fan
    public Fan() {
        speed = SLOW;
        on = false;
        radius = 5.0;
        color = "blue";
    }

    //creates a string that returns the fan's information
    public String toString() {
        if (on == true) {
            return "Fan Speed:" + speed + "\tFan Color:" + color
                    + "\tFan Radius:" + radius;
        } else {
            return "Fan is off" + "\tFan Color:" + color + "\t\tFan Radius:"
                    + radius;
        }
    }
}
