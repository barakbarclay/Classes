/*
 * Barak Barclay
 * CS1450.002
 * HW1BaseConversion
 * 9/19/17
 * ////////////////////////////////////////////////////////////////////
 */

public class NumbericalRepresentationTooBigException extends Exception {

    public NumbericalRepresentationTooBigException() {
        super("\nThis String will be converted to an integer which can only "
                + "hold 4 bytes. The String you entered is too large. Try again"
                + " with a smaller number representation.\n");
    }

}
