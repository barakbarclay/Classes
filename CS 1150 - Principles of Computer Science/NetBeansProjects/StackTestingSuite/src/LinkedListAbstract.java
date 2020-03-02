import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Objects;

public class LinkedListAbstract<T> 
{
    protected Node<T> head; 
		
    /***************************************************************
    **************You Have to Override this Method*****************
    * You can't use the exact same code as below.
    ****************************************************************
    * Returns the number of elements in this list. 
    * If this list contains more than Integer.MAX_VALUE elements,
    * returns Integer.MAX_VALUE. 
    * Returns: the number of elements in this list
    * 
    public abstract int size();
     * @return size the number (integer) of Nodes in the Linked List
    ****************************************************************/    
    public int size()
    {
        if(isEmpty())
        {
            return 0;
        }
        Iterator<T> iterator = this.iterator();
        int count = 0;
        while(iterator.hasNext())
        {
            iterator.next();
            count++;
        }
        return count; 
    }    
    
    /***************************************************************
    **************You Don't Have to Override this Method*****************
    * You can use the exact same code as below.
    ****************************************************************
    * Returns true if this list contains no elements.   
    * 
    public abstract boolean isEmpty();
     * @return true if this list contains no elements, else false
    ****************************************************************/    
    public boolean isEmpty()
    {
        return head == null;
    } 

    /***************************************************************
    **************You Have to Override this Method*****************
    * You can't use the exact same code as below.
    ****************************************************************
    * Inserts the specified element at the specified position in
    * this list (optional operation). 
    Shifts the element currently at that
    * position (if any) and any subsequent elements to the right
    * (adds one to their indices).
    * Parameters: index index at which the specified element
     is to be inserted
    * element element to be inserted
    * Throws: java.lang.UnsupportedOperationException if the add
    * operation is not supported by this list
    * java.lang.ClassCastException if the class of the specified
    * element prevents it from being added to this list
    * java.lang.NullPointerException if the specified
     element is null
    * and this list does not permit null elements
    * java.lang.IllegalArgumentException if some property of the
    * specified element prevents it from being added to this list
    * java.lang.IndexOutOfBoundsException
     if the index is out of range
    * (index < 0 || index > size())

    public abstract void add(int index, E element);
     * @param index index at which the specified element
                is to be inserted
     * @param value value of Node to be inserted
    ****************************************************************/    
    public void add(int index, T value)
    {
        if(value == null)
        {
            throw new NullPointerException();
        }
        Node<T> newNode = new Node<>();
        newNode.setValue(value);
        if(index == 0)
        {
            newNode.setNext(head);
            head = newNode;
        }        
        else
        {
            Node<T> previousNode = getNode(index - 1);            
            newNode.setNext(previousNode.getNext());
            previousNode.setNext(newNode);
        }        
    }    
    
    /***************************************************************
    **************You Have to Override this Method*****************
    * You can have very similar code to the one below.
    ****************************************************************
    * Appends the specified element to the end of this list
    * (optional operation). 
    * Lists that support this operation may place limitations
    * on what elements may be added to this list. In particular,
    * some lists will refuse to add null elements, and others will
    * impose restrictions on the type of elements that may be added.
    * List classes should clearly specify in their documentation any
    * restrictions on what elements may be added.
    * Parameters: e element to be appended to this list
    * Returns: true 
    (as specified by Collection.add(java.lang.Object))
    * Throws:
    * java.lang.UnsupportedOperationException if the add
     operation is not
    * supported by this list
    * java.lang.ClassCastException if the class of the specified
    * element prevents it from being added to this list
    * java.lang.NullPointerException if the specified element
    * is null and this list does not permit null elements
    * java.lang.IllegalArgumentException if some property of this
    * element prevents it from being added to this list

    public abstrct boolean add(E e);
     * @param value value of Node to be appended to this list
     * @return returns true if successful
    ****************************************************************/    
    public boolean add(T value)
    {
        int oldSize = size();
        add(oldSize, value);
        int newSize = size();
        if(newSize == oldSize + 1)
        {
            return true;
        }
        return false;
    }

