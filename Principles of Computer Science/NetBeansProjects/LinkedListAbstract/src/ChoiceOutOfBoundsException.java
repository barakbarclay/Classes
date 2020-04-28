/**
 * @author Dhiraj Gharana
 * CS1450 Section 1,2
 * Homework 2
 * Date: 10/02/2017
 * ................................
 * Class: ChoiceOutOfBoundsException
 */
public class ChoiceOutOfBoundsException extends Exception
{

    public ChoiceOutOfBoundsException(int choice) 
    {
        super("Choice " + choice + " is NOT a Valid Choice from"
                + " among the choices in the Menu!");
    }
    
}