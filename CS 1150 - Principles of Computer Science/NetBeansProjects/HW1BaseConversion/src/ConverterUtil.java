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

public class ConverterUtil {

    //returns number representation for new base
    public static String convertBetweenBases(int origBase, String numRep,
            int newBase) {
        return toNewNumRep(newBase, toBase10(origBase, numRep));
    }

    //converts number representation to a base 10 number 
    public static int toBase10(int base, String numRep) {
        int numRepInBase10 = 0;
        int value;
        for (int i = numRep.length() - 1; i > -1; i--) {
            if (Character.isDigit(numRep.charAt(i))) {  //for numbers
                value = (int) numRep.charAt(i) - 48;
                //for lowercase letters
            } else {
                value = (int) numRep.charAt(i) - 87;
                //for upercase letters
                if (value < 10) {
                    value += 32;
                }
            }
            numRepInBase10 += Math.pow(base, numRep.length() - i - 1) * value;
        }
        return numRepInBase10;
    }

    //converts number representaion from base 10 to the new base
    public static String toNewNumRep(int base, int numRep) {
        String newNumRep = "";
        int numOfRemainders = 0;
        int numRepCopy = numRep;
        
        //gets the length of the array
        while (numRepCopy != 0) {
            numRepCopy = numRepCopy / base;
            numOfRemainders++;
        }
        
        //creates array and fills it with the values of the num representations
        int valuesOfNewNumRep[] = new int[numOfRemainders];
        for (int i = 0; numRep != 0; i++) {
            valuesOfNewNumRep[numOfRemainders -1 - i] = numRep % base;
            numRep = numRep / base;
        }
        
        //converts values of num rep to letters where need be
        for (int i = 0; i < numOfRemainders; i++){
            if (valuesOfNewNumRep[i] < 10) {
                newNumRep += valuesOfNewNumRep[i];
            } else {
                valuesOfNewNumRep[i] += 55;
                newNumRep += (char) (valuesOfNewNumRep[i]);
            }
        }
        
        return newNumRep;
    }
}
