public class StackTestingSuite1
{
    public static void main(String[] args)
    {
        boolean done = false;
        
        //IMPORTANT!
        //For Front of Linked List as Top of Stack, use: "Front",
        //For End of Linked List as Top of Stack, use: "End"
        String frontOrEnd = "Front";
        
        String frontOrEndPrompt = "using " + frontOrEnd + 
                " of Linked List as Top of Stack.";
        
        //IMPORTANT!
        //Replace the name with your Last Name
        String name = "Gharana";
        
        try
        {
            //IMPORTANT!
            //Replace GharanaFrontStack/GharanaEndStack with your implementation!
            //Replace GharanaLinkedList with your implementation!
            //---------------------------------------------------------
            //The only types you can try are:
            //Integer, Double, or String
            //---------------------------------------------------------
            //The arguments to give to the constructor for UserInput are:
            //If Integer: any integer value such as 0
            //If Double: any double value such as 1.0
            //If String: any String such as " "
            StackTester<String> tester = new StackTester<>(
                    new GharanaFrontStack<String>(
                    new GharanaLinkedList<String>()), new UserInput<>(" "));
            
            System.out.println("================================================");
            System.out.println("\t" + name + "'s Stack: " + frontOrEndPrompt);
            System.out.println("================================================");
            while(!done)
            {
                try
                {
                    if(tester == null)
                    {
                        System.out.println("tester is null");
                    }
                    else if(tester.getStack() == null)
                    {
                        System.out.println("tester.getStack() is null");
                    }
                    else
                    {
                        System.out.println(tester.getStack().toString());
                    }                   
                    System.out.println();
                    int choice = tester.getUserInput().getChoice();
                    switch(choice)
                    {
                        case 1:
                            String stringValue = (String)
                                            tester.getUserInput().getValue();
                            tester.getStack().push(stringValue);                            
                            break;
                        case 2:
                            System.out.print("Popping the Top of The Stack: ");
                            System.out.println(tester.getStack().pop());
                            System.out.println();
                            break;
                        default:
                            System.out.print("Peeping at the Top of The Stack: ");
                            System.out.println(tester.getStack().peek());
                            System.out.println();
                            break;
                    }
                    if(frontOrEnd.equals("Front"))
                    {
                        tester.getStack().setTopFront();
                    }
                    else
                    {
                        tester.getStack().setTopEnd();
                    }
                }
                catch(Exception e)
                {
                    System.out.println(e.getMessage());
                    System.out.println();
                }                
            }
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
            System.out.println();
            System.out.println("The program will Terminate............");
            System.out.println();
            System.out.println("Good Bye...............................");
            System.out.println();
        } 
        finally
        {
            System.exit(0);
        }
    }
}