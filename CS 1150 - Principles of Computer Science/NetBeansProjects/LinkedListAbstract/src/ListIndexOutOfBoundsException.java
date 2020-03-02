/**
 * @author Dhiraj Gharana
 * CS1450 Section 1,2
 * Homework 2
 * Date: 10/02/2017
 * ................................
 * Class: ListIndexOutOfBoundsException
 */
public class ListIndexOutOfBoundsException extends Exception
{

    public ListIndexOutOfBoundsException(int index, int listSize)
    {
        super("Error! Invalid Index in Linked List,\nIndex = " +
                index + " , List Size = " + listSize + "!");
    }    
}