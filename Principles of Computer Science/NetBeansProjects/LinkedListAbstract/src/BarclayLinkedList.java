/*
 * Barak Barclay
 * CS1450.002
 * HW1BaseConversion
 * 10/06/17
 * This clas extends the given LinkedListAbstract class. It Overrides the size, 
 * isEmpty(), add(E e), remove(Object o), clear(), E get(int index), E set(int 
 * index, E element), add(int index, E element), and E remove(int index) 
 * methods from the LinkedListAbstract class.
 */
public class BarclayLinkedList<T> extends LinkedListAbstract<T> {

    /**
     * *************************************************************
     ****************************************************************
     * Returns the number of elements in this list. If this list contains more
     * than Integer.MAX_VALUE elements, returns Integer.MAX_VALUE. Returns: the
     * number of elements in this list
     *
     * public abstract int size();
     *
     * @return size the number (integer) of Nodes in the Linked List
     * **************************************************************
     */
    @Override
    public int size() {
        if (isEmpty()) {
            return 0;
        }
        Node<T> current = head;
        int count = 1;
        while (current.getNext() != null) {
            current = current.getNext();
            count++;
        }
        return count;
    }

    /**
     * *************************************************************
     ****************************************************************
     * Inserts the specified element at the specified position in this list
     * (optional operation). Shifts the element currently at that position (if
     * any) and any subsequent elements to the right (adds one to their
     * indices). Parameters: index index at which the specified element is to be
     * inserted element element to be inserted Throws:
     * java.lang.UnsupportedOperationException if the add operation is not
     * supported by this list java.lang.ClassCastException if the class of the
     * specified element prevents it from being added to this list
     * java.lang.NullPointerException if the specified element is null and this
     * list does not permit null elements java.lang.IllegalArgumentException if
     * some property of the specified element prevents it from being added to
     * this list java.lang.IndexOutOfBoundsException if the index is out of
     * range (index < 0 || index > size())
     *
     * public abstract void add(int index, E element);
     *
     * @param index index at which the specified element is to be inserted
     * @param value value of Node to be inserted
     * **************************************************************
     */
    @Override
    public void add(int index, T value) {
        if (value == null) {
            throw new NullPointerException();
        }
        Node<T> newNode = new Node<>();
        newNode.setValue(value);
        if (index == 0) {
            newNode.setNext(head);
            head = newNode;
        } else {
            Node<T> current = head;
            for (int i = 0; i < (index - 1)
                    && (current.getNext() != null); i++) {
                current = current.getNext();
            }
            newNode.setNext(current.getNext());
            current.setNext(newNode);
        }
    }

    /**
     * *************************************************************
     ****************************************************************
     * Appends the specified element to the end of this list (optional
     * operation). Lists that support this operation may place limitations on
     * what elements may be added to this list. In particular, some lists will
     * refuse to add null elements, and others will impose restrictions on the
     * type of elements that may be added. List classes should clearly specify
     * in their documentation any restrictions on what elements may be added.
     * Parameters: e element to be appended to this list Returns: true (as
     * specified by Collection.add(java.lang.Object)) Throws:
     * java.lang.UnsupportedOperationException if the add operation is not
     * supported by this list java.lang.ClassCastException if the class of the
     * specified element prevents it from being added to this list
     * java.lang.NullPointerException if the specified element is null and this
     * list does not permit null elements java.lang.IllegalArgumentException if
     * some property of this element prevents it from being added to this list
     *
     * public abstrct boolean add(E e);
     *
     * @param value value of Node to be appended to this list
     * @return returns true if successful
     * **************************************************************
     */
    public boolean add(T value) {
        int oldSize = size();
        add(oldSize, value);
        int newSize = size();
        if (newSize == oldSize + 1) {
            return true;
        }
        return false;
    }

    /**
     * *************************************************************
     ****************************************************************
     * Removes the element at the specified position in this list (optional
     * operation). Shifts any subsequent elements to the left (subtracts one
     * from their indices). Returns the element that was removed from the list.
     * Parameters: index the index of the element to be removed Returns: the
     * element previously at the specified position Throws:
     * java.lang.UnsupportedOperationException if the remove operation is not
     * supported by this list java.lang.IndexOutOfBoundsException if the index
     * is out of range (index < 0 || index >= size()) public abstract E
     * remove(int index);
     *
     * @param index the index of the Node to be removed
     * @return the value of the Node previously at the specified position
     * **************************************************************
     */
    @Override
    public T remove(int index) {
        T retVal = null;
        Node<T> current = head;
        Node<T> previous = current;
        for (int i = 0; (i < index)
                && (current.getNext() != null); i++) {
            previous = current;
            current = current.getNext();
        }
        if (index == 0) {
            retVal = head.getValue();
            head = current.getNext();
        } else {
            retVal = current.getValue();
            previous.setNext(current.getNext());
            current.setNext(null);
        }
        return retVal;
    }

