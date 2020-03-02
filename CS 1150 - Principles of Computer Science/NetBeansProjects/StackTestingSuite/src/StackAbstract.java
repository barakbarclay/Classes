public abstract class StackAbstract<T>
{
    protected LinkedListAbstract<T> list;
    
    private Node<T> top;

    public StackAbstract(LinkedListAbstract list)
    {
            if(list == null)
            {
                    throw new NullPointerException();
            }
            this.list = list;
    }

    //put new element on the top of the Stack
    public abstract void push(T value);		

    //take the top element out of the Stack
    //and return its value    
    public abstract T pop() throws PoppingEmptyStackException;

    //Observe the value of the top of the Stack
    //without removing it from the Stack
    public abstract T peek();
    
    //----------------------------------------------------------------------
    
    //Overrides method of Object class
    //This is only to facilitate printing the Stack
    //using System.out.println(theStack);
    //and it will visually display the Stack.
    @Override
    public String toString()
    {
        if(list.isEmpty())
        {
            return "The Stack is Empty!";
        }
        String retString = "--------------------------------------------\n" +
                "The Stack is Shown Below:\n";        
        if(top == list.getNode(0))
        {
            for(int i = 0; i < list.size(); i++)
            {
                retString += list.get(i) + "\n";
            }
        }
        else
        {
            for(int i = (list.size() -1); i > -1; i--)
            {
                retString += list.get(i) + "\n";
            }
        }
        retString += "--------------------------------------------";
        return retString;
    }

    public Node<T> getTop() 
    {
        return top;
    }

    public void setTopFront()
    {
        if(!list.isEmpty())
        {
            this.top = this.list.getNode(0);
        }
        else
        {
            this.top = null;
        }
    }
    
    public void setTopEnd()
    {
        if(!list.isEmpty())
        {
            this.top = this.list.getNode(this.list.size()-1);
        }
        else
        {
            this.top = null;
        }
    }
}