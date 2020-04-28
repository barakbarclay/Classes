public class BarclayFrontStack<T> extends StackAbstract<T>
{

    //Since you extend StackAbstract
    //and StackAbstract takes a Linked List argument in its constructor
    //you have to write this constructor.
    public BarclayFrontStack(LinkedListAbstract list)
    {
        super(list);
    }
    
    //put new element on the top of the Stack
    @Override
    public void push(T value)
    {
        list.add(0, value);        
    }

    //take the top element out of the Stack
    //and return its value
    @Override
    public T pop()
            throws PoppingEmptyStackException
    {
        if(list.isEmpty())
        {
            throw new PoppingEmptyStackException();
        }
        T returnValue = list.remove(0);        
        return returnValue;
    }

    //Observe the value of the top of the Stack
    //without removing it from the Stack
    @Override
    public T peek()
    {
        return list.get(0);
    }
}