    /**
     * *************************************************************
     ****************************************************************
     * Removes the first occurrence of the specified element from this list, if
     * it is present (optional operation). If this list does not contain the
     * element, it is unchanged. More formally, removes the element with the
     * lowest index i such that (o==null ? get(i) == null: o.equals(get(i))) (if
     * such an element exists). Returns true if this list contained the
     * specified element (or equivalently, if this list changed as a result of
     * the call). Parameters: o element to be removed from this list, if present
     * Returns: true if this list contained the specified element Throws:
     * java.lang.ClassCastException if the type of the specified element is
     * incompatible with this list (optional) java.lang.NullPointerException if
     * the specified element is null and this list does not permit null elements
     * (optional) java.lang.UnsupportedOperationException if the remove
     * operation is not supported by this list
     *
     * public abstract boolean remove(Object o);
     *
     * @param o value of Node to be removed from this list, if present
     * @return true if this list contained the specified element
     * **************************************************************
     */
    @Override
    public boolean remove(Object o)
            throws ClassCastException,
            NullPointerException {
        if (o == null) {
            throw new NullPointerException();
        }
        T valueToRemove = (T) o;
        Node<T> current = head;
        int counter = 0;
        while (current.getNext() != null) {
            if (current.getValue().equals(valueToRemove)) {
                remove(counter);
                return true;
            } else {
                current = current.getNext();
                counter++;
            }
        }
        return false;
    }

    /**
     * *************************************************************
     ****************************************************************
     * Returns the element at the specified position in this list. Parameters:
     * index index of the element to return Returns: the element at the
     * specified position in this list Throws:
     * java.lang.IndexOutOfBoundsException if the index is out of range (index < 0 || index
     * >= size()) public abstract E get(int index);
     *
     * @param index index of the element to return
     * @return the element at the specified position in this list
     * **************************************************************
     */
    @Override
    public T get(int index) throws IndexOutOfBoundsException {
        T reValue = null;
        Node<T> current = head;
        for (int i = 0; (i < index)
                && (current.getNext() != null); i++) {
            current = current.getNext();
        }
        return current.getValue();
    }

    /**
     * *************************************************************
     ****************************************************************
     * Replaces the element at the specified position in this list with the
     * specified element (optional operation). Parameters: index index of the
     * element to replace element element to be stored at the specified position
     * Returns: the element previously at the specified position Throws:
     * java.lang.UnsupportedOperationException if the set operation is not
     * supported by this list java.lang.ClassCastException if the class of the
     * specified element prevents it from being added to this list
     * java.lang.NullPointerException if the specified element is null and this
     * list does not permit null elements java.lang.IllegalArgumentException if
     * some property of the specified element prevents it from being added to
     * this list java.lang.IndexOutOfBoundsException if the index is out of
     * range (index < 0 || index >= size())
     *
     * public abstract E set(int index, E element);
     *
     * @param index index of the Node whose value is to be modified.
     * @param value the new value to assign to the Node
     * @return The old value of the Node
     * **************************************************************
     */
    @Override
    public T set(int index, T value)
            throws IndexOutOfBoundsException {
        if (value == null) {
            throw new NullPointerException();
        }
        T retValue = null;
        Node<T> current = head;
        for (int i = 0; (i < index)
                && (current.getNext() != null); i++) {
            retValue = current.getValue();
            current = current.getNext();
        }
        current.setValue(value);
        return retValue;
    }

    /**
     * *************************************************************
     ****************************************************************
     * Removes all of the elements from this list (optional operation). The list
     * will be empty after this call returns. Throws:
     * java.lang.UnsupportedOperationException if the clear operation is not
     * supported by this list
     */
    public void clear() {
        int originalSize = size();
        for (int i = 0; i < originalSize; i++) {
            remove(0);
        }
    }

}