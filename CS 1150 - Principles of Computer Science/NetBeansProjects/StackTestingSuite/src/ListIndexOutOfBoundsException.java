public class ListIndexOutOfBoundsException extends Exception
{

    public ListIndexOutOfBoundsException(int index, int listSize)
    {
        super("Error! Invalid Index in Linked List,\nIndex = " +
                index + " , List Size = " + listSize + "!");
    }    
}