public class StackTester<T>
{
    private final StackAbstract<T> stack;
    private final UserInput<T> userInput;
    private Node<T> top;
    
    public StackTester(StackAbstract<T> stack, UserInput<T> userInput)
    {
        if((stack == null)||(userInput == null))
        {
            throw new NullPointerException();
        }        
        this.stack = stack;
        this.userInput = userInput;
    }

    public StackAbstract<T> getStack()
    {
        return stack;
    }

    public UserInput<T> getUserInput()
    {
        return userInput;
    }
}