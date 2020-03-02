
/*
 * Barak Barclay
 * CS1150.002
 * Account Class
 */
public class Account {

    private int id;
    private double balance;
    private double annualInterestRate;

    //no arg constructor that creates a default account
    public Account() {
        id = 0;
        balance = 0;
        annualInterestRate = 0;
    }

    //constructor that creates an account with specified perimeters
    public Account(int id, double balance, double annualInterestRate) {
        this.id = id;
        this.balance = balance;
        this.annualInterestRate = annualInterestRate;
    }

    //getter for id
    public double getID() {
        return id;
    }

    //getter for balance
    public double getBalance() {
        return balance;
    }

    //getter for annual interest rate
    public double getAnnualInterestRate() {
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
    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }

    //method that calculates and returns monthly interest rate
    public double getMonthlyInterestRate() {
        return annualInterestRate / 12;
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
