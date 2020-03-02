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

public class UserBaseInput {
    
    public static Scanner input = new Scanner(System.in);
    
    public static int getBase(boolean orig){
        boolean contInput = true;
        int maxAttempts = 3;
        int base = 0;
        
        //gets orignal base and checks for invalid user input
        for (int i = 0; (i <= maxAttempts) & contInput; i++) {
            try {
                //throws exception for 3 invalid inputs
                if (i == maxAttempts) {
                    throw new MaxAttemptsException(maxAttempts);
                } else {
                    //prints a different line based on the method call
                    if (orig){
                    System.out.printf("Enter the orignal base as a number "
                            + "between 2 and 36, both inclusive:");
                    }
                    else {
                        System.out.printf("Enter the new base as a number "
                                + "between 2 and 36, both inclusive:");
                    }
                    base = input.nextInt();
                    //throws an exception if the base is not between 2 & 36
                    if ((base < 2) || (base > 36)) {
                        throw new InputOutOfBoundsException(2, 36);
                    } else {
                        contInput = false;
                    }
                }
            } catch (MaxAttemptsException ex) {
                System.err.println(ex.getMessage());
                input.nextLine();
            } catch (InputOutOfBoundsException ex) {
                System.err.println(ex.getMessage());
                input.nextLine();
            } catch (InputMismatchException ex) {
                System.err.println("\nInvalid Input. Enter an Integer.\n");
                input.nextLine();
            } catch (NoSuchElementException ex) {
                System.err.println("\nTry Again. No input found.\n");
                input.nextLine();
            } catch (IllegalStateException ex) {
                System.err.println("\nThere is a problem with the Scanner. Try "
                        + "again.\n");
                input.nextLine();
            }
        }
        return base;
    }
}
