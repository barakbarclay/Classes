/**
 * @author Dhiraj Gharana
 * CS1450 Section 1,2
 * Homework 2
 * Date: 10/02/2017
 * ................................
 * Class: LinkedListTestingSuite
 */
public class LinkedListTestingSuite 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        System.out.println("============================================");
        System.out.println();
        System.out.println("Welcome to the Linked List Testing Suite:");
        System.out.println();
        System.out.println("============================================\n\n");
        try
        {
            LinkedListTester<String> tester = new LinkedListTester<>("Gharana",
                new BarclayLinkedList<>(),
                new UserInput<>(""));
            try
            {
                do
                {
                    System.out.println();   
                    tester.setMenuChoice();
                    System.out.println();
                    tester.executeMenuChoice();
                }while(tester.getMenuChoice() != 0);
                
            }
            catch(Exception e)
            {
                System.out.println();
            }                    
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }          
    }
    
}