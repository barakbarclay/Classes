/**
 * @author Dhiraj Gharana
 * CS1450 Section 1,2
 * Homework 2
 * Date: 10/02/2017
 * ................................
 * Class: UserInput
 */
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class UserInput<T> 
{
    private final T initialValue;
    private String tType;
    private final String menu;
    private int MIN;
    private int MAX;
    private static final int NUMTRIALS = 1000;
    
    /**
     *
     */
    private final String[] CHOICES = 
    {
        "0.  Quit",
        "1.  Test add(int index, T value) Method:",
        "2.  Test add(T value) Method:",
        "3.  Test remove(int index) Method:",
        "4.  Test remove(Object o) Method:",
        "5.  Test get(int index) Method:",
        "6.  Test set(int index, T value) Method:",
        "7.  Test clear() Method:",
        "8.  Test indexOf(Object o) Method:",
        "9.  Test lastIndexOf(Object o) Method:",
        "10. Test subList(int fromIndex, int toIndex) Method:"
    };
    
    private final String[] POS_PROMPTS = 
    {
        "",
        "in the Linked List at which to Add the Node: ",
        "",
        "in the Linked List from which to Remove the Node: ",
        "",
        "in the Linked List from which to Get the Value of the Node: ",
        "in the Linked List at which to Set a New Value for the Node: ",
        "",
        "",
        "",
        "in the Linked List from where to start the SubList: ",
        "in the Linked List immediately after the last index of the SubList: "
    };
    
    private final String[] VAL_PROMPTS = 
    {
        "",
        "of the Node to Add to the List,",
        "of the Node to Append to the List,",
        "",
        "of the Node to Remove from the List,",
        "",
        "to set this Node to,",
        "",
        "to search in the List for the first Node with,\n"
            + " matching Value and return the index,",
        "to search in the List for the last Node with,\n"
            + " matching Value and return the index.",
        ""
    };
    
    public UserInput(T initialValue)
            throws UnsupportedInputException
    {
        this.initialValue = initialValue;
        if(this.initialValue == null)
        {
            throw new NullPointerException();
        }
        if(this.initialValue instanceof Integer)
        {
            this.tType = "Integer";
        }
        else if(this.initialValue instanceof Double)
        {
            this.tType = "Double";
        }
        else if(this.initialValue instanceof String)
        {
            this.tType = "String";
        }
        else
        {
            throw new UnsupportedInputException(this.initialValue);
        }
        String menuStr =  "";
        for(int i = 0; i < CHOICES.length; i++)
        {
            menuStr += CHOICES[i] + "\n";
        }        
        this.menu = menuStr;
        if(this.CHOICES.length == 0)
        {
            this.MIN = 0;
            this.MAX = 0;
        }
        else
        {
            this.MIN = 0;
            this.MAX = (CHOICES.length - 1);
        }
    }
    
    //If this method returns -1, then a problem occured. 
    public Object getValue(int menuChoice)
            throws ExceededMaxAttemptsAllowedException,
            UnsupportedInputException,
            UnsupportedMenuChoiceException,
            ChoiceOutOfBoundsException
    {
        Object retObject;
        retObject = null;
        if((menuChoice < MIN)||(menuChoice > MAX))
        {
            throw new ChoiceOutOfBoundsException(menuChoice);
        }
        if(this.tType == null)
        {
            throw new NullPointerException();
        }
        if(((!this.tType.equals("Integer"))&&(!this.tType.equals("Double")))&&
                (!this.tType.equals("String")))
        {
            throw new UnsupportedInputException(this.initialValue);
        }
        switch(menuChoice)
        {
            case 0:
            case 3:
            case 5:
            case 7:
            case 10: throw new UnsupportedMenuChoiceException("getValue",
                    menuChoice);
            default: //do nothing
        }
        boolean inputAccepted = false;
        for(int i = 0; i < NUMTRIALS & !inputAccepted; i++)
        {
            try
            {
                Scanner input = new Scanner(System.in);   
                System.out.println("Enter the Value " + VAL_PROMPTS[menuChoice]); 
                System.out.println();
                switch(this.tType)
                {
                    case "Integer":
                        System.out.print("Enter an Integer value: ");
                        retObject = input.nextInt();
                        break;
                    case "Double": 
                        System.out.print("Enter a Double value: ");
                        retObject = input.nextDouble();
                        break;
                    default:
                        System.out.print("Enter a String value: ");
                        retObject = input.next();                        
                }               
                System.out.println();                
                inputAccepted = true;               
            }                            
            catch(InputMismatchException e2)
            {
                switch(this.tType)
                {
                    case "Integer":
                        System.out.println();
                        System.out.println(
                                "Error! Please enter an integer number.");
                        System.out.println();
                        break;
                    case "Double": 
                        System.out.println();
                        System.out.println(
                                "Error! Please enter a double number.");
                        System.out.println();
                        break;
                    default:
                        System.out.println();
                        System.out.println(
                                "Error! Please enter a valid String value.");
                        System.out.println();
                } 
            }
            catch(NoSuchElementException e3)
            {
                System.out.println();
                System.out.println("Error! Please enter an input.");
                System.out.println();
            }
            catch(IllegalStateException e4)
            {
                System.out.println();
                System.out.println("Error! There is a problem with the" +
                        "\n" + "Scanner object used to get user input.");                
                System.out.println();
            }            
        }
        if(!inputAccepted)
        { 
            throw new ExceededMaxAttemptsAllowedException(NUMTRIALS);
        }
        return retObject;
    }
    
    //If this method returns -1, then a problem occured. 
    public int getIndex(int menuChoice, int listSize)
            throws ExceededMaxAttemptsAllowedException,
            UnsupportedInputException,
            UnsupportedMenuChoiceException,
            ChoiceOutOfBoundsException
    {
        int retInt;
        retInt = 0;
        if((menuChoice < MIN)||(menuChoice > (MAX + 1)))
        {
            throw new ChoiceOutOfBoundsException(menuChoice);
        }
        if(this.tType == null)
        {
            throw new NullPointerException();
        }
        if(((!this.tType.equals("Integer"))&&(!this.tType.equals("Double")))&&
                (!this.tType.equals("String")))
        {
            throw new UnsupportedInputException(this.initialValue);
        }
        int max = 0;
        switch(menuChoice)
        {
            case 0:
            case 2:
            case 4:
            case 7:
            case 8:
            case 9: throw new UnsupportedMenuChoiceException("getIndex",
                    menuChoice);
            case 1: 
            case 11: max = listSize;
                break;
            case 3:
            case 5:
            case 6:
            case 10: max = (listSize - 1);
            default: //do nothing
        }
        boolean inputAccepted = false;
        for(int i = 0; i < NUMTRIALS & !inputAccepted; i++)
        {
            try
            {
                Scanner input = new Scanner(System.in);                
                System.out.print("Enter the Index Position " +
                        POS_PROMPTS[menuChoice]);
                retInt = input.nextInt();
                System.out.println();                
                if((retInt < 0)||(retInt > max))
                {
                    throw new ListIndexOutOfBoundsException(retInt, listSize);
                }                
                inputAccepted = true;               
            } 
            catch(ListIndexOutOfBoundsException e1)
            {
                System.out.println(e1.getMessage());
                System.out.println();
            }
            catch(InputMismatchException e2)
            {
                System.out.println();
                System.out.println("Error! Please enter an integer number.");
                System.out.println();
            }
            catch(NoSuchElementException e3)
            {
                System.out.println();
                System.out.println("Error! Please enter an input.");
                System.out.println();
            }
            catch(IllegalStateException e4)
            {
                System.out.println();
                System.out.println("Error! There is a problem with the" +
                        "\n" + "Scanner object used to get user input.");                
                System.out.println();
            }            
        }
        if(!inputAccepted)
        { 
            throw new ExceededMaxAttemptsAllowedException(NUMTRIALS);
        }
        return retInt;
    }    
    
    //If this method returns -1, then a problem occured. 
    public int getChoice()
            throws ExceededMaxAttemptsAllowedException
    {
        boolean inputAccepted = false;
        int retChoice = -1;
        for(int i = 0; i < NUMTRIALS & !inputAccepted; i++)
        {
            try
            {
                Scanner input = new Scanner(System.in);
                System.out.println("Please select from among the"
                        + " choices below:");
                System.out.println();
                System.out.println(this.menu);
                System.out.println();
                System.out.print("Enter a choice between " + MIN +
                        " and " + MAX + ", both inclusive: ");
                retChoice = input.nextInt();
                System.out.println();                
                if((retChoice < this.MIN) || (retChoice > MAX))
                {
                    throw new ChoiceOutOfBoundsException(retChoice);
                }
                else
                {
                    inputAccepted = true;
                }                
            }
            catch(ChoiceOutOfBoundsException e1)
            {
                System.out.println(e1.getMessage());
                System.out.println();
            }                
            catch(InputMismatchException e2)
            {
                System.out.println();
                System.out.println(
                        "Error! Please enter an integer number.");
                System.out.println();
            }
            catch(NoSuchElementException e3)
            {
                System.out.println();
                System.out.println("Error! Please enter an input.");
                System.out.println();
            }
            catch(IllegalStateException e4)
            {
                System.out.println();
                System.out.println("Error! There is a problem with the" +
                        "\n" + "Scanner object used to get user input.");                
                System.out.println();
            }            
        }
        if(!inputAccepted)
        { 
            throw new ExceededMaxAttemptsAllowedException(NUMTRIALS);
        }
        return retChoice;
    }    
}