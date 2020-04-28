/*
 * Barak Barclay
 * CS1150.002
 * Ex9_7Account  
 * due 4-14-2017
 * This program creates an account object. The account class creates a default
 * arg constructor, a constructor with a specified id, balance, and annual 
 * interest rate, accessor and mutators methods for id, balance and the annual
 * interest rate, has methods to calculate and return the monthly interest rate
 * and monthly interest, and has methods to withdraw and deposit money into the 
 * account's balance. The test program creates an account with id of 1122, a 
 * balance of $20,000, and an annual interest rate of 4.5%. It then withdraws
 * $2,500 from the acount, deposits $3,000 into the account, and prints the 
 * account balance and the monthly interest of the account.
 */

public class Test {

    public static void main(String[] args) {
        //creates an default account
        Account account1 = new Account();
        //creates an account with $100 balance
        Account account2 = new Account(100);
        //sets annual interestrate to 4.5%
        Account.setAnnualInterestRate(0.045);
        //prints the balance and monthly interest of account1
        System.out.printf("Account %d has a balance of $%.2f.\n",
                account1.getID(), account1.getBalance());
        //prints the balance and monthly interest of account1
        System.out.printf("Account %d has a balance of $%.2f.\n",
                account2.getID(), account2.getBalance());
    }
}
