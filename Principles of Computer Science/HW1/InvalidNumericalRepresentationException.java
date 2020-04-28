/*
 * Barak Barclay
 * CS1450.002
 * HW1BaseConversion
 * 9/19/17
 * ////////////////////////////////////////////////////////////////////
 */

public class InvalidNumericalRepresentationException extends Exception {

    public InvalidNumericalRepresentationException(int base) {
        super("\nInput must be a valid numerical representation for base "
                + base + ". Try again.\n");
    }

}
