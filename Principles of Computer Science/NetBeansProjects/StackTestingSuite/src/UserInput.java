import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class UserInput<T> 
{
    private final T initialValue;
    private String tType;    
    
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
    }
    
    //if this method returns null,
    //then there is a problem
    public Object getValue()                        
    {
        Object retObject;
        retObject = null;        
        boolean inputAccepted = false;
        while(!inputAccepted)
        {
            try
            {
                Scanner input = new Scanner(System.in);   
                System.out.print("Enter the Value of the Node"
                        + " to Push onto the Stack: "); 
                switch(this.tType)
                {
                    case "Integer":                        
                        retObject = input.nextInt();                        
                        break;
                    case "Double":                         
                        retObject = input.nextDouble();                        
                        break;
                    default:                        
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
        return retObject;
    }
    
    //if this method returns 0,
    //then there is a problem
    public int getChoice()                        
    {
        int retChoice = 0;                
        boolean inputAccepted = false;
        while(!inputAccepted)
        {
            try
            {
                Scanner input = new Scanner(System.in);
                System.out.println("Please choose from the Menu below:");
                System.out.println("0. Quit!");
                System.out.println("1. Do you want to Push A New Value Onto"
                        + " the Top of the Stack?");
                System.out.println("2. Do you want to Pop the"
                        + " Top off the Stack?");
                System.out.println("3. Do you want to Peek at the"
                        + " Top off the Stack?");
                System.out.println();
                System.out.print("Enter the number corresponding to your choice: ");                
                retChoice = input.nextInt();                
                System.out.println();
                if((retChoice == 1)||(retChoice == 2)||(retChoice == 3))
                {
                    inputAccepted = true;
                }
                else if(retChoice == 0)
                {
                    System.out.println();
                    System.out.println("Good Bye ...................");
                    System.out.println();
                    System.exit(0);
                }
                else
                {
                    System.out.println("Sorry.");
                    System.out.println("That was Not a Valid"
                            + " Choice in the Menu.");
                    System.out.println();                    
                }
            }                            
            catch(InputMismatchException e2)
            {
                System.out.println();
                System.out.println(e2.getMessage());
                System.out.println();
                System.out.println(
                        "Error! Please enter an integer number.");
                System.out.println();                
            }
            catch(NoSuchElementException e3)
            {
                System.out.println();
                System.out.println(e3.getMessage());
                System.out.println();
                System.out.println("Error! Please enter an input.");
                System.out.println();
            }
            catch(IllegalStateException e4)
            {
                System.out.println();
                System.out.println(e4.getMessage());
                System.out.println();
                System.out.println("Error! There is a problem with the" +
                        "\n" + "Scanner object used to get user input.");                
                System.out.println();
            }            
        }        
        return retChoice;
    }

    public String getType()
    {
        return tType;
    }   
}