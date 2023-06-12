import java.util.Date;

public class Account {
    private int id;
    private double balance;
    private static double annualInterestRate;
    
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public static void setAnnualInterestRate(double annualInterestRate) {
        Account.annualInterestRate = annualInterestRate;
    }

    private Date dateCreated;

    public Date getDateCreated() {
        return dateCreated;
    }

    public Account() {
        this.id = 0;
        this.balance = 0;
        Account.annualInterestRate = 0;
        this.dateCreated = new Date();
    }
    
    public Account(int id, double balance) {
        this.id = id;
        this.balance = balance;
        this.dateCreated = new Date();
    }

    public double getMonthlyInterestRate() {
        double monthlyInterestRate = Account.annualInterestRate / 12;
        return monthlyInterestRate;
    }

    public double getMonthlyInterest() {
        double monthlyInterest = this.balance * getMonthlyInterestRate() / 100;
        return monthlyInterest;

    }

    public void withdraw(double amount) {
        if (amount >= 0) {
            this.balance -= amount;
        }
        else {
            this.balance -= Math.abs(amount);
        }
    }

    public void deposit(double amount) {
        if (amount >= 0) {
            this.balance += amount;
        }
        else {
            this.balance += Math.abs(amount);
        }
    }
}

/*

Session 3

Title: The Account Class

4. [10 points] Design a class name Account that contains:

Private int data field named id for the account (default 0)

Private double data field named balance for the account (default 0)

Private double data field named annualInterestRate that stores the current interest rate (in percentage, default 0). Assume all accounts have the same interest rate.

A private Date data field named dateCreated that stores the date when the account was created.

A no-arg constructor that creates a default account

A constructor that creates an account with the specified id and initial balance

The accessor and mutator methods for id, balance, and annualInterestRate

The accessor method for dateCreated

A method named getMonthlyInterestRate() that returns the monthly interest rate

A method named getMonthlyInterest() that returns the monthly interest

A method named withdraw that withdraws a specified amount from the account

A method named deposit that deposits a specified amount to the account

Write a test program that creates an Account object, with withdraw and deposit method to withdraw / deposit the amount, and print the balance, monthly interest and the date when the account was created. Note that the account balance is allowed to be negative.

Test case

public class TestAccount{

public static void main (String[] args) {

Account account = new Account(1122, 20000);

Account.setAnnualInterestRate(4.5);

account.withdraw(2500);

account.deposit(3000);

System.out.println("Balance is " + account.getBalance());

System.out.println("Monthly interest is " +

account.getMonthlyInterest());

}

}

Expected output

Balance is 20500.0

Monthly interest is 76.875

 */