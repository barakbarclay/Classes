/*
 * Barak Barclay
 * CS1450.002
 * HW1BaseConversion
 * 9/19/17
 * This program converts a number representation from one base to another. To 
 * implement this the program first asks for the user to enter the orignal base
 * of the number they want to convert. Once it has the orignal base, it gets the
 * new base and the number representation respectively. All three of these user 
 * inputs are checked for errors. The program then prints a line of code in
 * which it calls the converter utility to give the user the number 
 * representation in the new base. This is done by first converting the number
 * into base 10. This is done by giving a numerical value for the ASCII
 * representation, and then muliplying each digit by the increasing powers of 
 * 10 from right to left. The base 10 number is then converted to the new base
 * by dividing the number by the new base until there is no remainder, then 
 * using the remainders to represent the value. Then the value can be converted 
 * back to ASCII and returned to the user. 
 */

public class InputOutOfBoundsException extends Exception {

    public InputOutOfBoundsException(int min, int max) {
        super("\nInput must be an integer between " + min + " and " + max
                + ", both inclusive. Try Again.\n");

    }
}
