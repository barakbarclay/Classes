/**
 * @author Dhiraj Gharana
 * CS1450 Section 1,2
 * Homework 2
 * Date: 10/02/2017
 * ................................
 * Class: UnsupportedInputException
 */
public class UnsupportedInputException extends Exception
{

    public UnsupportedInputException(Object o)
    {
        super("This Linked List does not support Nodes with " +
                o.getClass().getName() + " values!");
    }
    
}