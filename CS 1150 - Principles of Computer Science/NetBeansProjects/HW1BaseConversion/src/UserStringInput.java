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
import java.util.*;

public class UserStringInput {

    public static Scanner input = new Scanner(System.in);

    public static String getNumRep(int origBase) {
        boolean contInput = true;
        int maxAttempts = 3;
        String numRep = null;

        //gets string and checks for invalid input
        for (int i = 0; (i <= maxAttempts) & contInput; i++) {
            try {
                //throws exception for 3 invalid inputs
                if (i == maxAttempts) {
                    throw new MaxAttemptsException(maxAttempts);
                } else {
                    System.out.printf("Enter the numerical representation as a "
                            + "String:");
                    numRep = input.next();
                    //throws an exception if an invalid num rep is entered
                    for (int j = 0; j < numRep.length(); j++) {
                        if ((int) numRep.charAt(j) < 0
                                && (int) numRep.charAt(j) > (origBase - 1)) {
                            throw new InvalidNumericalRepresentationException(origBase);
                        } //throws an exception if overflow happens from num
                        // rep bring too big
                        else if (ConverterUtil.toBase10(origBase, numRep) < 0) {
                            throw new NumbericalRepresentationTooBigException();
                        } else {
                            contInput = false;
                        }
                    }
                }
            } catch (MaxAttemptsException ex) {
                System.err.println(ex.getMessage());
                input.nextLine();
            } catch (InputMismatchException ex) {
                System.err.println("\nInvalid Input. Enter an String.\n");
                input.nextLine();
            } catch (NoSuchElementException ex) {
                System.err.println("\nTry Again. No input found.\n");
                input.nextLine();
            } catch (IllegalStateException ex) {
                System.err.println("\nThere is a problem with the Scanner. Try "
                        + "again.\n");
                input.nextLine();
            } catch (InvalidNumericalRepresentationException ex) {
                System.err.println(ex.getMessage());
                input.nextLine();
            } catch (NumbericalRepresentationTooBigException ex) {
                System.err.println(ex.getMessage());
                input.nextLine();
            }
        }
        return numRep;
    }

}
