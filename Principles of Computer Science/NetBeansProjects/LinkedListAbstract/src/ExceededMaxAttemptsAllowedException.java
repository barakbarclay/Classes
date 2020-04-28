/**
 * @author Dhiraj Gharana
 * CS1450 Section 1,2
 * Homework 2
 * Date: 10/02/2017
 * ................................
 * Class: ExceededMaxAttemptsAllowedException
 */
public class ExceededMaxAttemptsAllowedException extends Exception 
{

    public ExceededMaxAttemptsAllowedException(int numAttemptsAllowed) 
    {
        super("You have exceeded the maximum number of attempts allowed to" +
                "\n" + "accept user input, which was " + numAttemptsAllowed +
                " !");
    }
    
}