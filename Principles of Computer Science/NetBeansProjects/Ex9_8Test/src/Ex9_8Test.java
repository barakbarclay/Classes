/*
 * Barak Barclay
 * CS1150.002
 * Ex9_8Test and Fan
 * due 3-21-2017
 * The fan class of this project creates data fields for speed, on, radius, and
 * color for a fan. It has accessors and mutators for each of the data fields.
 * It has a no arg constructor that creates a  default fan and a toString() 
 * method that prints the fan's information. The test program creates two fans.
 * One with max speed, radius of 10, yellow, and on. The other with medium 
 * speed, radius of 5, blue, and off.
 */

public class Ex9_8Test {

    public static void main(String[] args) {               

        //print welcome and description
        System.out.printf("Welcome to Barak's Program"
                + "\nThis program creates two fans.\nOne with max speed, radius"
                + " of 10, yellow, and on.\nThe other with medium speed, radius"
                + " of 5, blue, and off.\n");

        //creates 2 fan objects
        Fan fan1 = new Fan();
        Fan fan2 = new Fan();
        
        //sets speed, radius, color and on position for fan 1
        fan1.setSpeed(Fan.FAST);
        fan1.setRadius(10);
        fan1.setColor("yellow");
        fan1.setOn(true);
        //sets speed, radius, color and on position for fan 1
        fan2.setSpeed(Fan.MEDIUM);
        fan2.setRadius(5);
        fan2.setColor("blue");
        fan2.setOn(false);

        //prints fan1
        System.out.printf("%s\n", fan1.toString());
        //prints fan2
        System.out.printf("%s\n", fan2.toString());
      }
}