    /***************************************************************
    **************You Have to Override this Method*****************
    * You can't use the exact same code as below.
    ****************************************************************
    * Removes the element at the specified position in this list
    * (optional operation).
    * Shifts any subsequent elements to the left
    * (subtracts one from their indices).
    * Returns the element that was removed from the list.
    * Parameters: index the index of the element to be removed
    * Returns: the element previously at the specified position
    * Throws: java.lang.UnsupportedOperationException if the remove
    * operation is not supported by this list
    * java.lang.IndexOutOfBoundsException
     if the index is out of range
    * (index < 0 || index >= size())
    public abstract E remove(int index);
     * @param index the index of the Node to be removed
     * @return the value of the Node previously at the specified position
    ****************************************************************/   
    public T remove(int index)
    {
        Node<T> previousNode;
        Node<T> nodeToRemove = getNode(index);
        if(index == 0)
        {
            head = nodeToRemove.getNext();
        }
        else
        {
            previousNode = getNode(index - 1);
            previousNode.setNext(nodeToRemove.getNext());
        }        
        nodeToRemove.setNext(null);
        return nodeToRemove.getValue();
    }
    
    /***************************************************************
    **************You Have to Override this Method*****************
    * You can't use the exact same code as below.
    ****************************************************************
    * Removes the first occurrence of the specified element
     from this list,
    * if it is present (optional operation).
    * If this list does not contain the element,
    * it is unchanged. More formally, removes the element
     with the lowest index i such that
      (o==null ? get(i) == null: o.equals(get(i)))
    * (if such an element exists).
    * Returns true if this list contained the specified element
    * (or equivalently, if this list changed as a result of
     the call).
    * Parameters: o element to be removed from this list,
     if present
    * Returns: true if this list contained the
     specified element
    * Throws:
    * java.lang.ClassCastException if the type of the
     specified element
    * is incompatible with this list (optional)
    * java.lang.NullPointerException if the specified
     element is null
    * and this list does not permit null elements
     (optional)
    * java.lang.UnsupportedOperationException if
     the remove operation
    * is not supported by this list

    public abstract boolean remove(Object o);
     * @param o value of Node to be removed from this list, if present
     * @return true if this list contained the specified element
    ****************************************************************/    
    public boolean remove(Object o)
            throws ClassCastException,
            NullPointerException
    {
        if(o == null)
        {
            throw new NullPointerException();
        }
        T valueToRemove = (T) o;
        Iterator<T> iter = this.iterator();
        int counter = 0;
        while(iter.hasNext())
        {
            if(iter.next().equals(valueToRemove))
            {
                remove(counter);
                return true;
            }
            else
            {
                counter++;
            }
        }
        return false;
    }
    
    /***************************************************************
     **************You Have to Override this Method*****************
     * You can't use the exact same code as below.
     ****************************************************************
     * Returns the element at the specified position in this list.
     * Parameters: index index of the element to return
     * Returns: the element at the specified position in this list
     * Throws: java.lang.IndexOutOfBoundsException if the index is out
     * of range (index < 0 || index >= size())
    public abstract E get(int index);
     * @param index index of the element to return
     * @return the element at the specified position in this list
     ****************************************************************/    
    public T get(int index) throws IndexOutOfBoundsException 
    {
        return getNode(index).getValue();
    }
    
    /***************************************************************
    **************You Have to Override this Method*****************
    * You can't use the exact same code as below.
    ****************************************************************
    * Replaces the element at the specified position in this list
    * with the specified element (optional operation).
    * Parameters: index index of the element to replace
    * element element to be stored at the specified position
    * Returns: the element previously at the specified position
    * Throws: java.lang.UnsupportedOperationException
     if the set operation
    * is not supported by this list
    * java.lang.ClassCastException if the class
     of the specified element
    * prevents it from being added to this list
    * java.lang.NullPointerException if the specified element is
    * null and this list does not permit null elements
    * java.lang.IllegalArgumentException if some property of the
    * specified element prevents it from being added to this list
    * java.lang.IndexOutOfBoundsException if the
     index is out of range
    * (index < 0 || index >= size())

    public abstract E set(int index, E element);
     * @param index index of the Node whose value is to be modified.
     * @param value the new value to assign to the Node
     * @return The old value of the Node
    ****************************************************************/    
    public T set(int index, T value)
            throws IndexOutOfBoundsException
    {
        if(value == null)
        {
            throw new NullPointerException();
        }
        Node<T> node = getNode(index);
        T oldValue = node.getValue();
        node.setValue(value);
        return oldValue;
    }
    
    /***************************************************************
    **************You Have to Override this Method*****************
    * You can use code similar to the one below.
    ****************************************************************
    * Removes all of the elements from this list (optional operation).
    * The list will be empty after this call returns. 
    * Throws: java.lang.UnsupportedOperationException
     if the clear operation
    * is not supported by this list

    public abstract void clear();
    ****************************************************************/    
    public void clear()
    {
        int originalSize = size();
        for(int i = 0; i < originalSize; i++)
        {
            remove(0);
        }
    } 
    
