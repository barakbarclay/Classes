/*
 * Barak Barclay
 * CS1450.002
 * HW1BaseConversion
 * 9/19/17
 * ////////////////////////////////////////////////////////////////////
 */

public class InputOutOfBoundsException extends Exception {

    public InputOutOfBoundsException(int min, int max) {
        super("\nInput must be an integer between " + min + " and " + max
                + " (inclusive). Try Again.\n");

    }
}
