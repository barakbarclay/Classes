public class UnsupportedInputException extends Exception
{

    public UnsupportedInputException(Object o)
    {
        super("This Linked List does not support Nodes with " +
                o.getClass().getName() + " values!");
    }
    
}