    /***************************************************************
    **********You Can Implement this Method for a Bonus*************
    * For Bonus, You can't use the exact same code as below.
    ****************************************************************
    * Returns the index of the first occurrence
     of the specified element
    * in this list, or -1 if this list does not contain the element.
    * More formally, returns the lowest index i such that
    * (o == null ? get(i) == null : o.equals(get(i))),
    * or -1 if there is no such index.
    * Parameters: o element to search for
    * Returns: the index of the first
     occurrence of the specified element
    * in this list, or -1 if this list does not contain the element
    * Throws: java.lang.ClassCastException
     if the type of the specified
    * element is incompatible with this list (optional)
    * java.lang.NullPointerException if the specified element
    * is null and this list does not permit
     null elements (optional)

    public abstract int indexOf(Object o);
     * @param o
     * @return 
    ****************************************************************/    
    public int indexOf(Object o)
    {
        if(o == null)
        {
            throw new NullPointerException();
        }
        T valueToSearch = (T) o;
        Iterator<T> iter = this.iterator();
        int counter = 0;
        while(iter.hasNext())
        {
            if(iter.next().equals(valueToSearch))
            {
                return counter;
            }
            else
            {
                counter++;
            }
        }
        return -1;
    }
    
    /***************************************************************
    **********You Can Implement this Method for a Bonus*************
    * For Bonus, You can't use the exact same code as below.
    ****************************************************************	
    * Returns the index of the last occurrence
     of the specified element
    * in this list, or -1 if this list does not contain the element.
    * More formally, returns the highest index i such that
    * (o == null ? get(i) == null : o.equals(get(i));
    * or -1 if there is no such index.
    * Parameters: o element to search for
    * Returns: the index of the last occurrence
     of the specified element
    * in this list, or -1 if this list does not contain the element
    * Throws: java.lang.ClassCastException
     if the type of the specified
    * element is incompatible with this list (optional)
    * java.lang.NullPointerException
     if the specified element is null
    * and this list does not permit null elements (optional)

    public abstract int lastIndexOf(Object o);
     * @param o
     * @return 
    ****************************************************************/   
    public int lastIndexOf( Object o)
    {
        if(o == null)
        {
            throw new NullPointerException();
        }
        T valueToSearch = (T) o;
        Iterator<T> iter = this.iterator();
        int counter = 0;
        int max = -1;
        while(iter.hasNext())
        {
            if(iter.next().equals(valueToSearch))
            {
                max = counter;
            }
            counter++;
        }
        return max;
    }
    
    /***************************************************************
    **********You Can Implement this Method for a Bonus*************
    * For Bonus, You can't use the exact same code as below at the
    * end of these comments.
    * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    * Remember that when you implement this method, it has to 
    * return an object of type LinkedListAbstract, but of object instantiation
    * of your Class;
    * Like,
    * LinkedListAbstract<T> list = new YourLastNameLinkedList<>();    
    ****************************************************************
    * Returns a view of the portion of this list between the
    * specified fromIndex, inclusive, and toIndex, exclusive.
    * (If fromIndex and toIndex are equal, the returned list is empty.)
    * The returned list is backed by this list,
    * so non-structural changes in the returned list are reflected
    * in this list, and vice-versa.
    * The returned list supports all of the optional list operations
    * supported by this list.
    * This method eliminates the need for explicit range operations
    * (of the sort that commonly exist for arrays).
    * Any operation that expects a list
     can be used as a range operation
    * by passing a subList view instead of a whole list.
    * For example, the following idiom removes a range
    * of elements from a list: 
    * list.subList(from, to).clear();
    * Similar idioms may be constructed
     for indexOf and lastIndexOf,
    * and all of the algorithms in the Collections class
    * can be applied to a subList.
    * The semantics of the list returned
     by this method become undefined
    * if the backing list (i.e., this list) is structurally modified
    * in any way other than via the returned list.
    * (Structural modifications are those
     that change the size of this list,
    * or otherwise perturb it in such
     a fashion that iterations in progress
    * may yield incorrect results.)
    * Parameters: fromIndex low endpoint (inclusive) of the subList
    * toIndex high endpoint (exclusive) of the subList
    * Returns: a view of the specified range within this list
    * Throws: java.lang.IndexOutOfBoundsException
     for an illegal endpoint index value
     (fromIndex < 0 || toIndex > size || fromIndex > toIndex)

    public abstract List<E> subList(int fromIndex, int toIndex);
    * 
     * @param fromIndex
     * @param toIndex
     * @return 
    ****************************************************************/    
    public LinkedListAbstract<T> subList(int fromIndex, int toIndex)
    {
        LinkedListAbstract<T> retSubList = new LinkedListAbstract<>();
        Iterator<T> iter = this.iterator();
        int count = 0;
        while(iter.hasNext())
        {
            if(count >= fromIndex)
            {
                if(count >= toIndex)
                {
                    break;
                }
                retSubList.add(iter.next());
            }
            else
            {
                iter.next();
            }
            count++;
        }
        return retSubList;
    }
    
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    //You Don't Have to Implement Any of the Methods Below:
    //But you can use them in your implementation
    //Except for the getNode() method........
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    
    //Overriding the toString() Method of Object
    /**
    //With this, we can directly print out our linked list with
    //System.out.println(list);
     * @return 
    */
    @Override
    public String toString()
    {
        String listString = "";
        if(!isEmpty())
        {
            Iterator<T> iter = this.iterator();
            listString += "head -> ";
            while(iter.hasNext())
            {
                listString += iter.next() + " -> ";
            } 
            listString += "null";            
        }        
        else
        {
            listString += "The Linked List is Empty!";            
        }
        return listString;
    }
    
