
/*
 * Barak Barclay
 * CS1150.002
 * Account Class
 */
public class Account {

    private static int count = 1000;
    private int id;
    private double balance;
    private static double annualInterestRate;

    //no arg constructor that creates a default account
    public Account() {
        this(35.0);
    }

    //constructor that creates an account by passing the balance
    public Account(double balance) {
        this.id = count;
        this.balance = balance;
        count++;
    }

    //getter for id
    public int getID() {
        return id;
    }

    //getter for balance
    public double getBalance() {
        return balance;
    }

    //getter for annual interest rate
    public static double getAnnualInterestRate() {
        return annualInterestRate;
    }

    //setter for id
    public void setID(int id) {
        this.id = id;
    }

    //setter for balance
    public void setBalance(double balance) {
        this.balance = balance;
    }

    //setter for annual interest rate
    public static void setAnnualInterestRate(double newAnnualInterestRate) {
        annualInterestRate = newAnnualInterestRate;
    }

    //method that calculates and returns monthly interest rate
    public static double getMonthlyInterestRate() {
        return annualInterestRate / 12.0;
    }

    //method that calculates and returns monthly interest
    public double getMonthlyInterest() {
        return getMonthlyInterestRate() * balance;
    }

    //method that calculates a new balance after a withdraw
    public void withdraw(double withdrawAmount) {
        balance -= withdrawAmount;
    }

    //method that calculates a new balance after a deposit
    public void deposit(double depositAmount) {
        balance += depositAmount;
    }
}
