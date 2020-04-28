/**
 * @author Dhiraj Gharana
 * CS1450 Section 1,2
 * Homework 2
 * Date: 10/02/2017
 * ................................
 * Class: Node
 */
import java.util.Objects;


public class Node<T> 
{
    private T value;
    private Node<T> next;

    public Node() 
    {
        super();
    }
    
    public Node(T value) 
    {
        this();
        this.value = value;
    }

    public T getValue()
    {
        return this.value;
    }

    public void setValue(T value)
    {
        this.value = value;
    }

    public Node<T> getNext()
    {
        return this.next;
    }

    public Node<T> setNext(Node<T> next)
    {
        this.next = next;
        return this.next;
    } 
    
    public boolean hasSameValue(Node<T> otherNode)
    {
        if(this.value.equals(otherNode.getValue()))
        {
            return true;
        }
        return false;
    }
    
    @Override
    public String toString()
    {
        return this.value.toString();
    }
    
    @Override
    public boolean equals(Object o)
    {
        try
        {
            Node<T> nodeObject = (Node<T>) o;
            if((nodeObject.getValue().equals(this.value))&&
                    (nodeObject.getNext() == this.next))
            {
                return true;
            }
            return false;
        }
        catch(Exception e)
        {
            return false;
        }                
    }

    @Override
    public int hashCode() 
    {
        int hash = 5;
        hash = 43 * hash + Objects.hashCode(this.value);
        hash = 43 * hash + Objects.hashCode(this.next);
        return hash;
    }
}