        /**
     * Added Method for ease of accessing any Node at any given position
     * within the Linked List.
     * This is not a method of the List Interface
     * @param index the position of the Node to access/get.
     * @return a reference to the Node at position index in the list.
     * @throws IndexOutOfBoundsException 
     */
//    public Node<T> getNode(int index)
//            throws IndexOutOfBoundsException
//    {
//        if((index < 0)||(index >= size()))
//        {
//            throw new IndexOutOfBoundsException();
//        }
//        else
//        {            
//            Node<T> current = head;
//            for(int i = 0; (i < index) && (
//                    current != null && current.getNext() != null); i++)
//            {
//                current = current.getNext();
//            }
//            return current;
//        }
//    }
    
    public Node<T> getNode(int index)
            throws IndexOutOfBoundsException
    {
        if((index < 0)||(index >= size()))
        {
            throw new IndexOutOfBoundsException();
        }
        else
        {            
            NodeIterator<T> nodeIter = this.nodeIterator();
            Node<T> retNode = null;
            for(int i = 0; (i < (index+1)) && 
                    (nodeIter.hasNext()); i++)
            {
                retNode = nodeIter.next();
            }
            return retNode;
        }
    }
    
    /****************************************************************
    * Returns true if this list contains the specified element.
    * More formally, returns true if and only if this list contains
    * at least one element e such that
     (o==null ? e==null: o.equals(e)).
    * Parameters: o element whose presence in this list
     is to be tested
    * Returns: true if this list contains the specified element
    * Throws: java.lang.ClassCastException if the type of
     the specified
    * element is incompatible with this list (optional)
    * java.lang.NullPointerException if the specified
     element is null
    * and this list does not permit null elements (optional)
    * 
    public abstract boolean contains(Object o);
     * @param o
     * @return 
    ****************************************************************/
    //@Override
    public boolean contains(Object o)
    {
        if(o == null)
        {
            throw new NullPointerException();
        }
        try
        {
            T searchVal = (T) o;
            Iterator<T> iter = this.iterator();
            while(iter.hasNext())
            {
                if((iter.next() == searchVal)||
                        (iter.next().equals(searchVal)))
                {
                    return true;
                }
            }
            return false;
        }
        catch(ClassCastException e)
        {
            throw e;
        }        
    }
    
    public void swap(int index)
            throws ListIndexOutOfBoundsException
    {
        if((index <= -1)||(index >= (size()- 1)))
        {
            throw new ListIndexOutOfBoundsException(index, size());
        }
        Node<T> current = head;
        Node<T> temp = head;
        for(int i = 0; i < index-1; i++)
        {
            current = current.getNext();
            temp = current.getNext();
        }
        temp = temp.getNext();
        (current.getNext()).setNext(temp.getNext());
        temp.setNext(current.getNext());
        current.setNext(temp);
    }
    
    /****************************************************************
    * Returns an array containing all of the elements
     in this list in proper sequence
      (from first to last element).
    * The returned array will be "safe" in that no references
    * to it are maintained by this list.
     (In other words, this method must allocate a new array
      even if this list is backed by an array).
    * The caller is thus free to modify the returned array.
    * This method acts as bridge between array-based and
     collection-based APIs.
    * Returns: an array containing all of the elements in this 
    * list in proper sequence

    public abatract Object[] toArray();
     * @return 
    ****************************************************************/
    //@Override
    public Object[] toArray()
    {
        Object[] retArray = new Object[size()];
        Iterator<T> iter = this.iterator();
        int counter = 0;
        while(iter.hasNext())
        {
            retArray[counter] = iter.next();
            counter++;
        }
        return retArray;
    }
    
