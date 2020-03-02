/*
 * Barak Barclay
 * CS1450.002
 * HW1BaseConversion
 * 9/19/17
 * ////////////////////////////////////////////////////////////////////
 */

public class MaxAttemptsException extends Exception {

    public MaxAttemptsException(int numAttemptsAllowed) {
        super("\nYou have exceed the max amount of attempts,"
                + numAttemptsAllowed + ", that you are allowed to enter. The "
                + "program will now exit.\n");
    }
}
