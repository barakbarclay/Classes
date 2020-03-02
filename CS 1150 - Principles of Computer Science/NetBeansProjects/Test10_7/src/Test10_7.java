/*
 * Barak Barclay
 * CS1150.002
 * Test10_7 and Account
 * due 4-11-2017
 * This program creates an array of 10 acct objects with initial balance of 
 * $100. It then asks the user to input an id. If the user inputs an invalid id,
 * it prints an error message. If the user inputs a valid id, it prints a menu,
 * gets the users choice, and enters a loop. The program will then either print
 * the account balance, withdraw money, deposit money, or exit the loop. 
 */
import java.util.Scanner;

public class Test10_7 {

    public static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        int inputtedID = 0;
        int choice = 0;
        int index = 0;
        double withdrawAmt = 0.0;
        double depositAmt = 0.0;
        //print welcome and description
        System.out.printf("Welcome to Barak's ATM Program"
                + "\nThis program acts like an ATM machine.\n");
        //creates an array of 10 objects
        Account[] myAcct = new Account[10];
        for (int i = 0; i < myAcct.length; i++) {
            myAcct[i] = new Account(100);
        }
        //gets id from user
        System.out.printf("Enter an ID:");
        inputtedID = input.nextInt();
        //determines if the user inputted id is valid
        boolean found = false;
        for (int i = 0; (i < myAcct.length && found == false); i++) {
            if (myAcct[i].getId() == inputtedID) {
                found = true;
                index = i;
            }
        }
        //if valid, prints menu and gets choice
        if (found == true) {
            System.out.printf("Main menu\n1: check balance\n2: withdraw\n3: "
                    + "deposit\n4: exit\nEnter a choice:");
            choice = input.nextInt();
            //exits program if choice = 4
            while (choice != 4) {
                //checks acct balance
                if (choice == 1) {
                    System.out.printf("The balance is %.2f\n",
                            myAcct[index].getBalance());
                }
                //withdraws from acct
                if (choice == 2) {
                    System.out.printf("Enter an amount to withdraw:");
                    withdrawAmt = input.nextDouble();
                    myAcct[index].withdraw(withdrawAmt);
                }
                //deposits in acct
                if (choice == 3) {
                    System.out.printf("Enter an amount to deposit:");
                    depositAmt = input.nextDouble();
                    myAcct[index].deposit(depositAmt);
                }
                //re-prints main menu and gets choice again
                System.out.printf("\nMain menu\n1: check balance\n2: "
                        + "withdraw\n3:deposit\n4: exit\nEnter a choice:");
                choice = input.nextInt();
            }//end while
        }//end if
        //error checking id input
        else {
            System.out.printf("\n%d is not a valid ID. Please enter a number "
                    + "between 1000 and 1009\n", inputtedID);

        }
    }
}