    /****************************************************************
    * Returns an iterator over the elements in this
     list in proper sequence.
    * Returns:
    * an iterator over the elements in this
     list in proper sequence
    * 
    public abstract Iterator<E> iterator();
     * @return an iterator over the Node values in this
            linked list in proper sequence
    ****************************************************************/    
    public Iterator<T> iterator()
    {
        return new MyIterator<>();
    }
    
    public NodeIterator<T> nodeIterator()
    {
        return new NodeIterator<>();
    } 
    
    /**
     * The MyIterator Inner Class
     */
    private class MyIterator<E> implements Iterator<E> 
    {
        private Node<E> currentNode;       

        public MyIterator()               
        {
            super();
            this.currentNode =  null;                   
        }       
        
        @Override
        public boolean hasNext() 
        {
            if(this.currentNode == null)
            {
                if(head != null)
                {
                    return true;
                }
                return false;
            }
            if (this.currentNode != null && this.currentNode.getNext() != null)
            {
                return true;
            }                
            return false;                
        }     
        
        @Override
        public E next() 
        {
            if (!hasNext())
            {
                throw new NoSuchElementException();
            }
            if(this.currentNode == null)
            {
                this.currentNode = (Node<E>) head;               
                return this.currentNode.getValue();
            }            
            this.currentNode = this.currentNode.getNext();            
            return currentNode.getValue();                      
        }  
        
        @Override
        public void remove()
                throws UnsupportedOperationException
        {
            throw new UnsupportedOperationException();
        }
    } 
    
    /**
     * The NodeIterator Inner Class
     */
    private class NodeIterator<E>  
    {
        private Node<E> currentNode;       

        public NodeIterator()               
        {
            super();
            this.currentNode =  null;                   
        }      
        
        public boolean hasNext() 
        {
            if(this.currentNode == null)
            {
                if(head != null)
                {
                    return true;
                }
                return false;
            }
            if (this.currentNode != null && this.currentNode.getNext() != null)
            {
                return true;
            }                
            return false;                
        }        
        
        public Node<E> next() 
        {
            if (!hasNext())
            {
                throw new NoSuchElementException();
            }
            if(this.currentNode == null)
            {
                this.currentNode = (Node<E>) head;               
                return this.currentNode;
            }            
            this.currentNode = this.currentNode.getNext();            
            return currentNode;                      
        }
    }
    
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    //Overriding Other Methods of Object

    /****************************************************************
     * Compares the specified object with this list for equality.
     * Returns true if and only if the specified object is also a list,
     * both lists have the same size, and all
    corresponding pairs of elements
     * in the two lists are equal.
     * (Two elements e1 and e2 are equal
     * if (e1==null ? e2==null : e1.equals(e2)).)
     * In other words, two lists are defined to be equal if they contain
     * the same elements in the same order.
     * This definition ensures that the equals method works properly
     * across different implementations of the List interface.
     * Parameters: o the object to be compared
    for equality with this list
     * Returns: true if the specified object is equal to this list
    public abstract boolean equals(Object o);
     * @return 
     ****************************************************************/
    @Override
    public boolean equals(Object obj) 
    {
        if (this == obj) 
        {
            return true;
        }
        if (obj == null) 
        {
            return false;
        }
        if (getClass() != obj.getClass()) 
        {
            return false;
        }
        final LinkedListAbstract<?> other = (LinkedListAbstract<?>) obj;
        if (!Objects.equals(this.head, other.head)) 
        {
            return false;
        }
        return true;
    }
    
    /****************************************************************
     * Returns the hash code value for this list.
     * The hash code of a list is defined to be the result
     * of the following calculation:
     * int hashCode = 1;
     * for (E e : list)
     * hashCode = 31*hashCode + (e==null ? 0 : e.hashCode());
     * This ensures that list1.equals(list2) implies that
     * list1.hashCode()==list2.hashCode() for
    any two lists, list1 and list2,
     * as required by the general contract
    of java.lang.Object.hashCode().
     * Returns: the hash code value for this list
    public abstract int hashCode();
     * @return 
     ****************************************************************/
    @Override
    public int hashCode()
    {
        int hash = 7;
        hash = 89 * hash + Objects.hashCode(this.head);
        return hash;
    }    
}