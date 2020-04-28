/**
 * @author Dhiraj Gharana
 * CS1450 Section 1,2
 * Homework 2
 * Date: 10/02/2017
 * ................................
 * Class: LinkedListTester
 * @param <T>
 */
public class LinkedListTester<T> 
{
    private final LinkedListAbstract<T> list;    
    private final String studentName;  
    private final UserInput<T> userInput;
    private int menuChoice;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////    
    /**
     * @param studentName 
     * @param list 
     * @param userInput 
     * @throws java.lang.NoSuchFieldException 
     */
    public LinkedListTester(String studentName, LinkedListAbstract<T> list,
            UserInput<T> userInput)
            throws NoSuchFieldException
    {
        super();                   
        this.studentName = studentName;
        System.out.println("|||||||||||||||||||||||||||||||||||||||||||||||||");
        System.out.println();
        System.out.println("Running Test on " + this.studentName + 
                "'s Code..........");
        System.out.println();
        System.out.println("|||||||||||||||||||||||||||||||||||||||||||||||||");
        this.list = list;
        System.out.println();
        this.userInput = userInput;
    }

    public LinkedListAbstract<T> getList()
    {
        return list;
    }
    
    public UserInput<T> getUserInput()
    {
        return this.userInput;
    }

    public String getStudentName()
    {
        return studentName;
    }
    
    public void setMenuChoice()
    {
        try
        {
            this.menuChoice = this.userInput.getChoice();
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
            System.out.println();
        }
    }
    
