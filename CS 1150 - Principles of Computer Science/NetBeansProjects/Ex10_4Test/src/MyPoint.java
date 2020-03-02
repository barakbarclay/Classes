/*
 * Barak Barclay
 * CS1150.002
 * MyPoint Class
 */
public class MyPoint {

    private double x;
    private double y;

    //no-arg consturctor creates point (0,0)
    public MyPoint() {
        this(0, 0);
    }

    //creates a point with specified x and y
    public MyPoint(double x, double y) {
        this.x = x;
        this.y = y;
    }

    //gets x value
    public double getX() {
        return x;
    }

    //gets y value
    public double getY() {
        return y;
    }

    //returns the distance between this point objectand another
    public double distance(MyPoint anyPoint) {
        return Math.sqrt(Math.pow(anyPoint.getX() - x, 2) + 
                Math.pow(anyPoint.getY() - y, 2));
    }

    //returns the distance between this point object and a point specified by x
    //and y
    public double distance(double x, double y) {
        return Math.sqrt(Math.pow(this.x - x, 2) + Math.pow(this.y - y, 2));
    }
}
