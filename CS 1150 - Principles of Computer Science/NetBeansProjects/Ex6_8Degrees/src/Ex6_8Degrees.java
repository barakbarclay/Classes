/* Barak Barclay
 * CS1150.002
 * Exercise 6.8 Conversions between Celsius and Fahrenheit
 * due 3-7-2017
 * This program prints a table that converts calsius to fahrenheit and vice
 * versa. It does this by printing a heading and then going into a for loop.
 * within the for loop, a printf statement prints the value of a preset celsius,
 * calls the celsiustofahrenheit method to print what it is in fahrenheit, and 
 * does the same for celsius values. The for loop increments the celsius and 
 * fahrenheit values each time it goes throught the for loop. The methods only 
 * convert the values and return the converted value.*/
public class Ex6_8Degrees {

    public static void main(String[] args) {

        double celsius = 40;
        double fahrenheit = 120;
        //print welcome and description
        System.out.printf("Welcome to Barak's program.\nThis program will print"
                + " a table that shows what celius temperture is in fahrenheit "
                + "and vice versa using methods.\n");
        //print table heading
        System.out.printf("Celsius\t\tFahrenheit\t|\tFahrenheit\tCelsius\n_____"
                + "__________________________________________________________"
                + "\n");
        //for loop that calls methods to print table
        for (int i = 0; i <= 10; i++) {
            System.out.printf(" %4.2f\t\t  %6.2f\t|\t  %6.2f\t %4.2f\n",
                    celsius, celsiusToFahrenheit(celsius), fahrenheit,
                    fahrenheitToCelsius(fahrenheit));
            celsius++;
            fahrenheit++;
        }
    }

    //Convert from Celsius to Fahrenheit
    public static double celsiusToFahrenheit(double celsius) {
        double methFahrenheit = 0;
        methFahrenheit = (9.0 / 5) * celsius + 32;
        return methFahrenheit;
    }

    //Convert from Fahrenheit to Celsius
    public static double fahrenheitToCelsius(double fahrenheit) {
        double methCelsius = 0;
        methCelsius = (5.0 / 9) * (fahrenheit - 32);
        return methCelsius;
    }
}