    public void executeMenuChoice()
    {
        try
        {
            switch(menuChoice)
            {
                case 1:
                    testAdd();
                    break;
                case 2: 
                    testAppend();
                    break;
                case 3: 
                    testRemoveIndex();
                    break;
                case 4:
                    testRemoveObject();
                    break;
                case 5:
                    testGet();
                    break;
                case 6:
                    testSet();
                    break;
                case 7:
                    testClear();
                    break;
                case 8:
                    testIndexOf();
                    break;
                case 9:
                    testLastIndexOf();
                    break;
                case 10:
                    testSubList();
                    break;
                default://do nothing;                    
            }
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
    }
    
    public int getMenuChoice()
    {
        return this.menuChoice;
    }
    
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
    /**
     * To Test the add(int index, T value) method of Linked List
     * 
     */    
    public void testAdd()            
    {
        try
        {            
            System.out.println("============================================");        
            System.out.println();
            System.out.println("Testing the add(int index, T value) method\n"
                    + "on the Linked List.......");
            System.out.println();
            System.out.println("---------------------------------------");
            System.out.println();
            System.out.println("The size of the Linked List is: " + list.size());
            System.out.println();
            int index = userInput.getIndex(this.menuChoice, list.size());
            T value = (T) userInput.getValue(this.menuChoice);            
            System.out.println("Testing: list.add(" + index + ", " +
                        value + ");");
            System.out.println();
            System.out.println("Before Adding:");
            System.out.println();            
            System.out.println(list);
            System.out.println();
            System.out.println("list.size() = " + list.size());
            System.out.println(); 
            list.add(index, value);
            System.out.println("After Adding:");
            System.out.println();            
            System.out.println(list);
            System.out.println();
            System.out.println("list.size() = " + list.size());
            System.out.println();                    
            System.out.println("============================================");
            System.out.println();
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }        
    }
    
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
    /**
     * To Test the add(T value) method of Linked List
     * 
     */    
    public void testAppend()
    {
        try
        {
            String testOutput = "";       
            System.out.println("============================================");
            System.out.println();
            System.out.println("Testing the add(T value) method\n"
                    + "on the Linked List.......");
            System.out.println();
            System.out.println("---------------------------------------");
            System.out.println();
            T value = (T) userInput.getValue(this.menuChoice);
            System.out.println();
            System.out.println("Testing: list.add(" + value + ");");
            System.out.println();
            System.out.println("Before Adding:");  
            System.out.println();
            System.out.println(list);              
            System.out.println();
            System.out.println("list.size() = " + list.size());
            System.out.println(); 
            list.add(value);
            System.out.println("After Adding:");  
            System.out.println();
            System.out.println(list);
            System.out.println();            
            System.out.println("list.size() = " + list.size());
            System.out.println();                   
            System.out.println("============================================");
            System.out.println();
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }        
    }

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////  
    /**
     * To Test the remove(int index) method of Linked List  
     * 
     */    
    public void testRemoveIndex()
    {   
        try
        {                   
            System.out.println("============================================");
            System.out.println();
            System.out.println("Testing the remove(int index) method\n"
                    + "on the Linked List.......");
            System.out.println();
            System.out.println("---------------------------------------");
            System.out.println();
            int index = userInput.getIndex(this.menuChoice, list.size());
            System.out.println();
            System.out.println("Testing: list.remove(" + index + ");");
            System.out.println();
            System.out.println("Before Removing:");  
            System.out.println();
            System.out.println(list);            
            System.out.println();
            System.out.println("list.size() = " + list.size());
            System.out.println(); 
            list.remove(index);
            System.out.println("After Removing:"); 
            System.out.println();
            System.out.println(list);
            System.out.println();
            System.out.println("list.size() = " + list.size());
            System.out.println();                 
            System.out.println("============================================");
            System.out.println();            
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
            System.out.println();
        }
        
    }
    
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////  
    /**
     * To Test the remove(Object o) method of Linked List  
     * 
     */    
    public void testRemoveObject()
    {  
        try
        {                  
            System.out.println("============================================");
            System.out.println();
            System.out.println("Testing the remove(Object o) method\n"
                    + "on the Integer Linked List.......");
            System.out.println();
            System.out.println("---------------------------------------");
            T value = (T) userInput.getValue(this.menuChoice);
            System.out.println();
            System.out.println("Testing: list.remove(" + value + ");");
            System.out.println();
            System.out.println("Before Removing:");  
            System.out.println();
            System.out.println(list);            
            System.out.println();
            System.out.println("list.size() = " + list.size());
            System.out.println(); 
            list.remove(value);
            System.out.println("After Removing:"); 
            System.out.println();
            System.out.println(list);
            System.out.println();
            System.out.println("list.size() = " + list.size());
            System.out.println();                  
            System.out.println("============================================");
            System.out.println();
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
            System.out.println();
        }        
    }

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////  
    /**
     * To Test the get(int index) method of Linked List  
     * 
     */    
    public void testGet()
    { 
        try
        {                   
            System.out.println("============================================"); 
            System.out.println();
            System.out.println("Testing the get(int index) method\n"
                    + "on the Linked List.......");
            System.out.println();
            System.out.println("---------------------------------------");
            System.out.println();
            int index = userInput.getIndex(this.menuChoice, list.size());
            System.out.println();
            System.out.println("Testing: list.get(" + index + ");");
            System.out.println();
            System.out.println("The Linked List is:");  
            System.out.println();
            System.out.println(list);
            System.out.println();
            System.out.println("The Node at position " + index +
                    " is: " + list.get(index));
            System.out.println();                  
            System.out.println("============================================");
            System.out.println();            
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
    }
    
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////  
    /**
     * To Test the set(int index, T value) method of Linked List  
     * 
     */    
    public void testSet()
    {  
        try
        {
            System.out.println("============================================"); 
            System.out.println();
            System.out.println("Testing the set(int index, T value) method\n"
                    + "on the Linked List.......");
            System.out.println();
            System.out.println("---------------------------------------");
            System.out.println();
            int index = userInput.getIndex(this.menuChoice, list.size());
            System.out.println();
            T value = (T) userInput.getValue(this.menuChoice);
            System.out.println();
            System.out.println("Before Setting:");  
            System.out.println();
            System.out.println(list);
            System.out.println();
            System.out.println("After Setting:"); 
            System.out.println();
            list.set(index, value); 
            System.out.println(list);
            System.out.println();             
            System.out.println("============================================");
            System.out.println();
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
    }
    
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////  
    /**
     * To Test the clear() method of Linked List  
     * 
     */    
    public void testClear()
    {        
        try
        {
            System.out.println("============================================");  
            System.out.println();
            System.out.println("Testing the clear() method\n"
                    + "on the Linked List.......");
            System.out.println();
            System.out.println("---------------------------------------");
            System.out.println();
            System.out.println("Before Clearing:");   
            System.out.println();
            System.out.println(list);
            System.out.println();            
            System.out.println("list.size() = " + list.size());
            System.out.println(); 
            System.out.println("After Clearing:");  
            list.clear(); 
            System.out.println(list);
            System.out.println();            
            System.out.println("list.size() = " + list.size());
            System.out.println(); 
            System.out.println("============================================"); 
            System.out.println();
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }        
    }
    
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////  
    /**
     * To Test the indexOf(Object o) method of Linked List  
     * 
     */    
    public void testIndexOf()
    {        
        try
        {
            System.out.println("============================================");
            System.out.println();
            System.out.println("Testing the indexOf(Object o) method\n"
                    + "of the Linked List.......");
            System.out.println();
            System.out.println("---------------------------------------");
            System.out.println();
            T value = (T) userInput.getValue(this.menuChoice);
            System.out.println();
            System.out.println("The Linked List is:");    
            System.out.println();
            System.out.println(list);
            System.out.println();
            System.out.println("The index of " + value + " is: " +
                    list.indexOf(value));
            System.out.println();
            System.out.println("============================================");
            System.out.println();
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
    }
    
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////  
    /**
     * To Test the lastIndexOf(Object o) method of Linked List  
     * 
     */    
    public void testLastIndexOf()
    {        
        try
        {
            System.out.println("============================================"); 
            System.out.println();
            System.out.println("Testing the lastIndexOf(Object o) method\n"
                    + "of the Linked List.......");
            System.out.println();
            System.out.println("---------------------------------------");
            System.out.println();
            T value = (T) userInput.getValue(this.menuChoice);
            System.out.println();
            System.out.println("The Linked List is:");
            System.out.println();            
            System.out.println(list);
            System.out.println();
            System.out.println("The last index of " + value +
                    " is: " + list.lastIndexOf(value));
            System.out.println();
            System.out.println("============================================");
            System.out.println();
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
    }
    
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////  
    /**
     * To Test the subList(int fromIndex, int toIndex) method of Linked List  
     * 
     */    
    public void testSubList()
    {
        try
        {                   
            System.out.println("============================================");
            System.out.println();
            System.out.println("Testing the subList(int fromIndex, int toIndex) method\n"
                    + "of the Linked List.......");
            System.out.println();
            System.out.println("---------------------------------------");
            System.out.println();
            int fromIndex = userInput.getIndex(this.menuChoice, list.size());
            System.out.println();
            int toIndex = userInput.getIndex((this.menuChoice + 1), list.size());
            System.out.println();
            System.out.println("The Linked List is:");   
            System.out.println();
            System.out.println(list);
            System.out.println();
            System.out.println();
            System.out.println("list.size() = " + list.size());
            System.out.println(); 
            System.out.println("Obtaining the subList using:\n list.subList(" +
                    fromIndex + ", " + toIndex + ");");
            System.out.println();
            LinkedListAbstract<T> subList = list.subList(fromIndex, toIndex);
            System.out.println("The Sub List is:");   
            System.out.println();
            System.out.println(subList);
            System.out.println();
            System.out.println();
            System.out.println("subList.size() = " + subList.size());
            System.out.println(); 
            System.out.println("============================================");
            System.out.println();
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
            System.out.println();
        }        
    }
}



