public class PoppingEmptyStackException extends Exception
{
    public PoppingEmptyStackException()
    {
        super("Error! Trying to Pop from an Empty Stack!");
    }    
}