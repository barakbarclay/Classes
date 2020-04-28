/*
 * Barak Barclay
 * CS1150.002
 * Account Class
 */

public class Account {
    
    public int id;
    private double balance;
    private static double annualInterestRate;
    private static int count = 1000;
    //constructors

    public Account(){
	this(35);
    }
    
    Account( double balance ){
        id =  count++;	//post increment, so that the first account number is 1000.
        this.balance = balance;
    }
    
    public void deposit( double deposit ){    //mutator or setter for balance
    //adds to blance
        balance += deposit;
    }
	
	    
    public void withdraw(double amount){
    //take money, go shopping
        balance -= amount;
    }
    
    public double getBalance(){
        return balance;
    }
	
    public int getId(){
        return this.id;
    }
	
    public static double getAnnualInterestRate(){
        return annualInterestRate;
    }
	
    public static void setAnnualInterestRate( double newRate ){
    //the passed in rate MUST use a differnt name than the class-level
    //variable, since you cannot use this. with a static variable.
        annualInterestRate = newRate;
    }

    
     public String toString( ){
    //section 11.6 in Liang
        return  id + "\n"+ balance;
     }
}//end Account
