/**
 * @author Dhiraj Gharana
 * CS1450 Section 1,2
 * Homework 2
 * Date: 10/02/2017
 * ................................
 * Class: UnsupportedMenuChoiceException
 */
public class UnsupportedMenuChoiceException extends Exception
{

    public UnsupportedMenuChoiceException(String methodName, int menuChoice)
    {
        super("The " + methodName +
                "() method doesn't support the Menu choice: " + menuChoice);
    }
    
}